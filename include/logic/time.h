/**
 * @file time.h
 *
 * @brief Contains time functions needed for the game
 *
 * @details
 * This file contains the declarations for managing the game timer, including
 * initialization, pausing, resuming, and handling turn-based timing.
 *
 * @ingroup Logic
 *
 * @see time.c
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
 *
 * @details
 * This struct tracks whether the timer is running and the number of ticks
 * elapsed in total and during the current turn.
 */
typedef struct
{
        bool is_running;              ///< Indicates if the timer is currently running
        volatile uint32_t ticks_total;///< Total ticks since the game started
        volatile uint32_t ticks_turn; ///< Ticks elapsed during the current turn
} GameTimer;

/**
 * @brief Global game timer instance
 *
 * @details
 * This global variable tracks the timer state and tick counts for the game.
 */
extern GameTimer g_timer;

/**
 * @brief Initializes the timer
 *
 * @details
 * Sets up the hardware timer with the appropriate configuration for the game.
 */
void time_init();

/**
 * @brief Increments the ticks and can finish the round
 *
 * @details
 * This function is called on a timer interrupt. It increments the total and
 * turn-specific tick counters and triggers a timeout if the turn duration is
 * exceeded.
 */
void time_onInterrupt();

/**
 * @brief Resets the ticks
 *
 * @details
 * Resets the turn-specific tick counter and updates the game state with the
 * elapsed time for the current player.
 *
 * @param[inout] game_state Current state of the game
 */
void time_finishTurn(GameState *game_state);

/**
 * @brief Pause the timer
 *
 * @details
 * Stops the hardware timer and marks the timer as not running.
 */
void time_pause();

/**
 * @brief Resume the timer when paused
 *
 * @details
 * Restarts the hardware timer and marks the timer as running.
 */
void time_resume();

#endif// TIME_H
