#ifndef BOT_H
#define BOT_H

#include "logic/game.h"
#include "presentation/field.h"

void bot_makeTurn(Cell cells[CELLS_PER_ROW][CELLS_PER_COL]);
void bot_makeHumanTurn(Cell cells[CELLS_PER_ROW][CELLS_PER_COL]);

static void markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Mark mark_by);

#endif// BOT_H
