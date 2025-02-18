#ifndef BOT_H
#define BOT_H

#include "logic/game.h"
#include "presentation/field.h"

Cell* bot_makeTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]);
Cell* bot_makeHumanTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]);

static Cell* markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Player mark_by);

#endif// BOT_H
