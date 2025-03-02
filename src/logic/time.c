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
 *
 */
#include "logic/time.h"

#include "hal_low/timer.h"
#include "logic/game.h"
#include "presentation/cursor.h"
#include "presentation/print.h"
#include <stdint.h>

volatile uint32_t time_sumTicks = 0;
volatile uint32_t time_roundTicks = 0;

void time_init()
{
    timer_init_detailed(TIMER0, TICK_SPEED, TIMER_MODE_TIMER, TIMER_BIT_MODE_32);
    timer_captureCompareSet(TIMER0, CC0, 2000, true);
    timer_start(TIMER0);
}

void time_onInterrupt()
{
    time_sumTicks++;
    time_roundTicks = (time_roundTicks + 1) % TICKS_PER_ROUND;
    if(time_roundTicks == TICKS_PER_ROUND - 1)
    {
        game_onTimeOut();
    }
}

void time_finishRound()
{
    time_roundTicks = 0;
}
