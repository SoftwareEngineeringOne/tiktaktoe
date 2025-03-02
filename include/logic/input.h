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

#include "logic/game.h"
#include "presentation/field.h"

/**
 * @brief Do certain things on input with escape sequences
 * @param [inout] cells
 * 2D field of cells
 * @param [inout] selected_cell
 * Selected cell
 */
void input_handleEscapeSequence(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Cell **selected_cell);

#endif// !INPUT_H
