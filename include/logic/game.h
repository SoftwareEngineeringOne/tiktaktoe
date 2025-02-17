//
// Created by paul on 2/10/25.
//

#ifndef GAME_H
#define GAME_H

#include "hal_high/input_buf.h"
#include "presentation/field.h"
#include <stdint.h>

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

void game_run();

/**
 * @brief Tries to mark the current position
 **/
void game_markPosition();

/**
 * @brief Increase the clock by one second
 **/
void game_updateTime();

#endif// GAME_H
