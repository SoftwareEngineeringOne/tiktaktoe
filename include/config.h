/*! !! This file has been generated automatically, any changes may be overridden !! !*/
/**
 * @file config.h.in
 *
 * @brief Configuration file for the Tic-Tac-Toe game.
 *
 * @details
 * This file contains preprocessor definitions and configuration macros
 * for the Tic-Tac-Toe game.
 *
 * @note
 * This file has been generated automatically by CMake. Do not edit it manually.
 * The unprocessed file is `config.h.in`.
 *
 * @see config.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef CONFIG_H
#define CONFIG_H

/**
 * @def ENABLE_UNICODE
 * @brief Enable Unicode support.
 *
 * @details
 * If defined, the game will use Unicode characters for rendering.
 * If not defined, ASCII characters will be used instead.
 */
#define ENABLE_UNICODE

/**
 * @def ENABLE_ASCII_ART
 * @brief Enable ASCII art rendering.
 *
 * @details
 * If defined, the game will render ASCII art for visual elements.
 */
#define ENABLE_ASCII_ART

/**
 * @def CELLS_PER_ROW
 * @brief Number of cells per row in the game grid.
 *
 * @details
 * This macro defines the horizontal size of the game grid.
 */
#define CELLS_PER_ROW 4

/**
 * @def CELLS_PER_COL
 * @brief Number of cells per column in the game grid.
 *
 * @details
 * This macro defines the vertical size of the game grid.
 */
#define CELLS_PER_COL 4

/**
 * @def TICKS_PER_TURN
 * @brief Number of ticks allowed per turn.
 *
 * @details
 * This macro defines the maximum number of ticks a player has to make a move.
 */
#define TICKS_PER_TURN 20

/**
 * @def TICK_SPEED
 * @brief Speed of each tick in milliseconds.
 *
 * @details
 * This macro defines the duration of each tick in the game loop.
 */
#define TICK_SPEED 12

/**
 * @defgroup HAL Hardware Abstraction Layer
 * @{
 * This group contains all modules from the hardware abstraction layer.
 * @}
 */

/**
 * @defgroup Logic Logic Layer
 * @{
 * This group contains all modules from the logic layer.
 * @}
 */

/**
 * @defgroup Presentation Presentation Layer
 * @{
 * This group contains all modules from the presentation layer.
 * @}
 */

/**
 * @defgroup Utility
 * @{
 * This group contains all utility modules.
 * @}
 */

#endif// CONFIG_H
