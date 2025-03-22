/**
 * @file input_buf.c
 *
 * @brief Implementation of the input buffer functions.
 *
 * @details
 * This file contains the implementation of functions for managing the input
 * buffer, including initialization, checking buffer state, and handling UART
 * input interrupts.
 *
 * @see input_buf.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "util/input_buf.h"

#include "presentation/print.h"
#include "util/error_handling.h"

volatile InputBuffer g_input_buf;

/**
 * @brief Put the next byte into the buffer.
 *
 * @details
 * This function writes a byte into the input buffer if there is space
 * available.
 *
 * @param[inout] ib InputBuffer to write to.
 * @param[in] byte Byte to write into the buffer.
 * @return False if the buffer is full, true otherwise.
 *
 * @internal
 */
static bool putIntoBuf(volatile InputBuffer *ib, const uint8_t byte);

void input_onInterrupt(const uint8_t input)
{
    if(!putIntoBuf(&g_input_buf, input))
    {
        // Triggering a hardfault is not the best way to handle this, but it is
        // better than silently dropping input.
        __asm volatile("udf #0");
    }
}

void input_init(volatile InputBuffer *ib)
{
    ib->head = 0;
    ib->tail = 0;
}

bool input_isEmpty(const volatile InputBuffer *ib)
{
    return ib->head == ib->tail;
}

bool input_isFull(const volatile InputBuffer *ib)
{
    return (ib->head + 1) % INPUT_BUF_SIZE == ib->tail;
}

bool input_getNext(volatile InputBuffer *ib, uint8_t *byte)
{
    if(input_isEmpty(ib))
    {
        return false;
    }
    *byte = ib->data[ib->tail];
    ib->tail = (ib->tail + 1) % INPUT_BUF_SIZE;
    return true;
}

static bool putIntoBuf(volatile InputBuffer *ib, const uint8_t byte)
{
    if(input_isFull(ib))
    {
        return false;
    }

    ib->data[ib->head] = byte;
    ib->head = (ib->head + 1) % INPUT_BUF_SIZE;
    return true;
}
