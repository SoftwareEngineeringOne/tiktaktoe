/**
 * @file math.h
 *
 * @brief Contains several different simple and independent math functions
 *
 * @details
 * This file provides utility macros for basic mathematical operations, such as
 * finding the minimum or maximum of two values.
 *
 * @ingroup Utility
 *
 * @see math.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef MATH_H
#define MATH_H

/**
 * @def min(a, b)
 * @brief Get the minimum of two values.
 *
 * @details
 * This macro evaluates to the smaller of the two provided values.
 *
 * @param[in] a The first value.
 * @param[in] b The second value.
 *
 * @return The smaller of the two values.
 *
 * @note This macro does not perform type checking and may evaluate its arguments multiple times.
 */
#define min(a, b) a < b ? a : b

/**
 * @def max(a, b)
 * @brief Get the maximum of two values.
 *
 * @details
 * This macro evaluates to the larger of the two provided values.
 *
 * @param[in] a The first value.
 * @param[in] b The second value.
 *
 * @return The larger of the two values.
 *
 * @note This macro does not perform type checking and may evaluate its arguments multiple times.
 */
#define max(a, b) a > b ? a : b

#endif// MATH_H
