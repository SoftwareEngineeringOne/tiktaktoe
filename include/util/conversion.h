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
#ifndef CONVERSION_H
#define CONVERSION_H

#include <stddef.h>
#include <stdint.h>

#define ASCII_NUM_OFFSET 48

/**
 * Converts an integer to a string
 * @param [in] num
 * Integer to convert
 * @param [out] buf
 * String
 * @param [in] buf_size
 * Size of the string
 * @return TODO ??False??? when no error occurred
 */
int8_t int_to_str(uint32_t num, char *buf, const size_t buf_size);

/**
 * Converts an integer to a character
 * @param num
 * Integer to convert
 * @return Suitable character
 */
char int_to_char(uint8_t num);

#endif// CONVERSION_H
