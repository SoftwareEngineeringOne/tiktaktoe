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
#ifndef INPUT_H
#define INPUT_H

#include "def.h"
#include "logic/game.h"

bool input_handleByte(uint8_t *byte, GameState *game_state, CellState *cell_state);

#endif// INPUT_H
