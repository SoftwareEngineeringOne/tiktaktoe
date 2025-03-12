/**
 * @file memset.h
 *
 * @brief Contains a simple implementation of memset
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
 * @param [in] x Value to be set. The value is passed as an int, but the function fills the block of
 * memory using the unsigned char conversion of this value
 * @param [in] n Number of bytes to be set to the value
 *
 * @return A pointer to the memory area
 */
void *memset(void *ptr, int x, size_t n);

#endif// MEMSET_H
