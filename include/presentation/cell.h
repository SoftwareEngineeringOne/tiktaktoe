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

typedef struct
{
        uint8_t width;
        uint8_t height;
} CellSize;

static CellSize VALID_SIZES[] = {
    {.width = 4, .height = 3},
    {.width = 8, .height = 5},
    {.width = 10, .height = 7},
};

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

#endif// CELL_H
