/**
 * @file memset.h
 *
 * @author Thomas Vogt
 * @author Sven Reis
 *
 * @brief Contains memset
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
 * @brief Sets the first n bytes of the block of memory pointed by ptr to the specified value
 *
 * @param [in] ptr Pointer to the block of memory to fill
 * @param [in] x Value to be set. The value is passed as an int, but the function fills the block of
 * memory using the unsigned char conversion of this value
 * @param [in] n Number of bytes to be set to the value
 *
 * @return A pointer to the memory area ptr
 */
void *memset(void *ptr, int x, size_t n);

#endif// MEMSET_H
