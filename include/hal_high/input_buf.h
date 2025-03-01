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

extern volatile InputBuffer input_buf;

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
bool input_isEmpty(volatile InputBuffer *ib);

/**
 * @brief Check if the buffer is full
 * @param[in] ib
 * InputBuffer
 * @return True if full
 */
bool input_isFull(volatile InputBuffer *ib);

/**
 * @brief Get the next byte from the buffer
 * @param[inout] ib
 * InputBuffer
 * @param[out] byte
 * Next Byte
 * @return False if empty
 */
bool input_getNext(volatile InputBuffer *ib, uint8_t *byte);

/**
 * @brief Put the next byte into the buffer
 * @param[inout] ib
 * InputBuffer
 * @param[out] byte
 * Next Byte
 * @return False if full
 */
static bool _putIntoBuf(volatile InputBuffer *ib, uint8_t byte);

#endif// INPUT_BUF_H
