#ifndef GAME_H
#define GAME_H

#include "hal_high/input_buf.h"
#include "presentation/field.h"

#include <stdint.h>

#define REMAINING_TIME (TICKS_PER_ROUND - time_roundTicks)
#define FIRST_TURN 1

typedef enum
{
    PVE,
    PVP,
} Mode;

typedef enum
{
    Circle = 0,
    Cross = 1,
    None = 2,
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

static Mode game_mode;
static Player current_player;
static volatile uint8_t turn_number;
static uint8_t last_ui_update;

static Cell cells[CELLS_PER_COL][CELLS_PER_ROW];
static Cell *selected_cell;
static Cell *last_marked_cross;
static Cell *last_marked_circle;

/**
 * @brief Start the main game
 */
void game_run(const Mode mode);

/**
 * @brief Automatic turn in case the round time is over
 */
void game_onTimeOut();

/**
 * @brief Initializes several things at the game start
 */
static void init(const Mode mode);

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

/**
 * @brief Prints the winner and statistics
 * @param [in] winner
 */
static void printEndScreen(Player winner);

#endif// GAME_H
