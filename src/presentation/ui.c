/**
 * @file ui.c
 *
 * @brief Implements functions for the in-game user interface.
 *
 * @see ui.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "presentation/ui.h"

#include "hal/uart.h"
#include "logic/time.h"
#include "presentation/ascii_art.h"
#include "presentation/cursor.h"
#include "presentation/menu.h"
#include "presentation/print.h"
#include "presentation/style.h"

void ui_displayTimer(const uint16_t remaining_time, const uint16_t total_time)
{
    cursor_moveTo(2, TIMER_ROW);
    print("");
    ui_updateTimer(remaining_time, total_time);

    cursor_moveTo(2, TIMER_ROW + 2);
    print_styled("Hint: Press \"?\" to see all controls!", &ITALIC_DIM);
}

void ui_updateTimer(const uint16_t remaining_time, const uint16_t total_time)
{
    cursor_moveTo(2, TIMER_ROW);
    print(ERASE_LINE_FROM_CURSOR);
    print(BOLD);

    #ifndef DISABLE_TIMER
    static Style style;
    const uint8_t percent = ((float)remaining_time / (float)total_time) * 100;// NOLINT
    if(!g_timer.is_running)
    {
        style = (Style){.font_style = DIM};
    }
    else if(percent > 66)
    {
        style = (Style){.fg_color = FG_GREEN};
    }
    else if(percent > 33)
    {
        style = (Style){.fg_color = FG_YELLOW};
    }
    else
    {
        style = (Style){.fg_color = FG_RED};
    }

    for(uint16_t i = 0; i < total_time; i++)
    {
        if(i < remaining_time)
        {
            print_styled(FULL_PROGRESS_ELEMENT, &style);
        }
        else if(i == remaining_time)
        {
            print_styled(HALF_PROGRESS_ELEMENT, &style);
        }
        else
        {
            print_styled(EMPTY_PROGRESS_ELEMENT, &style);
        }
    }

    cursor_moveTo(2, TIMER_ROW + 1);
    if(!g_timer.is_running)
    {
        println_styled("Paused...", &ITALIC_DIM);
        return;
    }
    print(ERASE_LINE_FROM_CURSOR);
    #else
    print_styled("Timer disabled", &ITALIC_DIM);
    #endif
    uart_writeByte('\n');
}

void ui_displayTurn(const uint8_t current_turn, const Player player)
{
    cursor_moveTo(1, TURN_ROW);

    print_styled("Round", &DEFAULT_BOLD);
    cursor_moveTo(1 + 6 + 3, TURN_ROW);
    print_styled(" Waiting for ", &DEFAULT_ITALIC);
    ui_updateTurn(current_turn, player);
}

void ui_updateTurn(const uint8_t current_turn, const Player player)
{
    cursor_moveTo(1 + 6, TURN_ROW);
    print_int(current_turn);

    cursor_moveTo(1 + 6 + 3 + 13, TURN_ROW);
    if(player == Circle)
    {
        print(FG_MAGENTA);
        print_styled("Circle... ", &BOLD_CIRCLE);
    }
    else if(player == Cross)
    {
        print(FG_GREEN);
        print_styled("Cross...", &BOLD_CROSS);
    }
}

void ui_gameOver()
{
    cursor_moveTo(1, TURN_ROW);
    print(ERASE_LINE_FROM_CURSOR);
    print_styled("Game Over!", &DEFAULT_BOLD);

    cursor_moveTo(0, TIMER_ROW);
    print(ERASE_LINE_FROM_CURSOR);
}

void ui_printHeading()
{
    cursor_moveTo(0, 0);
    print_styled(HEADING, &HEADING_STYLE);
}

void ui_printStartingPlayer(Player starting_player, Mode mode)
{
    print_clearConsole();
    ui_printHeading();
    switch(starting_player)
    {
        case Cross:
            if(mode == PVE)
            {
                print_styled(PLAYER_STARTS, &DEFAULT_CROSS);
            }
            else
            {
                print_styled(CROSS_STARTS, &DEFAULT_CROSS);
            }
            break;
        case Circle:
            if(mode == PVE)
            {
                print_styled(COMPUTER_STARTS, &DEFAULT_CIRCLE);
            }
            else
            {
                print_styled(CIRCLE_STARTS, &DEFAULT_CIRCLE);
            }
            break;
        case None:
            print_styled(
                "Something went very wrong...",
                &(Style){.font_style = BOLD, .fg_color = FG_RED});
    }
    menu_anyKeyToContinue("Press any key to start the game...");
}
