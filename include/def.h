/**
 * @file def.h
 *
 * @brief Contains very basic and general definitions.
 *
 * @details
 * This file defines a boolean type and constants for `true` and `false`.
 *
 * @ingroup Utility
 *
 * @see
 *  def.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef DEF_H
#define DEF_H

/**
 * @brief Boolean type definition.
 *
 * @details
 * Defines a boolean type using `char` for compatibility with C.
 */
typedef char bool;

/**
 * @def false
 * @brief Represents the boolean value `false`.
 */
#define false 0

/**
 * @def true
 * @brief Represents the boolean value `true`.
 */
#define true 1

#endif// DEF_H
