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
} Player;

typedef struct
{
        uint16_t col;
        uint16_t row;
        Player marked_by;
} Cell;

extern volatile InputBuffer input_buf;

static Cell cells[CELLS_PER_COL][CELLS_PER_ROW];
static Cell* selected_cell;
static Cell* last_marked_bot;
static Cell* last_marked_human;

void game_run();

void game_onTimeOut();

static void init();

static Player checkForWinner();

static void handleForcedMoveUpdate();

static bool checkIfPlayerWon(const Cell * cell, Player mark);

static bool handleInput(const uint8_t *input);

static void redrawField();

#endif// GAME_H
