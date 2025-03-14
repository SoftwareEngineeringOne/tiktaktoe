/**
 * @file game.h
 *
 * @brief Contains the game logic
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef GAME_H
#define GAME_H

#include "presentation/field.h"
#include "util/input_buf.h"

#include <stdint.h>

#define REMAINING_TIME (TICKS_PER_TURN - g_timer.ticks_turn)
#define FIRST_ROUND 1

/**
 * @brief Possible game modes
 *
 * The game can be played in PVE or  PVP mode
 **/
typedef enum
{
    PVE, //!< Player vs Computer
    PVP, //!< Player vs Player
} Mode;

/**
 * @brief Enum describing a player
 */
typedef enum
{
    Circle = 0,
    Cross = 1,
    None = 2,
} Player;

/**
 * @brief One cell on the field
 *
 * Contains coordinates and information by whom it is marked
 */
typedef struct
{
        uint16_t col;
        uint16_t row;
        Player marked_by;
} Cell;

/**
 * @brief The current game state
 *
 * Contains important game information and several metrics
 */
typedef struct
{
        Player winner; //!< None if tie or game not over
        Mode mode;
        volatile uint8_t round;
        volatile uint8_t fields_marked;
        Player current_player;

        // Relevant for summary
        uint32_t total_ticks;
        uint32_t average_ticks;

        uint32_t cross_total_ticks;
        uint32_t cross_average_ticks;

        uint32_t circle_total_ticks;
        uint32_t circle_average_ticks;
} GameState;

/**
 * @brief The current state of the cells
 */
typedef struct
{
        Cell all[CELLS_PER_COL][CELLS_PER_ROW]; //!< All cells of the match
        Cell *selected; //!< Pointer to the currently selected cell
        Cell *last_cross; //!< Pointer to the cell last marked by cross
        Cell *last_circle; //!< Pointer to the last cell marked by circle
} CellState;


/**
 * @brief Start the main game
 *
 * @param[in] mode Which mode the game should be played in.
 */
void game_run(const Mode mode);

/**
 * @brief Automaticly end a turn in case the turn time is over
 */
void game_onTimeOut();

/**
 * @brief Finish the current turn
 */
void game_endTurn();


#endif// GAME_H
