#include "logic/game.h"

#include "hal_low/nvic.h"
#include "hal_low/uart.h"
#include "hal_low/random.h"
#include "hal_high/input_buf.h"
#include "logic/input.h"
#include "presentation/cell.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/print.h"
#include "presentation/ui.h"
#include "logic/time.h"
#include "logic/bot.h"

volatile uint8_t current_turn = 0;

void game_run()
{
    input_init(&input_buf);
    rng_init();
    print(HIDE_CURSOR);

    static uint8_t input;

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
    uint8_t last_update = 0;
    while(true)
    {
        while(!input_getNext(&input_buf, &input))
        {
            if(current_turn != last_update) {
                last_update = current_turn;
                cell_select(bot_cell);
                cell_select(selected_cell);
                ui_updateTurn(current_turn, "Player");
            }
            ui_updateTimer(REMAINING_TIME);
            __WFI();
        }

        bool should_redraw_field = false;
        bool should_quit = false;
        switch(input)
        {
            case '\e':
                input_handleEscapeSequence(cells, &selected_cell);
                break;
            case ' ':
                if(selected_cell->marked_by == None)
                {
                    selected_cell->marked_by = Human;
                    cell_redraw(bot_makeTurn(cells));
                    current_turn++;
                    ui_updateTurn(current_turn, "Player");
                    time_finishRound();
                    game_checkGameState();
                }
                break;
            case '+':
                cell_increaseSize();
                should_redraw_field = true;
                break;
            case '-':
                cell_decreaseSize();
                should_redraw_field = true;
                break;
            case 'q':
                should_quit = true;
                break;
            default:;
        }

        if(should_quit || current_turn >= (CELLS_PER_COL * CELLS_PER_ROW) / 2)
        {
            clearConsole();
            break;
        }

        if(should_redraw_field)
        {
            clearConsole();
            ui_displayTurn(current_turn, "Player");
            ui_displayTimer(REMAINING_TIME);
            field_redraw();
            cell_redrawAll(cells);
        }

        cell_select(selected_cell);
    }
}

void game_onTimeOut()
{
    selected_cell = bot_makeHumanTurn(cells);
    bot_cell = bot_makeTurn(cells);
    current_turn++;
}

void game_checkGameState()
{
    const int8_t cellsToWin = min(CELLS_PER_COL, CELLS_PER_ROW);
    const int8_t playerX = selected_cell->col;
    const int8_t playerY = selected_cell->row;
    const int8_t botX = selected_cell->col;
    const int8_t botY = selected_cell->row;

    if(game_playerHasWon(playerX, playerY, cellsToWin, Human)) {
        print("Human has won!");
    }
    if(game_playerHasWon(playerX, playerY, cellsToWin, Computer)) {
        print("Computer has won!");
    }
}

uint8_t game_playerHasWon(uint8_t x, uint8_t y, uint8_t cellsToWin, Mark mark) {
    uint8_t vert = 1, hori = 1, diag1 = 1, diag2 = 1;
    for(int8_t i = 0; i < cellsToWin; i++) {
        if(!(cells[i][x].marked_by==mark)) {
            vert = 0;
        }
        if(!(cells[y][i].marked_by==mark)) {
            hori = 0;
        }
        if(!(cells[i][i].marked_by==mark)) {
            diag1 = 0;
        }
        if(!(cells[i][cellsToWin-1-i].marked_by==mark)) {
            diag2 = 0;
        }
    }
    if(vert || hori || diag1 || diag2) {
        return 1;
    } else {
        return 0;
    }
}
