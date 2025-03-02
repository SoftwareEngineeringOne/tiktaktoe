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
#include "presentation/menu.h"
#include "hal_low/nvic.h"
#include "logic/game.h"
#include "presentation/cell.h"
#include "presentation/cursor.h"
#include "config.h"
#include "presentation/print.h"
#include "presentation/style.h"

void menu_showGameOver(GameInfo *game_info) {
    cursor_moveTo(1, CELLS_PER_COL * cell_height);
    switch(game_info->winner)
    {
        case Circle:
            print(BOLD);
            print(FG_GREEN);
            if(game_info->mode == PVE)
            {
                println("Congratulations, you have beaten the Computer!");
            }
            else
            {
                println("Congratulations, circle has won!");
            }
            print(RESET);
            break;
        case Cross:
            print(BOLD);
            print(FG_MAGENTA);
            if(game_info->mode == PVE)
            {
                println("Better luck next time! The Computer has beaten you...");
            }
            else
            {
                println("Congratulation, cross has won!");
            }
            print(RESET);
            break;
        default:;
    }
    print(ITALIC);
    println("Press any key to see the statistics...");
    print(RESET);

    uint8_t input;
    while(!input_getNext(&input_buf, &input))
    {
        __WFI();
    }

    print_clearConsole();

    print("Turns needed:\t");
    print(BOLD);
    println_int(game_info->turn);
    print(RESET);

    print("Total ticks:\t");
    print(BOLD);
    println_int(game_info->total_ticks);
    print(RESET);

    print("Ø ticks / round:\t");
    print(BOLD);
    println_int(game_info->average_ticks);
    print(RESET);

    print(ITALIC);
    println("Press any key to return to the menu...");
    print(RESET);
    while(!input_getNext(&input_buf, &input))
    {
        __WFI();
    }
}
