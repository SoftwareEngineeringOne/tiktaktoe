/**
 * @file print.h
 *
 * @brief Contains several different high level functions for printing to UART
 *
 * @details
 * This file contains functions for printing strings, integers, and styled text
 * to the UART interface. It also includes utility functions for clearing the
 * console.
 *
 * @ingroup Presentation
 *
 * @see print.c
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
 * @param [in] string The string to print
 */
void print(const char *string);

/**
 * @brief Prints the given integer
 * @param [in] number The integer to print
 */
void print_int(const uint32_t number);

/**
 * @brief Prints the given string with a new line character
 * @param [in] string The string to print
 */
void println(const char *string);

/**
 * @brief Prints the given integer with a new line character
 * @param [in] number The integer to print
 */
void println_int(const uint32_t number);

/**
 * @brief Prints the given string with a predefined style
 * @param [in] string The string to print
 * @param [in] style The style to apply
 */
void print_styled(const char *string, const Style *style);

/**
 * @brief Prints the given string with a predefined style and a new line character
 * @param [in] string The string to print
 * @param [in] style The style to apply
 */
void println_styled(const char *string, const Style *style);

/**
 * @brief Prints the given style attributes
 * @param [in] style The style to print
 */
void print_style(const Style *style);

#endif// PRINT_H
