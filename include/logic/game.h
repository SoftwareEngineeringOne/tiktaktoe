/**
 * @file game.h
 *
 * @brief Contains the game logic
 *
 * @details
 * This file contains the core logic for the TikTakToe game, including
 * game state management, player handling, and cell state tracking.
 *
 * @ingroup Logic
 *
 * @see game.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef GAME_H
#define GAME_H

#include "presentation/field.h"
#include "util/input_buf.h"

#include <stdint.h>

#define REMAINING_TIME (TICKS_PER_TURN - g_timer.ticks_turn)///< Remaining time for the current turn
#define FIRST_ROUND 1///< Constant representing the first round of the game

/**
 * @brief Possible game modes
 *
 * The game can be played in Player vs Computer (PVE) or Player vs Player (PVP) mode.
 */
typedef enum
{
    PVE,///< Player vs Computer
    PVP,///< Player vs Player
} Mode;

/**
 * @brief Enum describing a player
 *
 * Represents the two players (Circle and Cross) and an unmarked state (None).
 */
typedef enum
{
    Circle = 0,///< Player Circle
    Cross = 1, ///< Player Cross
    None = 2,  ///< No player (unmarked)
} Player;

/**
 * @brief One cell on the field
 *
 * Contains coordinates and information about which player marked the cell.
 */
typedef struct
{
        uint16_t col;    ///< Column index of the cell
        uint16_t row;    ///< Row index of the cell
        Player marked_by;///< Player who marked the cell
} Cell;

/**
 * @brief The current game state
 *
 * Contains important game information and several metrics for tracking the game's progress.
 *
 * @note Some of the fields are only calculated once the game is over.
 */
typedef struct
{
        Player winner;                 ///< None if tie or game not over
        Mode mode;                     ///< Current game mode
        volatile uint8_t round;        ///< Current round number
        volatile uint8_t fields_marked;///< Number of fields marked so far
        Player current_player;         ///< Player whose turn it is

        // Relevant for summary
        uint32_t total_ticks;  ///< Total ticks elapsed in the game
        uint32_t average_ticks;///< Average ticks per turn

        uint32_t cross_total_ticks;  ///< Total ticks for Player Cross
        uint32_t cross_average_ticks;///< Average ticks for Player Cross

        uint32_t circle_total_ticks;  ///< Total ticks for Player Circle
        uint32_t circle_average_ticks;///< Average ticks for Player Circle
} GameState;

/**
 * @brief The current state of the cells
 *
 * Tracks all cells on the field and pointers to specific cells for easier access.
 */
typedef struct
{
        Cell all[CELLS_PER_COL][CELLS_PER_ROW];///< All cells of the match
        Cell *selected;                        ///< Pointer to the currently selected cell
        Cell *last_cross;                      ///< Pointer to the cell last marked by Cross
        Cell *last_circle;                     ///< Pointer to the last cell marked by Circle
} CellState;

/**
 * @brief Start the main game
 *
 * @details
 * Initializes the game and enters the main game loop.
 *
 * @param[in] mode Which mode the game should be played in.
 */
void game_run(const Mode mode);

/**
 * @brief Automatically end a turn in case the turn time is over
 *
 * @see time_onInterrupt
 */
void game_onTimeOut();

/**
 * @brief Finish the current turn
 *
 * @details
 * Updates the game state and switches to the next player or round.
 */
void game_endTurn();

#endif// GAME_H
