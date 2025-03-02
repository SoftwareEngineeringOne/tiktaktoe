/**
 * @file
 *
 * @author
 *
 * @date
 *
 * @brief
 *
 * @see
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
#ifndef INPUT_BUF_H
#define INPUT_BUF_H

#include "def.h"

#include <stdint.h>

#define INPUT_BUF_SIZE 128

/**
 * @brief RingBuffer for fixed memory footprint
 */
typedef struct
{
        uint8_t data[INPUT_BUF_SIZE];
        volatile uint16_t head;
        volatile uint16_t tail;
} InputBuffer;

extern volatile InputBuffer g_input_buf;

/**
 * @brief Function to call in case of UART input interrupt
 * @param[in] input
 * Pure input from UART
 */
void input_onInterrupt(uint8_t input);

/**
 * @brief Initialize the given InputBuffer
 * @param[inout] ib
 * InputBuffer
 */
void input_init(volatile InputBuffer *ib);

/**
 * @brief Check if the buffer is empty
 * @param[in] ib
 * InputBuffer
 * @return True if empty
 */
bool input_isEmpty(const volatile InputBuffer *ib);

/**
 * @brief Check if the buffer is full
 * @param[in] ib
 * InputBuffer
 * @return True if full
 */
bool input_isFull(const volatile InputBuffer *ib);

/**
 * @brief Get the next byte from the buffer
 * @param[inout] ib
 * InputBuffer
 * @param[out] byte
 * Next Byte
 * @return False if empty
 */
bool input_getNext(volatile InputBuffer *ib, uint8_t *byte);

#endif// INPUT_BUF_H
