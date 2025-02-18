#include "logic/game.h"

#include "hal_low/nvic.h"
#include "hal_low/uart.h"
#include "hal_low/random.h"
#include "hal_low/timer.h"
#include "hal_high/input_buf.h"
#include "logic/input.h"
#include "presentation/cell.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/print.h"
#include "presentation/ui.h"
#include "logic/time.h"
#include "logic/bot.h"
#include "helper/math.h"

volatile uint8_t current_turn = 0;

void game_run()
{
    init();

    uint8_t input;
    uint8_t last_update = 0;
    Player winner = None;
    while(true)
    {
        while(!input_getNext(&input_buf, &input))
        {
            // If true, Move was forced due to inactivity
            if(current_turn != last_update)
            {
                last_update = current_turn;
                handleForcedMoveUpdate();
                break;
            }
            ui_updateTimer(REMAINING_TIME);
            __WFI();
        }

        const bool should_redraw_field = handleInput(&input);

        winner = checkForWinner();

        if(winner != None || input == 'q' || current_turn >= (CELLS_PER_COL * CELLS_PER_ROW) / 2)
        {
            timer_stop(TIMER0);
            break;
        }

        if(should_redraw_field)
        {
            redrawField();
        }

        cell_select(selected_cell);
    }


    cursor_moveTo(1, CELLS_PER_COL * cell_height);
    switch(winner)
    {
        case Human:
            println("Congratulations for winning!");
            break;
        case Computer:
            println("Better luck next time!");
            break;
        default:;
    }
    println("Press any key to return to the menu...");
    while(input_isEmpty(&input_buf))
    {
        __WFI();
    }
}

void game_onTimeOut()
{
    last_marked_human = bot_makeHumanTurn(cells);
    last_marked_bot = bot_makeTurn(cells);
    current_turn++;
}

void init()
{
    current_turn = 0;
    input_init(&input_buf);
    rng_init();
    print(HIDE_CURSOR);


    for(int y = 0; y < CELLS_PER_COL; y++)
    {
        for(int x = 0; x < CELLS_PER_ROW; x++)
        {
            cells[y][x] = (Cell){
                .col = x,
                .row = y,
                .marked_by = None,
            };
        }
    }

    selected_cell = &cells[0][0];

    clearConsole();
    time_init();
    field_redraw();
    cell_select(selected_cell);
    ui_displayTimer(REMAINING_TIME);
    ui_displayTurn(current_turn, "Player");
}

bool handleInput(const uint8_t *input)
{
    switch(*input)
    {
        case '\e':
            input_handleEscapeSequence(cells, &selected_cell);
            break;
        case ' ':
            if(selected_cell->marked_by == None)
            {
                selected_cell->marked_by = Human;
                last_marked_bot = bot_makeTurn(cells);
                last_marked_human = selected_cell;
                cell_redraw(last_marked_bot);
                current_turn++;
                ui_updateTurn(current_turn, "Player");
                time_finishRound();
            }
            break;
        case '+':
            cell_increaseSize();
            return true;
        case '-':
            cell_decreaseSize();
            return true;
        default:;
    }
    return false;
}

void redrawField()
{
    clearConsole();
    ui_displayTurn(current_turn, "Player");
    ui_displayTimer(REMAINING_TIME);
    field_redraw();
    cell_redrawAll(cells);
}

void handleForcedMoveUpdate()
{
    cell_select(last_marked_bot);
    cell_select(last_marked_human);
    ui_updateTurn(current_turn, "Player");

    selected_cell = last_marked_human;
}

Player checkForWinner()
{
    if(checkIfPlayerWon(last_marked_human, Human))
    {
        return Human;
    }
    if(checkIfPlayerWon(last_marked_bot, Computer))
    {
        return Computer;
    }
    return None;
}

bool checkIfPlayerWon(const Cell *cell, const Player player)
{
    if(cell == NULL)
    {
        return false;
    }

    // VICTORY ALGORITHM
    // This algorithm starts at the given cell coordinates. It goes in 8 different direction and counts on 4 axes.
    // The return value is true when one axis or more axes has / have reached the win condition (minimum of rows and columns).
    // Every step in one of the directions increments the dedicated axis until a cell is reached that is not marked by our player.
    //  UP      UP     UP          | axis       | direction 1 | direction 2 |
    // LEFT     ^     RIGHT        |------------+-------------+-------------|
    //        \ | /                | vertical   | up          | down        |
    // LEFT <---+---> RIGHT        | horizontal | left        | right       |
    //        / | \                | diagonal_1 | up right    | down left   |
    // DOWN     v     DOWN         | diagonal_2 | up left     | down right  |
    // LEFT    DOWN   RIGHT
    const uint8_t cellsToWin = min(CELLS_PER_COL, CELLS_PER_ROW);
    const uint8_t row = cell->row, col = cell->col;
    const uint8_t maxRow = CELLS_PER_COL - 1, maxCol = CELLS_PER_ROW - 1;
    uint8_t vertical_sum = 1, horizontal_sum = 1, diagonal_1_sum = 1, diagonal_2_sum = 1;
    bool verticalUp = true, verticalDown = true, horizontalLeft = true, horizontalRight = true;
    bool diagonal_1_UpRight = true, diagonal_1_DownLeft = true, diagonal_2_UpLeft = true, diagonal_2_DownRight = true;
    for(uint8_t i = 1; i < cellsToWin; i++)
    {
        // --- VERTICAL ---
        // upwards
        if(verticalUp && row-i >= 0 && cells[row-i][col].marked_by == player)
        {
            vertical_sum++;
        }
        else
        {
            verticalUp = false;
        }
        // downwards
        if(verticalDown && row+i <= maxRow && cells[row+i][col].marked_by == player)
        {
            vertical_sum++;
        }
        else
        {
            verticalDown = false;
        }

        // --- HORIZONTAL ---
        // to the left
        if(horizontalLeft && col-i >= 0 && cells[row][col-i].marked_by == player)
        {
             horizontal_sum++;
        }
        else
        {
            horizontalLeft = false;
        }
        // to the right
        if(horizontalRight && col+i <= maxCol && cells[row][col+i].marked_by == player)
        {
             horizontal_sum++;
        }
        else
        {
            horizontalRight = false;
        }

        // --- 1st DIAGONAL ---
        // upwards to the right
        if(diagonal_1_UpRight && row-i >= 0 && col+i <= maxCol && cells[row - i][col + i].marked_by == player)
        {
            diagonal_1_sum++;
        }
        else
        {
            diagonal_1_UpRight = false;
        }
        // downwards to the left
        if(diagonal_1_DownLeft && row+i <= maxRow && col-i >= 0 && cells[row + i][col - i].marked_by == player)
        {
            diagonal_1_sum++;
        }
        else
        {
            diagonal_1_DownLeft = false;
        }

        // --- 2nd DIAGONAL ---
        // upwards to the left
        if(diagonal_2_UpLeft && row-i >= 0 && col-i >= 0 && cells[row - i][col - i].marked_by == player)
        {
            diagonal_2_sum++;
        }
        else
        {
            diagonal_2_UpLeft = false;
        }
        // downwards to the right
        if(diagonal_2_DownRight && row+i <= maxRow && col+i <= maxCol && cells[row + i][col + i].marked_by == player)
        {
            diagonal_2_sum++;
        }
        else
        {
            diagonal_2_DownRight = false;
        }
    }
    if(vertical_sum >= cellsToWin ||  horizontal_sum >= cellsToWin  || diagonal_1_sum >= cellsToWin  || diagonal_2_sum >= cellsToWin )
    {
        return true;
    }
    else
    {
        return false;
    }
}
