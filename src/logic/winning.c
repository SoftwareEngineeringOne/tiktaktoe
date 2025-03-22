/**
 * @file winning.c
 *
 * @brief Implements the function for checking if someone has won
 *
 * @details
 * This file contains the implementation of the logic for determining if a player
 * has won in the game. It includes the main function and helper functions for
 * evaluating the game state.
 *
 * @see winning.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "logic/winning.h"

/**
 * @brief Checks if the given player has won
 *
 * @details
 * This function evaluates the game board to determine if the specified player has won.
 * It checks vertical, horizontal, and diagonal lines originating from the last marked
 * cell of the player. If a winning condition is met, the relevant cells are written
 * to the provided buffer.
 *
 * @param[in] cell Last marked cell of the player
 * @param[in] player Player it is looking for
 * @param[in] cell_state Current state of the game board
 * @param[out] winner_cells Buffer to store the cells forming the winning line
 *
 * @return True if the player has won, false otherwise
 *
 * @internal
 */
static bool checkIfPlayerWon(
    const Cell *cell,
    Player player,
    CellState *cell_state,
    Cell *winner_cells[max(CELLS_PER_COL, CELLS_PER_ROW)]// NOLINT
);

Player winning_checkForWinner(
    CellState *cell_state,
    Cell *winner_cells[max(CELLS_PER_COL, CELLS_PER_ROW)]// NOLINT
)
{
    if(checkIfPlayerWon(cell_state->last_circle, Circle, cell_state, winner_cells))
    {
        return Circle;
    }
    if(checkIfPlayerWon(cell_state->last_cross, Cross, cell_state, winner_cells))
    {
        return Cross;
    }
    return None;
}

static bool checkIfPlayerWon(
    const Cell *cell,
    const Player player,
    CellState *cell_state,
    Cell *winner_cells[max(CELLS_PER_COL, CELLS_PER_ROW)])// NOLINT
{
    if(cell == NULL)
    {
        return false;
    }

    const uint8_t diagonal_win_condition = min(CELLS_PER_COL, CELLS_PER_ROW);// NOLINT
    const uint8_t max_cells = max(CELLS_PER_COL, CELLS_PER_ROW);             // NOLINT
    const uint8_t row = cell->row;
    const uint8_t col = cell->col;
    const uint8_t max_row = CELLS_PER_COL - 1;
    const uint8_t max_col = CELLS_PER_ROW - 1;
    uint8_t diagonal_1_sum = 1;
    uint8_t diagonal_2_sum = 1;
    bool vertical_match = true;
    bool horizontal_match = true;
    bool diagonal_1_up_right = true;
    bool diagonal_1_down_left = true;
    bool diagonal_2_up_left = true;
    bool diagonal_2_down_right = true;

    Cell *diagonal_1_cells[min(CELLS_PER_COL, CELLS_PER_ROW)] = {0};// NOLINT
    Cell *diagonal_2_cells[min(CELLS_PER_COL, CELLS_PER_ROW)] = {0};// NOLINT
    for(uint8_t i = 1, n = 0; n < max_cells; i++, n++)
    {
        // --- VERTICAL ---
        // downwards
        if(n <= max_row && cell_state->all[n][col].marked_by != player)
        {
            vertical_match = false;
        }

        // --- HORIZONTAL ---
        // to the right
        if(n <= max_col && cell_state->all[row][n].marked_by != player)
        {
            horizontal_match = false;
        }

        // --- 1st DIAGONAL ---
        // upwards to the right
        if(diagonal_1_up_right && row - i >= 0 && col + i <= max_col
           && cell_state->all[row - i][col + i].marked_by == player)
        {
            diagonal_1_cells[n] = &cell_state->all[row - i][col + i];
            diagonal_1_sum++;
        }
        else
        {
            diagonal_1_up_right = false;
        }
        // downwards to the left
        if(diagonal_1_down_left && row + i <= max_row && col - i >= 0
           && cell_state->all[row + i][col - i].marked_by == player)
        {
            diagonal_1_cells[n] = &cell_state->all[row + i][col - i];
            diagonal_1_sum++;
        }
        else
        {
            diagonal_1_down_left = false;
        }

        // --- 2nd DIAGONAL ---
        // upwards to the left
        if(diagonal_2_up_left && row - i >= 0 && col - i >= 0
           && cell_state->all[row - i][col - i].marked_by == player)
        {
            diagonal_2_cells[n] = &cell_state->all[row - i][col - i];
            diagonal_2_sum++;
        }
        else
        {
            diagonal_2_up_left = false;
        }
        // downwards to the right
        if(diagonal_2_down_right && row + i <= max_row && col + i <= max_col
           && cell_state->all[row + i][col + i].marked_by == player)
        {
            diagonal_2_cells[n] = &cell_state->all[row + i][col + i];
            diagonal_2_sum++;
        }
        else
        {
            diagonal_2_down_right = false;
        }
    }

    if(vertical_match)
    {
        for(uint8_t i = 0; i < CELLS_PER_COL; i++)
        {
            winner_cells[i] = &cell_state->all[i][col];
        }
        return true;
    }

    if(horizontal_match)
    {
        for(uint8_t i = 0; i < CELLS_PER_ROW; i++)
        {
            winner_cells[i] = &cell_state->all[row][i];
        }
        return true;
    }

    if(diagonal_1_sum >= diagonal_win_condition)
    {
        for(uint8_t i = 0; i < diagonal_win_condition; i++)
        {
            winner_cells[i] = diagonal_1_cells[i];
        }
        winner_cells[diagonal_win_condition - 1] = &cell_state->all[row][col];
        return true;
    }

    if(diagonal_2_sum >= diagonal_win_condition)
    {
        for(uint8_t i = 0; i < diagonal_win_condition; i++)
        {
            winner_cells[i] = diagonal_2_cells[i];
        }
        winner_cells[diagonal_win_condition - 1] = &cell_state->all[row][col];
        return true;
    }

    return false;
}
