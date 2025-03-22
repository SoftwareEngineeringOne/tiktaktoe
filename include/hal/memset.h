/**
 * @file memset.h
 *
 * @brief Header file for a simple implementation of memset
 *
 * @ingroup HAL
 *
 * @see memset.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef MEMSET_H
#define MEMSET_H

#include <stddef.h>

/**
 * @brief Simple implementation of memset
 *
 * @details
 * Sets the first **n** bytes of the block of memory
 * pointed to by **ptr** to the specified value **x**
 *
 * @param [in] ptr Pointer to the block of memory to fill
 * @param [in] x Value to be set.
 * @param [in] n Number of bytes to be set to the value
 *
 * @return A pointer to the memory area
 *
 * @warning
 * While x is passed as an int, it is cast to a uint8_t (char)
 * before being stored in the memory area.
 */
void *memset(void *ptr, int x, size_t n);

#endif// MEMSET_H
