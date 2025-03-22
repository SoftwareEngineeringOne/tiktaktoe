/**
 * @file conversion.h
 *
 * @brief Contains several different simple and independent conversion functions.
 *
 * @details
 * This file provides utility functions for converting integers to strings or characters.
 *
 * @ingroup Utility
 *
 * @see conversion.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef CONVERSION_H
#define CONVERSION_H

#include <stddef.h>
#include <stdint.h>

#define ASCII_NUM_OFFSET 48///< Offset to convert a digit to its ASCII representation.

/**
 * @brief Converts an integer to a string.
 *
 * @details
 * Converts a given unsigned integer to its string representation and stores it in the provided
 * buffer.
 *
 * @param[in] num The integer to convert.
 * @param[out] buf The buffer to store the resulting string.
 * @param[in] buf_size The size of the buffer.
 *
 * @return 0 on success, -1 if an error occurred (e.g., buffer is NULL or too small).
 */
int8_t int_to_str(uint32_t num, char *buf, const size_t buf_size);

/**
 * @brief Converts an integer to a character.
 *
 * @details
 * Converts a single-digit integer (0-9) to its corresponding ASCII character.
 *
 * @param[in] num The integer to convert (must be between 0 and 9).
 *
 * @return The ASCII character corresponding to the input integer.
 */
char int_to_char(uint8_t num);

#endif// CONVERSION_H
