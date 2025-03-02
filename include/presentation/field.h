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
 */
#ifndef FIELD_H
#define FIELD_H

#include <stddef.h>
#include "config.h"

#define FIELD_X_OFFSET 1
#define FIELD_Y_OFFSET 2


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
 * @brief Redraw the whole 2D field
 **/
void field_redraw();


#endif// FIELD_H
