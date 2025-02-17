#ifndef INPUT_H
#define INPUT_H

#include "logic/game.h"
#include "presentation/field.h"

void input_handleEscapeSequence(Cell cells[CELLS_PER_ROW][CELLS_PER_COL], Cell **selected_cell);

#endif// !INPUT_H
