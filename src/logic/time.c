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

#include "hal/timer.h"
#include "logic/game.h"
#include <stdint.h>

GameTimer g_timer = (GameTimer){
    .ticks_total = 0,
    .ticks_turn = 0,
    .is_running = true,
};

void time_init()
{
    timer_init_detailed(TIMER0, TICK_SPEED, TIMER_MODE_TIMER, TIMER_BIT_MODE_32);
    timer_captureCompareSet(TIMER0, CC0, 2000, true);
    timer_start(TIMER0);
}

void time_onInterrupt()
{
    g_timer.ticks_total++;
    g_timer.ticks_turn = (g_timer.ticks_turn + 1) % TICKS_PER_TURN;
    if(g_timer.ticks_turn == TICKS_PER_TURN - 1)
    {
        game_onTimeOut();
    }
}

void time_finishTurn(GameState *game_state)
{
    const uint32_t ticks = g_timer.ticks_turn;

    if(game_state->current_player == Cross)
    {
        game_state->cross_total_ticks += ticks;
    }
    else
    {
        game_state->circle_total_ticks += ticks;
    }

    g_timer.ticks_turn = 0;
}

void time_pause()
{
    timer_stop(TIMER0);
    g_timer.is_running = false;
}

void time_resume()
{
    timer_start(TIMER0);
    g_timer.is_running = true;
}
