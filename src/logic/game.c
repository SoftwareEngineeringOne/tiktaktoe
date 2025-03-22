/**
 * @file game.c
 *
 * @brief Implements the core game logic for Tic-Tac-Toe
 *
 * @see game.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "logic/game.h"

#include "config.h"
#include "hal/nvic.h"
#include "hal/random.h"
#include "hal/timer.h"
#include "logic/bot.h"
#include "logic/input.h"
#include "logic/time.h"
#include "logic/winning.h"
#include "presentation/cell.h"
#include "presentation/field.h"
#include "presentation/menu.h"
#include "presentation/print.h"
#include "presentation/style.h"
#include "presentation/ui.h"
#include "util/input_buf.h"
#include "util/math.h"
#include <stdint.h>


/// @brief Force an update of the UI
volatile bool force_ui_update = false;
/// @brief GameState of the current game
static GameState game_state;
/// @brief CellState of the current game
static CellState cell_state;

/**
 * @brief Initializes relevant things at the game start
 *
 * @details
 * Sets up the game/cell state, initializes the input buffer, and prepares the UI.
 *
 * @param[in] mode The game mode (PVE or PVP).
 */
static void init(Mode mode);

/**
 * @brief Handles the presentation update, when a move is forced due to timeout
 */
static void handleForcedMoveUpdate();

/**
 * @brief Refreshes the whole UI
 *
 * @details
 * Clears the console and redraws the game field and UI elements.
 */
static void redrawField();

/**
 * @brief Calculates game summary statistics
 *
 * @details
 * Computes total and average ticks for each player and the game overall.
 *
 * @note Statistics are written to the game_state struct.
 * @see game_state
 */
static void calculateSummary();

/**
 * @brief Randomly determines the starting player
 */
static Player startingPlayer();


void game_run(const Mode mode)
{
    init(mode);

    Cell *winner_cells[max(CELLS_PER_COL, CELLS_PER_ROW)] = {0};// NOLINT
    uint8_t input;

    if(game_state.mode == PVE && game_state.current_player == Circle)
    {
        cell_state.last_circle = bot_markRandomCell(cell_state.all, Circle);
        game_state.current_player = Cross;
        game_state.fields_marked++;

        cell_select(cell_state.last_circle);
        cell_select(&cell_state.all[0][0]);
        ui_updateTurn(game_state.round, game_state.current_player);
    }

    while(true)
    {
        while(!input_getNext(&g_input_buf, &input))
        {
            // If true, Move was forced due to inactivity
            if(force_ui_update)
            {
                handleForcedMoveUpdate();
                force_ui_update = false;
                input = 0;
                break;
            }
            ui_updateTimer(REMAINING_TIME, TICKS_PER_TURN);
            __WFI();
        }

        const bool should_redraw_field = input_handleByte(&input, &game_state, &cell_state);

        game_state.winner = winning_checkForWinner(&cell_state, winner_cells);

        if(g_timer.is_running)
        {
            cell_select(cell_state.selected);
        }

        if(game_state.winner != None || input == 'q' || input == 'Q'
           || game_state.fields_marked >= CELLS_PER_COL * CELLS_PER_ROW)
        {
            timer_stop(TIMER0);
            break;
        }

        if(should_redraw_field)
        {
            redrawField();
        }
    }

    cell_redrawAll(cell_state.all, "\e[0;2m");
    for(uint8_t i = 0; i < (max(CELLS_PER_COL, CELLS_PER_ROW)) && winner_cells[i] != NULL;
        i++)// NOLINT
    {
        cell_redraw_withModifier(winner_cells[i], BOLD);
    }

    calculateSummary();
    menu_showGameOver(&game_state);
}

