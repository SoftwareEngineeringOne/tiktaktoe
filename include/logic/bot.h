/**
 * @file bot.h
 *
 * @brief Bot logic for Tic-Tac-Toe game.
 *
 * @details
 * This file contains the declaration of functions used to implement bot logic
 * for the Tic-Tac-Toe game, such as marking a random cell.
 *
 * @ingroup Logic
 *
 * @see
 *  bot.c
 *  game.h
 *  field.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef BOT_H
#define BOT_H

#include "logic/game.h"
#include "presentation/field.h"

/**
 * @brief Mark a random unmarked cell on the game board.
 *
 * @param[inout] cells 2D field of cells representing the game board.
 * @param[in] marked_by Player who should mark the cell.
 *
 * @return Pointer to the marked cell.
 *
 * @warning This function assumes that there is at least one unmarked cell
 * on the board. If there is not, the function will loop indefinitely.
 */
Cell *bot_markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Player marked_by);

#endif// BOT_H
