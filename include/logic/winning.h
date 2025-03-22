/**
 * @file winning.h
 *
 * @brief Contains the function for checking if someone has won
 *
 * @details
 * This file contains the declaration of the function used to check if a player has won
 * in the game.

 * # VICTORY ALGORITHM
 * ## Vertical / Horizontal:
 * The algorithm starts at the border and iterates to the other side. It goes in 2 different
 * directions and counts on 2 axes. It runs in one of the directions till a cell is reached that
 * is not marked by our player. Diagonal: The algorithm starts at the given cell coordinates. It
 * goes in 4 different direction and counts on 2 axes. Every step in one of the directions
 * increments the dedicated axis until a cell is reached that is not marked by our player.
 *
 * The return value is true when one axis or more axes has / have reached the win condition
 * (line to the other side).
 * ```text
 *  UP      UP     UP          | axis       | direction 1 | direction 2 |
 * LEFT           RIGHT        |------------+-------------+-------------|
 *        \ | /                | vertical   | down        |             |
 * LEFT  ---+---> RIGHT        | horizontal | right       |             |
 *        / | \                | diagonal_1 | up right    | down left   |
 * DOWN     v     DOWN         | diagonal_2 | up left     | down right  |
 * LEFT    DOWN   RIGHT
 * ```
 *
 * @ingroup Logic
 *
 * @see winning.c
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
 * @details
 * This function evaluates the current state of the game board to determine if a player
 * has won. If a player has won, the relevant cells are written to the provided buffer.
 *
 * @param[in] cell_state Current state of the cells
 * @param[out] winner_cells If a player won, the relevant cells will be written to this buffer
 *
 * @return The player who won, or `None` if no player has won
 */
Player winning_checkForWinner(
    CellState *cell_state,
    Cell *winner_cells[max(CELLS_PER_COL, CELLS_PER_ROW)]);

#endif// WINNING_H
