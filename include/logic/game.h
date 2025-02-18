//
// Created by paul on 2/10/25.
//

#ifndef GAME_H
#define GAME_H

#include "hal_high/input_buf.h"
#include "presentation/field.h"
#include <stdint.h>

#define REMAINING_TIME TICKS_PER_ROUND - time_roundTicks

typedef enum
{
    Human,
    Computer,
    None
} Mark;

typedef struct
{
        uint16_t col;
        uint16_t row;
        Mark marked_by;
} Cell;

extern volatile InputBuffer input_buf;

static Cell cells[CELLS_PER_COL][CELLS_PER_ROW];
static Cell* selected_cell;
static Cell* bot_cell;

void game_run();

void game_onTimeOut();

#endif// GAME_H
