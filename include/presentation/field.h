/**
 * @file field.h
 *
 * @brief Contains constants and one function to draw the whole field.
 *
 * @details
 * This file defines constants for rendering the tic-tac-toe field, including
 * offsets, Unicode or ASCII characters for the field's borders, and the
 * `field_redraw` function to render the field.
 *
 * @ingroup Presentation
 *
 * @see field.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef FIELD_H
#define FIELD_H

#include "config.h"
#include "presentation/ascii_art.h"
#include <stddef.h>

/**
 * @def FIELD_X_OFFSET
 * @brief Horizontal offset for the field rendering.
 */
#define FIELD_X_OFFSET 1

/**
 * @def FIELD_Y_OFFSET
 * @brief Vertical offset for the field rendering, including heading lines.
 */
#define FIELD_Y_OFFSET 2 + HEADING_LINES

#ifdef ENABLE_UNICODE

#define CORNER_TOP_LEFT "╭"
#define CORNER_BOT_LEFT "╰"
#define CORNER_TOP_RIGHT "╮"
#define CORNER_BOT_RIGHT "╯"

#define T_LEFT "├"
#define T_RIGHT "┤"
#define T_TOP "┬"
#define T_BOT "┴"

#define CROSS "┼"

#define SIDE "│"
#define TOP_BOTTOM "─"
#define EMPTY " "

#define DIAGONAL_FW "╱"
#define DIAGONAL_BW "╲"
#define DIAGONAL_MID "╳"

#else

#define CORNER_TOP_LEFT "+"
#define CORNER_BOT_LEFT "+"
#define CORNER_TOP_RIGHT "+"
#define CORNER_BOT_RIGHT "+"

#define T_LEFT "+"
#define T_RIGHT "+"
#define T_TOP "+"
#define T_BOT "+"

#define CROSS "+"

#define SIDE "|"
#define TOP_BOTTOM "-"
#define EMPTY " "

#define DIAGONAL_FW "/"
#define DIAGONAL_BW "\\"
#define DIAGONAL_MID "X"
#endif

/**
 * @brief Redraw the whole 2D field.
 *
 * @details
 * This function renders the entire tic-tac-toe field, including borders
 * and empty cells, based on the current configuration.
 */
void field_redraw();

#endif// FIELD_H
