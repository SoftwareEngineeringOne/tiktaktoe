/**
 * @file bot.c
 *
 * @brief Implementation of bot logic for Tic-Tac-Toe game.
 *
 * @see
 *  bot.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "logic/bot.h"

#include "hal/random.h"
#include "logic/game.h"

Cell *bot_markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], const Player marked_by)
{
    for(;;)
    {
        const uint8_t col = rng_getRandomValue_waiting() % CELLS_PER_ROW;
        const uint8_t row = rng_getRandomValue_waiting() % CELLS_PER_COL;

        if(cells[row][col].marked_by == None)
        {
            cells[row][col].marked_by = marked_by;
            Cell *cell = &cells[row][col];
            /* cell_redraw(cell); */
            return cell;
        }
    }
}
