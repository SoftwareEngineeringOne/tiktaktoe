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
#ifndef UI_H
#define UI_H

#include "logic/game.h"
#include "presentation/field.h"
#include <stdint.h>

#define TURN_ROW 1
#define TIMER_ROW (CELLS_PER_COL * cell_height) - 1

extern uint8_t cell_height;

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

#endif// UI_H
