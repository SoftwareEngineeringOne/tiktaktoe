#ifndef INPUT_BUF_H
#define INPUT_BUF_H

#include "def.h"
#include <stdint.h>

#define INPUT_BUF_SIZE 128

// RingBuffer for fixed memory footprint
typedef struct
{
        uint8_t data[INPUT_BUF_SIZE];
        volatile uint16_t head;
        volatile uint16_t tail;
} InputBuffer;

extern volatile InputBuffer input_buf;

void input_onInterrupt(uint8_t input);

void input_init(volatile InputBuffer *ib);

bool input_isEmpty(volatile InputBuffer *ib);

bool input_isFull(volatile InputBuffer *ib);

bool input_getNext(volatile InputBuffer *ib, uint8_t *byte);

static bool putIntoBuf(volatile InputBuffer *ib, uint8_t byte);

#endif// INPUT_BUF_H
