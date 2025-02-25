#ifndef GAME_H
#define GAME_H

#include "hal_high/input_buf.h"
#include "presentation/field.h"

#include <stdint.h>

#define REMAINING_TIME (TICKS_PER_ROUND - time_roundTicks)

typedef enum
{
    Human,
    Computer,
    None
} Player;

/**
 * @brief One cell on the field
 *
 * Contains coordinates and information by whom it is marked
 */
typedef struct
{
        uint16_t col;
        uint16_t row;
        Player marked_by;
} Cell;

static Cell cells[CELLS_PER_COL][CELLS_PER_ROW];
static Cell *selected_cell;
static Cell *last_marked_bot;
static Cell *last_marked_human;

/**
 * @brief Start the main game
 */
void game_run();

/**
 * @brief Automatic turn in case the round time is over
 */
void game_onTimeOut();

/**
 * @brief Initializes several things at the game start
 */
static void init();

/**
 * @brief Checks at the end of the round if someone has won
 * @return The player who won
 */
static Player checkForWinner();

/**
 * @brief Handles the presentation update in case of a automatic round
 */
static void handleForcedMoveUpdate();

/**
 * @brief Checks if the given player has won
 * @param [in] cell
 * Newest marked cell of the player
 * @param [in] player
 * Player it is looking for
 * @return True when player won
 */
static bool checkIfPlayerWon(const Cell *cell, Player player);

/**
 * @brief Does certain things on input
 * @param [in] input
 */
static bool handleInput(const uint8_t *input);

/**
 * @brief Refreshes the whole UI
 */
static void redrawField();

#endif// GAME_H
