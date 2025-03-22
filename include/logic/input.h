/**
 * @file input.h
 *
 * @brief Contains the input handling of the game.
 *
 * @details
 * This file provides the interface for handling user input during the game,
 * including processing key presses and updating game and cell states.
 *
 * @ingroup Logic
 *
 * @see input.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INPUT_H
#define INPUT_H

#include "def.h"
#include "logic/game.h"

/**
 * @brief Handles an input byte and updates game and cell states.
 *
 * @details
 * Processes the input byte to determine the appropriate action, such as
 * marking a cell, navigating the board, or pausing the game. Updates the
 * game state and cell state accordingly.
 *
 * @param[in] byte The input byte to process.
 * @param[inout] game_state Pointer to the current game state.
 * @param[inout] cell_state Pointer to the current cell state.
 *
 * @return True if a field redraw is needed, false otherwise.
 */
bool input_handleByte(const uint8_t *byte, GameState *game_state, CellState *cell_state);

#endif// INPUT_H
