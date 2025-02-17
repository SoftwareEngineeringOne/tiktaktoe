#include "presentation/field.h"

#include "presentation/cell.h"
#include "presentation/print.h"
#include <stddef.h>
#include <stdint.h>


void field_redraw()
{
    const uint8_t row_length = CELLS_PER_ROW * CELL_WIDTH + 1;
    char *divider[row_length];
    char *top_divider[row_length];
    char *bot_divider[row_length];
    char *non_divider[row_length];

    for(uint8_t i = 0; i < row_length; i++)
    {
        if(i == 0)
        {
            divider[i] = T_LEFT;
            top_divider[i] = CORNER_TOP_LEFT;
            bot_divider[i] = CORNER_BOT_LEFT;
            non_divider[i] = SIDE;
        }
        else if(i == row_length - 1)
        {
            divider[i] = T_RIGHT;
            top_divider[i] = CORNER_TOP_RIGHT;
            bot_divider[i] = CORNER_BOT_RIGHT;
            non_divider[i] = SIDE;
        }
        else if(i % CELL_WIDTH == 0)
        {
            divider[i] = CROSS;
            top_divider[i] = T_TOP;
            bot_divider[i] = T_BOT;
            non_divider[i] = SIDE;
        }
        else
        {
            divider[i] = TOP_BOTTOM;
            top_divider[i] = TOP_BOTTOM;
            bot_divider[i] = TOP_BOTTOM;
            non_divider[i] = EMPTY;
        }
    }

    printRow(top_divider, row_length);

    uint8_t first = 0;
    for(uint8_t i = 0; i < CELLS_PER_COL; i++)
    {
        if(first == 0)
        {
            first = 1;
        }
        else
        {
            printRow(divider, row_length);
        }
        for(uint8_t j = 0; j < CELL_HEIGHT - 2; j++)
        {
            printRow(non_divider, row_length);
        }
    }
    printRow(bot_divider, row_length);
}


void printRow(char **row, const size_t row_length)
{
    for(size_t i = 0; i < row_length; i++)
    {
        print(row[i]);
    }
    print("\n");
}
