#include "logic/bot.h"

#include "logic/game.h"
#include "hal_low/random.h"
#include "presentation/field.h"
#include "presentation/cell.h"

void bot_makeTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]) {
    markRandomCell(cells, Computer);
}

void bot_makeHumanTurn(Cell cells[CELLS_PER_ROW][CELLS_PER_COL]) {
    markRandomCell(cells, Human);
}

static void markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Mark mark_by) {
    for (;;) {
        const uint8_t col = rng_getRandomValue_waiting() % CELLS_PER_ROW;
        const uint8_t row = rng_getRandomValue_waiting() % CELLS_PER_COL;

        if (cells[row][col].marked_by == None) {
            cells[row][col].marked_by = mark_by;
            cell_select(&cells[row][col]);
            return;
        }
    }

}
