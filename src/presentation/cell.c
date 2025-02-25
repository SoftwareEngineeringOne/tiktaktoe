#include "presentation/cell.h"

#include "logic/game.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/print.h"

uint8_t cell_width = INITIAL_WIDTH;
uint8_t cell_height = INITIAL_HEIGHT;
Size current_size = INITIAL_SIZE;

void cell_redraw(Cell *cell)
{
    redrawCell(cell->row, cell->col, "", cell->marked_by);
}

void cell_select(Cell *cell)
{
    static uint16_t prev_top = 0;
    static uint16_t prev_left = 0;
    static Player prev_mark;
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

void cell_redrawAll(Cell cells[CELLS_PER_COL][CELLS_PER_ROW])
{
    for(uint8_t row = 0; row < CELLS_PER_ROW; row++)
    {
        for(uint8_t col = 0; col < CELLS_PER_COL; col++)
        {
            const Cell *cell = &cells[row][col];
            redrawCell(cell->row, cell->col, "", cell->marked_by);
        }
    }
}

void redrawCell(uint8_t row, uint8_t col, char *modifier, Player marked_by)
{
    const uint8_t top = row * (cell_height - 1) + 1;
    const uint8_t left = col * cell_width + 1;
    const uint8_t bot = top + (cell_height - 2);
    const uint8_t right = left + (cell_width - 2);

    for(uint8_t i = top; i < bot; i++)
    {
        cursor_moveTo(left + FIELD_X_OFFSET, i + FIELD_Y_OFFSET);
        print(modifier);

        for(uint8_t j = 0; j < cell_width - 1; j++)
        {
            switch(marked_by)
            {
                case Circle:
                    print(FG_GREEN);
                    switch(current_size)
                    {
                        case Small:
                            print(SMALL_X[i - top][j]);
                            break;
                        case Medium:
                            print(MEDIUM_X[i - top][j]);
                            break;
                        case Large:
                            print(LARGE_X[i - top][j]);
                            break;
                    }
                    print("\e[37");
                    break;
                case Cross:
                    print(FG_MAGENTA);
                    switch(current_size)
                    {
                        case Small:
                            print(SMALL_O[i - top][j]);
                            break;
                        case Medium:
                            print(MEDIUM_O[i - top][j]);
                            break;
                        case Large:
                            print(LARGE_O[i - top][j]);
                            break;
                    }
                    print("\e[37");
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
    if(current_size + 1 >= Large + 1)
    {
        return;
    }
    current_size++;
    cell_width = VALID_SIZES[current_size].width;
    cell_height = VALID_SIZES[current_size].height;
}
void cell_decreaseSize()
{
    if(current_size - 1 < Small)
    {
        return;
    }
    current_size--;
    cell_width = VALID_SIZES[current_size].width;
    cell_height = VALID_SIZES[current_size].height;
}
