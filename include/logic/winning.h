/**
 * @file winning.h
 *
 * @brief Contains the function for checking if someone has won
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WINNING_H
#define WINNING_H

#include "logic/game.h"
#include "util/math.h"

/**
 * @brief Checks at the end of the round if someone has won
 *
 * @param [in] cell_state
 * @param [out] winner_cells
 *
 * @return The player who won
 */
Player winning_checkForWinner(
    CellState *cell_state,
    Cell *winner_cells[max(CELLS_PER_COL, CELLS_PER_ROW)]);

#endif// WINNING_H
