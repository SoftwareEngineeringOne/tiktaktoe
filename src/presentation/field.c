/**
 * @file 
 *
 * @author 
 *
 * @date 
 *
 * @brief 
 *
 * @see 
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
#include "presentation/field.h"

#include "presentation/cell.h"
#include "presentation/cursor.h"
#include "presentation/print.h"

#include "config.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Print one row
 * @param [in] row String to print
 * @param [in] row_length Length of string
 *
 */
static void _printRow(char **row, size_t row_length);

void field_redraw()
{
    const uint8_t row_length = CELLS_PER_ROW * cell_width + 1;
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
        else if(i % cell_width == 0)
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

    cursor_moveTo(FIELD_X_OFFSET, FIELD_Y_OFFSET);
    _printRow(top_divider, row_length);

    uint8_t first = 0;
    for(uint8_t i = 0; i < CELLS_PER_COL; i++)
    {
        if(first == 0)
        {
            first = 1;
        }
        else
        {
            _printRow(divider, row_length);
        }
        for(uint8_t j = 0; j < cell_height - 2; j++)
        {
            _printRow(non_divider, row_length);
        }
    }
    _printRow(bot_divider, row_length);
}


void _printRow(char **row, const size_t row_length)
{
    for(size_t i = 0; i < row_length; i++)
    {
        print(row[i]);
    }
    print("\n");
}
