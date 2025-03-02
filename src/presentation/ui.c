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
#include "presentation/ui.h"

#include "hal_low/uart.h"
#include "presentation/cursor.h"
#include "presentation/print.h"
#include "presentation/style.h"
#include "util/conversion.h"

#include <stddef.h>


void ui_displayTimer(uint16_t remaining_time, uint16_t total_time)
{
    cursor_moveTo(1, TIMER_ROW);
    print("Remaining: ");
    ui_updateTimer(remaining_time, total_time);
}

void ui_updateTimer(uint16_t remaining_time, uint16_t total_time)
{
    cursor_moveTo(1 + 11, TIMER_ROW);
    print(ERASE_LINE_FROM_CURSOR);
    print(BOLD);
    uint8_t percent = ((float)remaining_time / (float)total_time) * 100;
    if(percent > 66)
    {
        print(FG_GREEN);
    }
    else if(percent > 33)
    {
        print(FG_YELLOW);
    }
    else
    {
        print(FG_RED);
    }

    for(uint16_t i = 0; i < total_time; i++)
    {
        if(i < remaining_time)
        {
            print("█");
        }
        else if(i == remaining_time)
        {
            print("▆");
        }
        else
        {
            print("▁");
        }
    }
    uart_writeByte('\n');
    print(RESET);
}
void ui_displayTurn(uint8_t current_turn, Player player)
{
    cursor_moveTo(1, TURN_ROW);

    print(BOLD);
    print("Turn");
    print(RESET);
    cursor_moveTo(1 + 5 + 3, TURN_ROW);
    print(ITALIC);
    print(" Waiting for ");
    print(RESET);
    ui_updateTurn(current_turn, player);
}

void ui_updateTurn(uint8_t current_turn, Player player)
{
    cursor_moveTo(1 + 5, TURN_ROW);
    print(BOLD);
    print_int(current_turn);

    cursor_moveTo(1 + 5 + 3 + 13, TURN_ROW);
    if(player == Circle)
    {
        print(FG_GREEN);
        print("Cross... ");
    }
    else if(player == Cross)
    {
        print(FG_MAGENTA);
        print("Circle...");
    }
    print(RESET);
}
