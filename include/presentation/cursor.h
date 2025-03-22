/**
 * @file cursor.h
 *
 * @brief Contains functions for moving the presentation of the cursor.
 *
 * @details
 * This file provides the interface for cursor movement in the presentation layer.
 *
 * @ingroup Presentation
 *
 * @see cursor.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>

/**
 * @brief Move the cursor to the given coordinates.
 *
 * @details
 * This function generates an escape sequence to move the cursor to the specified
 * (x, y) position on the terminal.
 *
 * @param[in] x X-coordinate of the cursor position.
 * @param[in] y Y-coordinate of the cursor position.
 *
 * @note
 * This function can be improved by using new functions found in the conversion module
 * and directly writing the string representation of the number to the target buffer.
 */
void cursor_moveTo(uint8_t x, uint8_t y);

#endif// CURSOR_H
