/**
 * @file conversion.c
 *
 * @brief Implementation of utility functions for integer-to-string and integer-to-character
 * conversions.
 *
 * @see conversion.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "util/conversion.h"

#include <stddef.h>
#include <stdint.h>

int8_t int_to_str(uint32_t num, char *buf, const size_t buf_size)
{
    if(buf == NULL || buf_size == 0)
    {
        return -1;
    }

    if(num < 10)
    {
        buf[0] = num + ASCII_NUM_OFFSET;
        buf[1] = '\0';
        return 0;
    }

    size_t i = 0;
    do
    {
        if(i > buf_size)
        {
            return -1;
        }
        buf[i++] = num % 10 + '0';
        num /= 10;
    } while(num);

    for(size_t j = 0, k = i - 1; j < k; j++, k--)
    {
        const char temp = buf[j];
        buf[j] = buf[k];
        buf[k] = temp;
    }

    return 0;
}

char int_to_char(uint8_t num)
{
    while(num >= 10)
    {
        num -= 10;
    }

    return num + ASCII_NUM_OFFSET;
}
