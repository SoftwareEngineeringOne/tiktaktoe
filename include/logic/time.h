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
#ifndef TIME_H
#define TIME_H

#include "logic/game.h"
#include <stdint.h>

typedef struct
{
        bool is_running;
        volatile uint32_t ticks_total;
        volatile uint32_t ticks_turn;
} GameTimer;

extern GameTimer g_timer;

/**
 * @brief Initializes the timer
 */
void time_init();

/**
 * @brief Increments the ticks and can finish the round
 */
void time_onInterrupt();

/**
 * @brief Resets the ticks
 */
void time_finishTurn(GameState *game_state);

void time_pause();

void time_resume();

#endif// TIME_H
