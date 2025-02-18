#include "logic/bot.h"

#include "logic/game.h"
#include "hal_low/random.h"
#include "presentation/print.h"
#include "presentation/cell.h"

void bot_mark(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]) {
    for (;;) {
        const uint8_t col = rng_getRandomValueWaiting() % CELLS_PER_ROW;
        const uint8_t row = rng_getRandomValueWaiting() % CELLS_PER_COL;

        if (cells[row][col].marked_by == None) {
            cells[row][col].marked_by = Computer;
            cell_select(&cells[row][col]);
            return;
        }
    }
}