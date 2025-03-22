/**
 * @file ui.h
 *
 * @brief Contains different functions for the presentation of the in-game
 *        user interface (everything besides the actual game field).
 *
 * @details
 * This file provides functions to display and update the timer, turn text,
 * and other UI elements for the game. It also includes macros for rendering
 * progress elements and constants for positioning UI elements.
 *
 * @ingroup Presentation
 *
 * @see ui.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef UI_H
#define UI_H

#include "logic/game.h"
#include "presentation/ascii_art.h"
#include "presentation/cell.h"
#include <stdint.h>

#define TURN_ROW 1 + HEADING_LINES///< Row position for displaying the turn text.
/**
 * @def TIMER_ROW
 *
 * @brief Row position for displaying the timer.
 *
 * @details
 * The timer row position is calculated based on the number of cells per column.
 * If the number of cells per column is 2, the calculation has to be adjusted
 */
#define TIMER_ROW \
    (CELLS_PER_COL == 2 ? FIELD_HEIGHT + (FIELD_HEIGHT % 2) + 1 + HEADING_LINES \
                        : FIELD_HEIGHT + (FIELD_HEIGHT % 2) - 1 + HEADING_LINES)

#ifdef ENABLE_UNICODE
#define FULL_PROGRESS_ELEMENT "█" ///< Full progress bar element
#define HALF_PROGRESS_ELEMENT "▆" ///< Half progress bar element
#define EMPTY_PROGRESS_ELEMENT "▁"///< Empty progress bar element
#else
#define FULL_PROGRESS_ELEMENT "-"///< Full progress bar element
#define HALF_PROGRESS_ELEMENT "_"///< Half progress bar element
#define EMPTY_PROGRESS_ELEMENT ""///< Empty progress bar element
#endif

/**
 * @brief Writes the timer text to the screen.
 *
 * @param[in] remaining_time The remaining time in seconds.
 * @param[in] total_time The total time in seconds.
 */
void ui_displayTimer(uint16_t remaining_time, uint16_t total_time);

/**
 * @brief Updates the time on the screen.
 *
 * @param[in] remaining_time The remaining time in seconds.
 * @param[in] total_time The total time in seconds.
 */
void ui_updateTimer(uint16_t remaining_time, uint16_t total_time);

/**
 * @brief Writes the turn text to the screen.
 *
 * @param[in] current_turn The current turn number.
 * @param[in] player The player whose turn it is (Circle or Cross).
 */
void ui_displayTurn(uint8_t current_turn, Player player);

/**
 * @brief Updates the turn number on the screen.
 *
 * @param[in] current_turn The current turn number.
 * @param[in] player The player whose turn it is (Circle or Cross).
 */
void ui_updateTurn(uint8_t current_turn, Player player);

/**
 * @brief Displays the starting player and mode.
 *
 * @param[in] starting_player The player who starts the game.
 * @param[in] mode The game mode (e.g., PVE or PVP).
 */
void ui_printStartingPlayer(Player starting_player, Mode mode);

/**
 * @brief Prints the game heading to the screen.
 */
void ui_printHeading();

/**
 * @brief Displays the "Game Over" message on the screen.
 */
void ui_gameOver();

#endif// UI_H
