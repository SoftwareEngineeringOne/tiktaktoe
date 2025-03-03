/**
 * @file
 *
 * @author
 *
 * @date
 *
 * @brief
 *
 * @see
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

typedef enum
{
    PVE,
    PVP,
} Mode;

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

typedef struct
{
        Player winner;
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

typedef struct
{
        Cell all[CELLS_PER_COL][CELLS_PER_ROW];
        Cell *selected;
        Cell *last_cross;
        Cell *last_circle;
} CellState;


/**
 * @brief Start the main game
 */
void game_run(const Mode mode);

/**
 * @brief Automatic turn in case the round time is over
 */
void game_onTimeOut();

void game_endTurn();


#endif// GAME_H
