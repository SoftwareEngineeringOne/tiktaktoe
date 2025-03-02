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

#include <stdint.h>
#define TICKS_PER_ROUND 20
#define TICK_SPEED 10

extern volatile uint32_t time_sumTicks;
extern volatile uint32_t time_roundTicks;

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
void time_finishRound();

#endif// TIME_H
