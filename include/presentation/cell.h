/**
 * @file cell.h
 *
 * @brief Contains functions and definitions for managing the presentation of cells.
 *
 * @details
 * This file provides functions to redraw cells, manage cell selection, and adjust cell sizes.
 * It also defines the `CellSize` struct and `Size` enum for handling cell dimensions.
 *
 * @ingroup Presentation
 *
 * @see cell.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CELL_H
#define CELL_H

#include "logic/game.h"
#include "presentation/field.h"

#include <stdint.h>

#define NUM_OF_SIZES 3     ///< Number of available cell sizes.
#define INITIAL_INDEX 1    ///< Initial index for cell size.
#define INITIAL_WIDTH 8    ///< Initial width of a cell.
#define INITIAL_HEIGHT 5   ///< Initial height of a cell.
#define INITIAL_SIZE Medium///< Initial size of a cell.
#define FIELD_HEIGHT \
    (CELLS_PER_COL * g_cell_size.height)///< Height of the field based on cell size.

/**
 * @brief Enum representing the available cell sizes.
 */
typedef enum
{
    Small = 0, ///< Small cell size.
    Medium = 1,///< Medium cell size.
    Large = 2, ///< Large cell size.
} Size;

/**
 * @brief Struct representing the dimensions of a cell.
 */
typedef struct
{
        Size size;     ///< Current size of the cell.
        uint8_t width; ///< Width of the cell.
        uint8_t height;///< Height of the cell.
} CellSize;

/**
 * @brief Global variable representing the current cell size.
 *
 * @details
 * Initialized with default values for size, height, and width.
 *
 * @see VALID_SIZES
 * @see INITIAL_SIZE
 * @see INITIAL_HEIGHT
 * @see INITIAL_WIDTH
 */
extern CellSize g_cell_size;

/**
 * @brief Redraws the given cell.
 *
 * @param[in] cell Cell to redraw.
 */
void cell_redraw(const Cell *cell);

/**
 * @brief Redraws the given cell with a modifier.
 *
 * @param[in] cell Cell to redraw.
 * @param[in] modifier Modifier to apply during redraw.
 */
void cell_redraw_withModifier(const Cell *cell, const char *modifier);

/**
 * @brief Redraws the entire field of cells.
 *
 * @param[in] all_cells 2D array of cells representing the field.
 * @param[in] modifier Modifier to apply during redraw.
 */
void cell_redrawAll(Cell all_cells[][CELLS_PER_ROW], const char *modifier);

/**
 * @brief Selects the given cell.
 *
 * @param[in] cell Cell to select.
 */
void cell_select(const Cell *cell);

/**
 * @brief Increases the size of the cells.
 */
void cell_increaseSize();

/**
 * @brief Decreases the size of the cells.
 */
void cell_decreaseSize();

#endif// CELL_H
