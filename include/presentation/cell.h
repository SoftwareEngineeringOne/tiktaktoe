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

void cell_mark(Cell *cell);

bool cell_moveUp(Cell *selected_field);

bool cell_moveDown(Cell *selected_field);

bool cell_moveLeft(Cell *selected_field);

bool cell_moveRight(Cell *selected_field);

static void redrawCell(uint16_t top, uint16_t left, char *modifier, Mark marked_by);

#endif// !CELL_H
