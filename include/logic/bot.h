#ifndef BOT_H
#define BOT_H

#include "logic/game.h"
#include "presentation/field.h"

/**
 * @brief Mark some random cell for the bot player
 * @param [inout] cells
 * 2D field of cells
 * @return Marked cell
 */
Cell *bot_makeTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]);

/**
 * @brief Mark some random cell for the human player
 * @param [inout] cells
 * 2D field of cells
 * @return Marked cell
 */
Cell *bot_makeHumanTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]);

/**
 * @brief some random cell
 * @param [inout] cells
 * 2D field of cells
 * @param mark_by
 * Player to be marked by
 * @return Marked cell
 */
static Cell *markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Player mark_by);

#endif// BOT_H
