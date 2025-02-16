#include "logic/input.h"
#include "hal_high/input_buf.h"
#include "presentation/cell.h"

void input_handleEscapeSequence(Cell *selected_cell)
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

    switch(input)
    {
        case 'A':
            cell_moveUp(selected_cell);
            break;
        case 'B':
            cell_moveDown(selected_cell);
            break;
        case 'C':
            cell_moveRight(selected_cell);
            break;
        case 'D':
            cell_moveLeft(selected_cell);
            break;
        default:;
    }
}
