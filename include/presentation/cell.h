#ifndef CELL_H
#define CELL_H

#include <stdint.h>
#include <stddef.h>
#include "def.h"
#include "logic/game.h"
#include "presentation/field.h"

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


void cell_redraw(Cell *cell);

void cell_redrawAll(Cell cells[CELLS_PER_ROW][CELLS_PER_COL]);

void cell_select(Cell *cell);

void redrawCell(uint8_t row, uint8_t col, char *modifier, Player marked_by);

void cell_mark(Cell *cell);

void cell_increaseSize();
void cell_decreaseSize();


#endif// !CELL_H
