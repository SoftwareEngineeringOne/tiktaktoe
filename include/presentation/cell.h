#ifndef CELL_H
#define CELL_H

#include <stdint.h>
#include <stddef.h>
#include "def.h"
#include "logic/game.h"
#include "presentation/field.h"

extern uint8_t CELL_WIDTH;
extern uint8_t CELL_HEIGHT;

void cell_select(Cell *field);

void cell_redraw(uint16_t row, uint16_t col, char *modifier, Mark marked_by);

void cell_mark(Cell *cell);

bool cell_moveUp(Cell *selected_field);

bool cell_moveDown(Cell *selected_field);

bool cell_moveLeft(Cell *selected_field);

bool cell_moveRight(Cell *selected_field);


#endif// !CELL_H
