/**
 * @file time.h
 *
 * @brief Contains time functions needed for the game
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

/**
 * @brief Time information of the current game
 */
typedef struct
{
        bool is_running;
        volatile uint32_t ticks_total;
        volatile uint32_t ticks_turn;
} GameTimer;

extern GameTimer g_timer; //!< Global instance of the GameTimer

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
 *
 * @param[inout] game_state Current state of the game
 */
void time_finishTurn(GameState *game_state);

/**
 * @brief Pause the timer
 */
void time_pause();

/**
 * @brief Resume the timer when paused
 */
void time_resume();

#endif// TIME_H
