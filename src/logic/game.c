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
    const int8_t cellsToWin = min(CELLS_PER_COL, CELLS_PER_ROW);

    if(checkIfPlayerWon(selected_cell, cellsToWin, Human))
    {
        return Human;
    }
    if(checkIfPlayerWon(last_marked_bot, cellsToWin, Computer))
    {
        return Computer;
    }
    return None;
}

bool checkIfPlayerWon(const Cell *cell, const uint8_t cellsToWin, const Player mark)
{
    if(cell == NULL)
    {
        return false;
    }
    bool vertical_match = true, horizontal_match = true, diagonal_1_match = true, diagonal_2_match = true;
    for(int8_t i = 0; i < cellsToWin; i++)
    {
        if(cells[i][cell->col].marked_by != mark)
        {
            vertical_match = false;
        }
        if(cells[cell->col][i].marked_by != mark)
        {
             horizontal_match = false;
        }
        if(cells[i][i].marked_by != mark)
        {
            diagonal_1_match = false;
        }
        if(cells[i][cellsToWin - 1 - i].marked_by != mark)
        {
            diagonal_2_match = false;
        }
    }
    if(vertical_match ||  horizontal_match || diagonal_1_match || diagonal_2_match)
    {
        return true;
    }
    else
    {
        return false;
    }
}
