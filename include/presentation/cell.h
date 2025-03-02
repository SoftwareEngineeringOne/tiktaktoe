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

typedef enum
{
    Small = 0,
    Medium = 1,
    Large = 2,
} Size;

extern Size current_size;
extern uint8_t cell_width;
extern uint8_t cell_height;

typedef struct
{
        uint8_t width;
        uint8_t height;
} CellSize;


/**
 * @brief Redraws the given cell
 * @param [in] cell
 * Cell to redraw
 */
void cell_redraw(Cell *cell);

/**
 * @brief Redraws the whole field
 * @param [in] all_cells
 * 2D field of cells
 */
void cell_redrawAll(Cell all_cells[][CELLS_PER_ROW]);

/**
 * @brief Selects the given cell
 * @param [in] cell
 * Cell to select
 */
void cell_select(Cell *cell);


/**
 * @brief Marks the given cell
 * @param [in] cell
 * Cell to mark
 */
void cell_mark(Cell *cell);

/**
 * @brief Increases the field size
 */
void cell_increaseSize();

/**
 * @brief Decreases the field size
 */
void cell_decreaseSize();


#endif// CELL_H