void game_onTimeOut()
{
    force_ui_update = true;
    if(game_state.mode == PVE)
    {
        cell_state.last_cross = bot_markRandomCell(cell_state.all, Cross);
        cell_state.last_circle = bot_markRandomCell(cell_state.all, Circle);
    }
    else if(game_state.current_player == Cross)
    {
        cell_state.last_cross = bot_markRandomCell(cell_state.all, Cross);
    }
    else if(game_state.current_player == Circle)
    {
        cell_state.last_circle = bot_markRandomCell(cell_state.all, Circle);
    }

    game_endTurn();
}

void game_endTurn()
{
    if(game_state.mode == PVE)
    {
        time_finishTurn(&game_state);
        game_state.round++;
        game_state.fields_marked += 2;
    }
    else
    {
        time_finishTurn(&game_state);
        if(game_state.current_player == Cross)
        {
            game_state.current_player = Circle;
            cell_state.selected =
                cell_state.last_circle != NULL ? cell_state.last_circle : cell_state.selected;
            game_state.fields_marked++;
        }
        else
        {
            game_state.current_player = Cross;
            cell_state.selected =
                cell_state.last_cross != NULL ? cell_state.last_cross : cell_state.selected;
            game_state.round++;
            game_state.fields_marked++;
        }
    }
}

static void init(const Mode mode)
{
    // When starting a second game in a session an artifact bug occurred,
    // reelecting here fixes this.
    if(cell_state.selected != NULL)
    {
        cell_state.selected->marked_by = None;
        cell_select(cell_state.selected);
    }

    input_init(&g_input_buf);
    rng_init();

    game_state = (GameState){
        .winner = None,
        .mode = mode,
        .round = FIRST_ROUND,
        .current_player = startingPlayer(),
    };


    cell_state = (CellState){};

    print(HIDE_CURSOR);


    for(int y = 0; y < CELLS_PER_COL; y++)
    {
        for(int x = 0; x < CELLS_PER_ROW; x++)
        {
            cell_state.all[y][x] = (Cell){
                .col = x,
                .row = y,
                .marked_by = None,
            };
        }
    }

    cell_state.selected = &cell_state.all[0][0];

    ui_printStartingPlayer(game_state.current_player, mode);

    print_clearConsole();
    time_init();
    redrawField();
}


static void calculateSummary()
{
    game_state.total_ticks = g_timer.ticks_total;

    if(game_state.mode == PVE)
    {
        game_state.average_ticks = g_timer.ticks_total / 2 / game_state.round;
    }
    else
    {
        game_state.average_ticks = g_timer.ticks_total / game_state.round;
    }

    // the loser made one turn less
    uint8_t cross_rounds = game_state.round;
    uint8_t circle_rounds = game_state.round;
    if(game_state.winner == Cross)
    {
        circle_rounds--;
    }
    else if(game_state.winner == Circle)
    {
        cross_rounds--;
    }

    game_state.cross_average_ticks = game_state.cross_total_ticks / cross_rounds;
    game_state.circle_average_ticks = game_state.circle_total_ticks / circle_rounds;
}

static void redrawField()
{
    print_clearConsole();
    ui_printHeading();
    ui_displayTurn(game_state.round, game_state.current_player);
    ui_displayTimer(REMAINING_TIME, TICKS_PER_TURN);
    field_redraw();
    cell_redrawAll(cell_state.all, "");
    cell_select(cell_state.selected);
}

static void handleForcedMoveUpdate()
{
    cell_select(cell_state.last_cross);
    cell_select(cell_state.last_circle);
    ui_updateTurn(game_state.round, game_state.current_player);

    if(game_state.mode == PVE)
    {
        cell_state.selected = cell_state.last_circle;
    }
    else
    {
        // inverted to select from previous turn
        cell_state.selected =
            game_state.current_player == Circle ? cell_state.last_circle : cell_state.last_cross;
        if(cell_state.selected == NULL)
        {
            cell_state.selected = &cell_state.all[0][0];
        }
    }
}

static Player startingPlayer()
{
    uint8_t rand = rng_getRandomValue_waiting();

    // 0 is Cross, 1 is Circle - mod 2 returns 0 or 1
    return (Player)(rand % 2);
}
