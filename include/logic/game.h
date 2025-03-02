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

#include "hal_high/input_buf.h"
#include "presentation/field.h"

#include <stdint.h>

#define REMAINING_TIME (TICKS_PER_ROUND - time_roundTicks)
#define FIRST_TURN 1

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
    uint8_t turn;
    uint32_t total_ticks;
    uint32_t average_ticks;
} GameInfo;


/**
 * @brief Start the main game
 */
void game_run(const Mode mode);

/**
 * @brief Automatic turn in case the round time is over
 */
void game_onTimeOut();


#endif// GAME_H
