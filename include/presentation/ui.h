/**
 * @file ui.h
 *
 * @brief Contains different functions for the presentation of the in-game
 *        user interface (everything besides the actual game field)
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

#define TURN_ROW 1 + HEADING_LINES
#define TIMER_ROW FIELD_HEIGHT + (FIELD_HEIGHT % 2) - 1 + HEADING_LINES

#ifdef ENABLE_UNICODE
#define FULL_PROGRESS_ELEMENT "█"
#define HALF_PROGRESS_ELEMENT "▆"
#define EMPTY_PROGRESS_ELEMENT "▁"

#else
#define FULL_PROGRESS_ELEMENT "-"
#define HALF_PROGRESS_ELEMENT "_"
#define EMPTY_PROGRESS_ELEMENT ""

#endif


/**
 * @brief Writes the timer text to the screen
 * @param [in] remaining_time
 */
void ui_displayTimer(uint16_t remaining_time, uint16_t total_time);

/**
 * @brief Updates the time on the screen
 * @param [in] remaining_time
 */
void ui_updateTimer(uint16_t remaining_time, uint16_t total_time);

/**
 * @brief Writes the turn text to the screen
 * @param [in] current_turn
 * @param [in] playerName
 */
void ui_displayTurn(uint8_t current_turn, Player player);

/**
 * @brief Updates the turn number on the screen
 * @param [in] current_turn
 * @param [in] playerName
 */
void ui_updateTurn(uint8_t current_turn, Player player);

void ui_printStartingPlayer(Player starting_player, Mode mode);

void ui_printHeading();

void ui_gameOver();

#endif// UI_H
