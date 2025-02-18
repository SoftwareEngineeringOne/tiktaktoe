#include "logic/game.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/cell.h"
#include "presentation/print.h"

uint8_t CELL_WIDTH = 8;
uint8_t CELL_HEIGHT = 5;


void cell_select(Cell *cell)
{
    static uint16_t prev_top = 0;
    static uint16_t prev_left = 0;
    static Mark prev_mark;
    static bool has_prev = false;

    // with +1 to account for top/left divider
    // with -2 account for dividers
    if(has_prev)
    {
        cell_redraw(prev_top, prev_left, RESET, prev_mark);
    }
    else
    {
        has_prev = true;
    }

    cell_redraw(cell->row, cell->col, INVERSE, cell->marked_by);

    prev_top = cell->row;
    prev_left = cell->col;
    prev_mark = cell->marked_by;
}

void cell_redraw(uint16_t row, uint16_t col, char *modifier, Mark marked_by)
{
    uint16_t top = (row * (CELL_HEIGHT - 1)) + 1;
    uint16_t left = (col * CELL_WIDTH) + 1;
    uint16_t bot = top + (CELL_HEIGHT - 2);
    uint16_t right = left + (CELL_WIDTH - 2);

    for(uint16_t i = top; i < bot; i++)
    {
        cursor_moveTo(left + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(modifier);

        for(uint8_t j = 0; j < (CELL_WIDTH - 1); j++)
        {
            switch(marked_by)
            {
                case Human:
                    print("X");
                    break;
                case Computer:
                    print("O");
                    break;
                case None:
                    print(" ");
                    break;
            }
        }


        cursor_moveTo(right + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(RESET);
    }
}
