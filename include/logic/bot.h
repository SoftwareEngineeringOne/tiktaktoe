/**
 * @file bot.h
 *
 * @brief Contains function for random cell marking (a "bot player")
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
 * @brief Mark some random cell
 * @param [inout] cells 2D field of cells
 * @param [in] marked_by Player to be marked by
 *
 * @return Marked cell
 */
Cell *bot_markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Player marked_by);

#endif// BOT_H
