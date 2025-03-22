/**
 * @file menu.h
 *
 * @brief Contains functions for presentation of the menu.
 *
 * @details
 * This file contains the declarations for menu-related functions and macros
 * used in the presentation layer of the application.
 *
 * @ingroup Presentation
 *
 * @see menu.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef MENU_H
#define MENU_H

#include "logic/game.h"

/**
 * @def RETURN_MENU_HINT
 * @brief Hint message displayed to return to the menu.
 */
#define RETURN_MENU_HINT "\nPress any key to return to the menu..."

#ifdef ENABLE_UNICODE

#define ARROW_LEFT "←"
#define ARROW_UP "↑"
#define ARROW_RIGHT "→"
#define ARROW_DOWN "↓"

#else

#define ARROW_LEFT "<LEFT>"
#define ARROW_UP "<UP>"
#define ARROW_RIGHT "<RIGHT>"
#define ARROW_DOWN "<DOWN>"

#endif

/**
 * @brief Displays the main menu and handles user input.
 *
 * @return `true` if the game should reset, `false` if the game should quit.
 */
bool menu_showMainMenu();

/**
 * @brief Displays the controls menu.
 *
 * @param[in] continue_hint Hint message displayed to return to the menu.
 */
void menu_showControls(const char *continue_hint);

/**
 * @brief Displays the credits screen.
 */
void menu_showCredits();

/**
 * @brief Displays the game over screen and game summary.
 *
 * @param[in] game_info Pointer to the game state containing game statistics.
 */
void menu_showGameOver(const GameState *game_info);

/**
 * @brief Waits for any key press to continue.
 *
 * @param[in] continue_hint Hint message displayed to prompt the user.
 */
void menu_anyKeyToContinue(const char *continue_hint);

#endif// MENU_H
