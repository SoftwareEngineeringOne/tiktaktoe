#include "logic/game.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/cell.h"
#include "presentation/print.h"

uint8_t cell_width = INITIAL_WIDTH;
uint8_t cell_height = INITIAL_HEIGHT;

void cell_redraw(Cell *cell)
{
    redrawCell(cell->row, cell->col, "", cell->marked_by);
}

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
        redrawCell(prev_top, prev_left, RESET, prev_mark);
    }
    else
    {
        has_prev = true;
    }

    redrawCell(cell->row, cell->col, INVERSE, cell->marked_by);

    prev_top = cell->row;
    prev_left = cell->col;
    prev_mark = cell->marked_by;
}

void cell_redrawAll(Cell cells[CELLS_PER_ROW][CELLS_PER_COL])
{
    for(uint8_t row = 0; row < CELLS_PER_ROW; row++)
    {
        for(uint8_t col = 0; col < CELLS_PER_COL; col++)
        {
            Cell *cell = &cells[row][col];
            redrawCell(cell->row, cell->col, "", cell->marked_by);
        }
    }
}

void redrawCell(uint8_t row, uint8_t col, char *modifier, Mark marked_by)
{
    uint8_t top = (row * (cell_height - 1)) + 1;
    uint8_t left = (col * cell_width) + 1;
    uint8_t bot = top + (cell_height - 2);
    uint8_t right = left + (cell_width - 2);

    uint8_t mid_row = (top + bot) / 2;
    uint8_t mid_col = (left + right) / 2;
    char mid_char = int_to_char(mid_row);
    char mid_char_2 = int_to_char(mid_col);
    for(uint8_t i = top; i < bot; i++)
    {
        cursor_moveTo(left + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(modifier);

        for(uint8_t j = 0; j < (cell_width - 1); j++)
        {
            switch(marked_by)
            {
                case Human:
                    if(i == mid_row && left + j == mid_col)
                    {
                        print("X");
                    }
                    else
                    {
                        print(" ");
                    }
                    break;
                case Computer:
                    if(i == mid_row && left + j == mid_col)
                    {
                        print("O");
                    }
                    else
                    {
                        print(" ");
                    }
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

void cell_increaseSize()
{
    if(size_index + 1 >= NUM_OF_SIZES)
    {
        return;
    }
    size_index++;
    cell_width = VALID_SIZES[size_index].width;
    cell_height = VALID_SIZES[size_index].height;
    print("BREAK ME");
}
void cell_decreaseSize()
{
    if(size_index - 1 < 0)
    {
        return;
    }
    size_index--;
    cell_width = VALID_SIZES[size_index].width;
    cell_height = VALID_SIZES[size_index].height;
    print("BREAK ME");
}
