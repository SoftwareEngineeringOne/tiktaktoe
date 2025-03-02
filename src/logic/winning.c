#include "logic/winning.h"

/**
 * @brief Checks if the given player has won
 *
 * @details
 * VICTORY ALGORITHM
 * Vertical / Horizontal:
 * The algorithm starts at the border and iterates to the other side. It goes in 2 different
 * directions and counts on 2 axes. It runs in one of the directions till a cell is reached that
 * is not marked by our player. Diagonal: The algorithm starts at the given cell coordinates. It
 * goes in 4 different direction and counts on 2 axes. Every step in one of the directions
 * increments the dedicated axis until a cell is reached that is not marked by our player.
 *
 * The return value is true when one axis or more axes has / have reached the win condition
 * (line to the other side).
 *  UP      UP     UP          | axis       | direction 1 | direction 2 |
 * LEFT           RIGHT        |------------+-------------+-------------|
 *        \ | /                | vertical   | down        |             |
 * LEFT  ---+---> RIGHT        | horizontal | right       |             |
 *        / | \                | diagonal_1 | up right    | down left   |
 * DOWN     v     DOWN         | diagonal_2 | up left     | down right  |
 * LEFT    DOWN   RIGHT
 *
 * @param [in] cell Last marked cell of the player
 * @param [in] player Player it is looking for
 * @param [in] cell_state
 * @param [out] winner_cells
 *
 * @return True if player won
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

bool checkIfPlayerWon(
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
    const uint8_t row = cell->row, col = cell->col;
    const uint8_t max_row = CELLS_PER_COL - 1, max_col = CELLS_PER_ROW - 1;
    uint8_t diagonal_1_sum = 1, diagonal_2_sum = 1;
    bool vertical_match = true, horizontal_match = true;
    bool diagonal_1_up_right = true, diagonal_1_down_left = true, diagonal_2_up_left = true,
         diagonal_2_down_right = true;

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
