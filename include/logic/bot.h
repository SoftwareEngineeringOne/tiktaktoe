#ifndef BOT_H
#define BOT_H

#include "logic/game.h"
#include "presentation/field.h"

/**
 * @brief Mark some random cell
 * @param [inout] cells
 * 2D field of cells
 * @param mark_by
 * Player to be marked by
 * @return Marked cell
 */
Cell *bot_markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Player mark_by);

#endif// BOT_H
