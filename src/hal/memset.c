/**
 * @file memset.c
 *
 * @brief Implementation of a simple memset function
 *
 * @see memset.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "hal/memset.h"

#include <stdint.h>

void *memset(void *ptr, const int x, size_t n)
{
    uint8_t *p = ptr;
    while(n--)
    {
        *p++ = (uint8_t)x;
    }
    return ptr;
}
