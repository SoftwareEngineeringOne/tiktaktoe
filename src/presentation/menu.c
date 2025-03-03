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
#include "config.h"
#include "hal/nvic.h"
#include "logic/game.h"
#include "presentation/ascii_art.h"
#include "presentation/cell.h"
#include "presentation/cursor.h"
#include "presentation/print.h"
#include "presentation/style.h"
#include "presentation/ui.h"
#include "util/input_buf.h"


static void printWinnerBanner(const GameState *game_info);

static void printMainMenu();

bool menu_showMainMenu()
{
    print(HIDE_CURSOR);
    printMainMenu();
    uint8_t input;
    while(true)
    {
        while(!input_getNext(&g_input_buf, &input))
        {
            __WFI();
        }

        switch(input)
        {
            case '1':
                game_run(PVP);
                printMainMenu();
                break;
            case '2':
                game_run(PVE);
                printMainMenu();
                break;
            case '3':
                menu_showControls(RETURN_MENU_HINT);
                printMainMenu();
                break;
            case '4':
                menu_showCredits();
                printMainMenu();
                break;
            case '5':
                return false;
            case '6':
                return true;
            case '7':
                __asm volatile("udf #0");
            default:;
        }
    }
}

void menu_showGameOver(const GameState *game_info)
{
    ui_gameOver();

    // avoid artifact when ascii art is disabled
    cursor_moveTo(1, (CELLS_PER_COL * g_cell_size.height + HEADING_LINES) + 1);
    print(ERASE_LINE_FROM_CURSOR);

    cursor_moveTo(1, CELLS_PER_COL * g_cell_size.height + HEADING_LINES);
    printWinnerBanner(game_info);

    menu_anyKeyToContinue("\nPress any key to see the summary...");

    print_clearConsole();
    ui_printHeading();
    printWinnerBanner(game_info);

    println_styled("\nGame Summary:\n", &DEFAULT_BOLD);


    print_styled("\tRounds needed:\t", &DEFAULT_ITALIC);
    println_int(game_info->round);

    print_styled("\tFields marked:\t", &DEFAULT_ITALIC);
    println_int(game_info->fields_marked);

    print_styled("\tTotal ticks:\t", &DEFAULT_ITALIC);
    println_int(game_info->total_ticks);

    print_styled("\tØ ticks/turn:\t", &DEFAULT_ITALIC);
    println_int(game_info->average_ticks);


    print_styled("\n\tTotal ticks by ", &DEFAULT_ITALIC);
    print_styled("cross", &BOLD_CROSS);
    print(":\t");
    println_int(game_info->cross_total_ticks);

    print_styled("\tØ ticks/turn by ", &DEFAULT_ITALIC);
    print_styled("cross", &BOLD_CROSS);
    print(":\t");
    println_int(game_info->cross_average_ticks);

    print_styled("\n\tTotal ticks by ", &DEFAULT_ITALIC);
    print_styled("circle", &BOLD_CIRCLE);
    print(":\t");
    println_int(game_info->circle_total_ticks);

    print_styled("\tØ ticks/turn by ", &DEFAULT_ITALIC);
    print_styled("circle", &BOLD_CIRCLE);
    print(":\t");
    println_int(game_info->circle_average_ticks);
    print(RESET);

    menu_anyKeyToContinue(RETURN_MENU_HINT);
}

void menu_showCredits()
{
    print_clearConsole();
    ui_printHeading();
    println("Credits");

    menu_anyKeyToContinue(RETURN_MENU_HINT);
}

void menu_showControls(const char *continue_hint)
{
    print_clearConsole();
    ui_printHeading();
    println_styled("Controls:\n", &DEFAULT_BOLD);

    print("\t");
    print_styled(ARROW_RIGHT, &BOLD_CROSS);
    println("\t Move selection right");

    print("\t");
    print_styled(ARROW_UP, &BOLD_CROSS);
    println("\t Move selection up");

    print("\t");
    print_styled(ARROW_LEFT, &BOLD_CROSS);
    println("\t Move selection left");

    print("\t");
    print_styled(ARROW_DOWN, &BOLD_CROSS);
    println("\t Move selection down\n");

    print_styled("\t<SPACE>", &BOLD_CROSS);
    println("\t Mark the selected field");

    print_styled("\t<ENTER>", &BOLD_CROSS);
    println("\t Mark the selected field\n");


    print_styled("\tp / P", &BOLD_CROSS);
    println("\t Pause the game");
    println_styled("\t\t You won't be able to see the field while paused!\n", &ITALIC_DIM);
    print_styled("\tq / Q", &BOLD_CROSS);
    println("\t Quit the running game\n");


    print_styled("\t+", &BOLD_CROSS);
    println("\t Increase cell size");

    print_styled("\t-", &BOLD_CROSS);
    println("\t Decrease cell size\n");

    print_styled("\t?", &BOLD_CROSS);
    println("\t Open this overview");

    menu_anyKeyToContinue(continue_hint);
}

void printMainMenu()
{
    print_clearConsole();
    ui_printHeading();
    println_styled("Choose your option:\n", &DEFAULT_BOLD);
    println("\t(1) Player vs Player");
    println("\t(2) Player vs Computer");
    println("\t(3) Controls");
    println("\t(4) Credits");
    println("\t(5) Quit\n");

    println(DIM);
    println("\t(6) Reset\n");
    println("\tResetting the game may help if an unexpected error occurs.");
    println("\tIf the error persists, please contact the developer.\n");
    print(RESET);
    println_styled("Hint: Press the number corresponding to your desired option", &ITALIC_DIM);
}

void printWinnerBanner(const GameState *game_info)
{
    switch(game_info->winner)
    {
        case Circle:
            print_styled(CIRCLE_WINS, &BOLD_CIRCLE);
            break;
        case Cross:
            print_styled(CROSS_WINS, &BOLD_CROSS);
            break;
        case None:
            print_styled(ITS_A_TIE, &BOLD_DIM);
            break;
        default:;
    }
}

void menu_anyKeyToContinue(const char *continue_hint)
{
    println_styled(continue_hint, &ITALIC_DIM);
    uint8_t input;
    while(!input_getNext(&g_input_buf, &input))
    {
        __WFI();
    }
    while(input_getNext(&g_input_buf, &input))
        ;
}
