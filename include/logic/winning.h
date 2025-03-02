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
