#include "logic/input.h"
#include "hal_high/input_buf.h"
#include "presentation/cell.h"
#include "presentation/field.h"
#include "presentation/cursor.h"
#include "presentation/print.h"

void input_handleEscapeSequence(Cell *cells[CELLS_PER_COL][CELLS_PER_ROW], Cell *selected_cell)
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

    int col = selected_cell->col;
    int row = selected_cell->row;

    // TODO To be removed
    cursor_moveTo(20,1);
    //selected_cell->col = 10;
    int i = selected_cell->col;
    char* string[10];
    int_to_str(i, string, 10);
    print(string);

    switch(input)
    {
        case 'A':
            if (cell_moveUp(selected_cell)) {
                selected_cell = cells[row][col-1];
            };
            break;
        case 'B':
            if (cell_moveDown(selected_cell)) {
                selected_cell = &cells[row][col+1];
            };
            break;
        case 'C':
            if (cell_moveRight(selected_cell)) {
                selected_cell = cells[row+1][col];
            };
            break;
        case 'D':
            if (cell_moveLeft(selected_cell)) {
                selected_cell = cells[row-1][col];
            };
            break;
        default:;
    }
        // TODO To be removed
        cursor_moveTo(30,1);
        //selected_cell->col = 10;
        i = selected_cell->col;
        //char* string[10];
        int_to_str(i, string, 10);
        print(string);
    
}
