#include "logic/bot.h"

#include "logic/game.h"
#include "hal_low/random.h"
#include "presentation/field.h"
#include "presentation/cell.h"

Cell* bot_makeTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]) {
    return markRandomCell(cells, Computer);
}

Cell* bot_makeHumanTurn(Cell cells[CELLS_PER_COL][CELLS_PER_ROW]) {
    return markRandomCell(cells, Human);
}

static Cell* markRandomCell(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Player marked_by) {
    for (;;) {

        uint8_t col = rng_getRandomValue_waiting() % CELLS_PER_ROW;
        uint8_t row = rng_getRandomValue_waiting() % CELLS_PER_COL;

        if (cells[row][col].marked_by == None) {
            cells[row][col].marked_by = marked_by;
            Cell* cell = &cells[row][col];
            /* cell_redraw(cell); */
            return cell;
        }
    }
}