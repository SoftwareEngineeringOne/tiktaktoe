#include "logic/input.h"
#include "hal_high/input_buf.h"
#include "presentation/cell.h"
#include "presentation/field.h"

void input_handleEscapeSequence(Cell cells[CELLS_PER_COL][CELLS_PER_ROW], Cell **selected_cell)
{
    uint8_t input = '\0';
    if(!input_getNext(&input_buf, &input) || input != '[')
    {
        return;
    }

    if(!input_getNext(&input_buf, &input))
    {
        return;
    }

    const int col = (*selected_cell)->col;
    const int row = (*selected_cell)->row;

    switch(input)
    {
        case 'A':
            if(row - 1 >= 0)
            {
                *selected_cell = &cells[row - 1][col];
            }
            break;
        case 'B':
            if(row + 1 < CELLS_PER_COL)
            {
                *selected_cell = &cells[row + 1][col];
            }
            break;
        case 'C':
            if(col + 1 < CELLS_PER_ROW)
            {
                *selected_cell = &cells[row][col + 1];
            }
            break;
        case 'D':
            if(col - 1 >= 0)
            {
                *selected_cell = &cells[row][col - 1];
            }
            break;
        default:;
    }
}
