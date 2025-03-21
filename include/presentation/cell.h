/**
 * @file cell.h
 *
 * @brief Contains functions for changing the presentation of cells
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

#define NUM_OF_SIZES 3
#define INITIAL_INDEX 1
#define INITIAL_WIDTH 8
#define INITIAL_HEIGHT 5
#define INITIAL_SIZE Medium
#define FIELD_HEIGHT (CELLS_PER_COL * g_cell_size.height)

typedef enum
{
    Small = 0,
    Medium = 1,
    Large = 2,
} Size;


typedef struct
{
        Size size;
        uint8_t width;
        uint8_t height;
} CellSize;

extern CellSize g_cell_size;


/**
 * @brief Redraws the given cell
 * @param [in] cell
 * Cell to redraw
 */
void cell_redraw(const Cell *cell);

void cell_redraw_withModifier(const Cell *cell, const char *modifier);

/**
 * @brief Redraws the whole field
 * @param [in] all_cells
 * 2D field of cells
 */
void cell_redrawAll(Cell all_cells[][CELLS_PER_ROW], const char *modifier);

/**
 * @brief Selects the given cell
 * @param [in] cell
 * Cell to select
 */
void cell_select(const Cell *cell);

/**
 * @brief Increases the field size
 */
void cell_increaseSize();

/**
 * @brief Decreases the field size
 */
void cell_decreaseSize();


#endif// CELL_H
