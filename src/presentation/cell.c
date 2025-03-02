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
 *
 */
#include "presentation/cell.h"

#include "logic/game.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/print.h"
#include "presentation/style.h"

uint8_t cell_width = INITIAL_WIDTH;
uint8_t cell_height = INITIAL_HEIGHT;
Size current_size = INITIAL_SIZE;

/**
 * @brief Redraw one cell
 * @param [in] row
 * Y-Position
 * @param [in] col
 * X-Position
 * @param [in] modifier
 * @param [in] marked_by
 * Player to mark by
 */
static void _redrawCell(uint8_t row, uint8_t col, char *modifier, Player marked_by);

static char *SMALL_X[1][3] = {{" ", "X", " "}};

static char *SMALL_O[1][3] = {{" ", "O", " "}};

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

static CellSize VALID_SIZES[] = {
    {.width = 4, .height = 3},
    {.width = 8, .height = 5},
    {.width = 10, .height = 7},
};

void cell_redraw(Cell *cell)
{
    _redrawCell(cell->row, cell->col, "", cell->marked_by);
}

void cell_select(Cell *cell)
{
    static uint16_t prev_top = 0;
    static uint16_t prev_left = 0;
    static Player prev_mark;
    static bool has_prev = false;

    // with +1 to account for top/left divider
    // with -2 account for dividers
    if(has_prev)
    {
        _redrawCell(prev_top, prev_left, RESET, prev_mark);
    }
    else
    {
        has_prev = true;
    }

    _redrawCell(cell->row, cell->col, INVERSE, cell->marked_by);

    prev_top = cell->row;
    prev_left = cell->col;
    prev_mark = cell->marked_by;
}

void cell_redrawAll(Cell all_cells[][CELLS_PER_ROW])
{
    Cell *cell = NULL;
    for(uint8_t row = 0; row < CELLS_PER_COL; row++)
    {
        for(uint8_t col = 0; col < CELLS_PER_ROW; col++)
        {
            cell = &all_cells[row][col];
            _redrawCell(cell->row, cell->col, "", cell->marked_by);
        }
    }
}

void _redrawCell(uint8_t row, uint8_t col, char *modifier, Player marked_by)
{
    const uint8_t top = row * (cell_height - 1) + 1;
    const uint8_t left = col * cell_width + 1;
    const uint8_t bot = top + (cell_height - 2);
    const uint8_t right = left + (cell_width - 2);

    for(uint8_t i = top; i < bot; i++)
    {
        cursor_moveTo(left + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(modifier);

        for(uint8_t j = 0; j < cell_width - 1; j++)
        {
            switch(marked_by)
            {
                case Circle:
                    print(FG_GREEN);
                    switch(current_size)
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
                    print("\e[37");
                    break;
                case Cross:
                    print(FG_MAGENTA);
                    switch(current_size)
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
                    print("\e[37");
                    break;
                case None:
                    print(" ");
                    break;
            }
        }


        cursor_moveTo(right + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(RESET);
    }
}

void cell_increaseSize()
{
    if(current_size + 1 >= Large + 1)
    {
        return;
    }
    current_size++;
    cell_width = VALID_SIZES[current_size].width;
    cell_height = VALID_SIZES[current_size].height;
}
void cell_decreaseSize()
{
    if(current_size - 1 < Small)
    {
        return;
    }
    current_size--;
    cell_width = VALID_SIZES[current_size].width;
    cell_height = VALID_SIZES[current_size].height;
}
