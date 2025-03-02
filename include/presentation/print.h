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
#ifndef PRINT_H
#define PRINT_H

#include "presentation/style.h"
#include <stdint.h>

#define LINE_SEPERATOR '\n'

/**
 * @brief Clear the whole terminal
 */
void print_clearConsole();

/**
 * @brief Prints the given string
 * @param [in] string
 */
void print(const char *string);

/**
 * @brief Prints the given integer
 * @param [in] number
 */
void print_int(const uint32_t number);

/**
 * @brief Prints the given string with a new line character
 * @param [in] string
 */
void println(const char *string);

/**
 * @brief Prints the given integer with a new line character
 * @param [in] number
 */
void println_int(const uint32_t number);

/**
 * @brief Prints the given string with a predefined style
 * @param [in] string
 * @param [in] style
 */
void print_styled(const char *string, const Style *style);

/**
 * @brief Prints the given string with a predefined style and a new line character
 * @param [in] string
 * @param [in] style
 */
void println_styled(const char *string, const Style *style);

void printStyle(const Style *style);

void print_hardFault();

#endif// PRINT_H
