/**
 * @file input_buf.h
 *
 * @brief Contains everything for the input buffer.
 *
 * @details
 * This file contains the definition of the InputBuffer struct and declarations
 * of functions for managing the input buffer, including initialization, checking
 * buffer state, and handling UART input interrupts.
 *
 * @ingroup Utility
 *
 * @see input_buf.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INPUT_BUF_H
#define INPUT_BUF_H

#include "def.h"

#include <stdint.h>

#define INPUT_BUF_SIZE 128///< Size of the input buffer

/**
 * @brief RingBuffer for fixed memory footprint.
 *
 * @details
 * This struct represents a ring buffer with a fixed size, used for storing
 * input data in a circular manner.
 */
typedef struct
{
        uint8_t data[INPUT_BUF_SIZE];///< Buffer data storage
        volatile uint16_t head;      ///< Index of the head (write position)
        volatile uint16_t tail;      ///< Index of the tail (read position)
} InputBuffer;

extern volatile InputBuffer g_input_buf;///< Global input buffer instance

/**
 * @brief Function to call in case of UART input interrupt.
 *
 * @param[in] input Pure input from UART.
 */
void input_onInterrupt(uint8_t input);

/**
 * @brief Initialize the given InputBuffer.
 *
 * @param[inout] ib InputBuffer to initialize.
 */
void input_init(volatile InputBuffer *ib);

/**
 * @brief Check if the buffer is empty.
 *
 * @param[in] ib InputBuffer to check.
 * @return True if the buffer is empty, false otherwise.
 */
bool input_isEmpty(const volatile InputBuffer *ib);

/**
 * @brief Check if the buffer is full.
 *
 * @param[in] ib InputBuffer to check.
 * @return True if the buffer is full, false otherwise.
 */
bool input_isFull(const volatile InputBuffer *ib);

/**
 * @brief Get the next byte from the buffer.
 *
 * @param[inout] ib InputBuffer to read from.
 * @param[out] byte Pointer to store the next byte.
 * @return False if the buffer is empty, true otherwise.
 */
bool input_getNext(volatile InputBuffer *ib, uint8_t *byte);

#endif// INPUT_BUF_H
