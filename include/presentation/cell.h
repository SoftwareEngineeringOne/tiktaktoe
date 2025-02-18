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

static uint8_t size_index = INITIAL_INDEX;
extern uint8_t cell_width ;
extern uint8_t cell_height ;

typedef struct {
        uint8_t width;
        uint8_t height;
} CellSize;

static CellSize VALID_SIZES[] = {
{.width = 4, .height = 3},
{.width = 8, .height = 5},
{.width = 10, .height = 6},
};


void cell_redraw(Cell *cell);

void cell_redrawAll(Cell cells[CELLS_PER_ROW][CELLS_PER_COL]);

void cell_select(Cell *cell);

void redrawCell(uint8_t row, uint8_t col, char *modifier, Mark marked_by);

void cell_mark(Cell *cell);

void cell_increaseSize();
void cell_decreaseSize();


#endif// !CELL_H
