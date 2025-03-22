/**
 * @file cell.c
 *
 * @brief Implements functions for managing the presentation of cells.
 *
 * @see cell.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "presentation/cell.h"

#include "logic/game.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/print.h"
#include "presentation/style.h"

CellSize g_cell_size = (CellSize){
    .size = INITIAL_SIZE,
    .height = INITIAL_HEIGHT,
    .width = INITIAL_WIDTH,
};

/**
 * @brief Redraws a single cell at the specified position.
 *
 * @param[in] row Y-position of the cell.
 * @param[in] col X-position of the cell.
 * @param[in] modifier Modifier to apply during redraw.
 * @param[in] marked_by Player marking the cell.
 *
 * @internal
 */
static void redrawCell(uint8_t row, uint8_t col, const char *modifier, Player marked_by);

static char *SMALL_X[1][3] = {{" ", "X", " "}};///< Representation of a small 'X'.
static char *SMALL_O[1][3] = {{" ", "O", " "}};///< Representation of a small 'O'.

static char *MEDIUM_X[3][7] = {
    {" ", " ", DIAGONAL_BW, " ", DIAGONAL_FW, " ", " "},
    {" ", " ", " ", DIAGONAL_MID, " ", " ", " "},
    {" ", " ", DIAGONAL_FW, " ", DIAGONAL_BW, " ", " "},
};

static char *MEDIUM_O[3][7] = {
    {" ", CORNER_TOP_LEFT, TOP_BOTTOM, TOP_BOTTOM, TOP_BOTTOM, CORNER_TOP_RIGHT, " "},
    {" ", SIDE, " ", " ", " ", SIDE, " "},
    {" ", CORNER_BOT_LEFT, TOP_BOTTOM, TOP_BOTTOM, TOP_BOTTOM, CORNER_BOT_RIGHT, " "},
};

static char *LARGE_X[5][9] = {
    {" ", " ", DIAGONAL_BW, " ", " ", " ", DIAGONAL_FW, " ", " "},
    {" ", " ", " ", DIAGONAL_BW, " ", DIAGONAL_FW, " ", " ", " "},
    {" ", " ", " ", " ", DIAGONAL_MID, " ", " ", " ", " "},
    {" ", " ", " ", DIAGONAL_FW, " ", DIAGONAL_BW, " ", " ", " "},
    {" ", " ", DIAGONAL_FW, " ", " ", " ", DIAGONAL_BW, " ", " "},
};

static char *LARGE_O[5][9] = {
    {" ",
     CORNER_TOP_LEFT,
     TOP_BOTTOM,
     TOP_BOTTOM,
     TOP_BOTTOM,
     TOP_BOTTOM,
     TOP_BOTTOM,
     CORNER_TOP_RIGHT,
     " "},
    {" ", SIDE, " ", " ", " ", " ", " ", SIDE, " "},
    {" ", SIDE, " ", " ", " ", " ", " ", SIDE, " "},
    {" ", SIDE, " ", " ", " ", " ", " ", SIDE, " "},
    {" ",
     CORNER_BOT_LEFT,
     TOP_BOTTOM,
     TOP_BOTTOM,
     TOP_BOTTOM,
     TOP_BOTTOM,
     TOP_BOTTOM,
     CORNER_BOT_RIGHT,
     " "},
};

/**
 * @brief Array of valid cell sizes.
 *
 * @details
 * Each entry contains the width and height for a specific size.
 *
 * @internal
 */
static CellSize VALID_SIZES[] = {
    {.width = 4, .height = 3},
    {.width = 8, .height = 5},
    {.width = 10, .height = 7},
};

void cell_redraw(const Cell *cell)
{
    redrawCell(cell->row, cell->col, "", cell->marked_by);
}

void cell_redraw_withModifier(const Cell *cell, const char *modifier)
{
    redrawCell(cell->row, cell->col, modifier, cell->marked_by);
}

void cell_select(const Cell *cell)
{
    static uint16_t prev_top = 0;
    static uint16_t prev_left = 0;
    static Player prev_mark;
    static bool has_prev = false;

    // with +1 to account for top/left divider
    // with -2 account for dividers
    if(has_prev)
    {
        redrawCell(prev_top, prev_left, 0, prev_mark);
    }
    else
    {
        has_prev = true;
    }

    redrawCell(cell->row, cell->col, INVERSE, cell->marked_by);

    prev_top = cell->row;
    prev_left = cell->col;
    prev_mark = cell->marked_by;
}

void cell_redrawAll(Cell all_cells[][CELLS_PER_ROW], const char *modifier)
{
    const Cell *cell = NULL;
    for(uint8_t row = 0; row < CELLS_PER_COL; row++)
    {
        for(uint8_t col = 0; col < CELLS_PER_ROW; col++)
        {
            cell = &all_cells[row][col];
            redrawCell(cell->row, cell->col, modifier, cell->marked_by);
        }
    }
}

void cell_increaseSize()
{
    if(g_cell_size.size + 1 >= Large + 1)
    {
        return;
    }
    g_cell_size.size++;
    g_cell_size.width = VALID_SIZES[g_cell_size.size].width;
    g_cell_size.height = VALID_SIZES[g_cell_size.size].height;
}

void cell_decreaseSize()
{
    if(g_cell_size.size - 1 < Small)
    {
        return;
    }
    g_cell_size.size--;
    g_cell_size.width = VALID_SIZES[g_cell_size.size].width;
    g_cell_size.height = VALID_SIZES[g_cell_size.size].height;
}

static void
redrawCell(const uint8_t row, const uint8_t col, const char *modifier, const Player marked_by)
{
    const uint8_t top = row * (g_cell_size.height - 1) + 1;
    const uint8_t left = col * g_cell_size.width + 1;
    const uint8_t bot = top + (g_cell_size.height - 2);
    const uint8_t right = left + (g_cell_size.width - 2);

    for(uint8_t i = top; i < bot; i++)
    {
        cursor_moveTo(left + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);

        print(modifier);
        for(uint8_t j = 0; j < g_cell_size.width - 1; j++)
        {
            switch(marked_by)
            {
                case Cross:
                    print_style(&DEFAULT_CROSS);
                    print(modifier);
                    switch(g_cell_size.size)
                    {
                        case Small:
                            print(SMALL_X[i - top][j]);
                            break;
                        case Medium:
                            print(MEDIUM_X[i - top][j]);
                            break;
                        case Large:
                            print(LARGE_X[i - top][j]);
                            break;
                    }
                    break;
                case Circle:
                    print_style(&DEFAULT_CIRCLE);
                    print(modifier);
                    switch(g_cell_size.size)
                    {
                        case Small:
                            print(SMALL_O[i - top][j]);
                            break;
                        case Medium:
                            print(MEDIUM_O[i - top][j]);
                            break;
                        case Large:
                            print(LARGE_O[i - top][j]);
                            break;
                    }
                    break;
                case None:
                    print(modifier);
                    print(" ");
                    break;
            }
        }


        cursor_moveTo(right + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(RESET);
    }
}
