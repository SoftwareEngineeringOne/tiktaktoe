#include "hal_high/input_buf.h"

#include "presentation/print.h"

volatile InputBuffer input_buf;

void input_onInterrupt(const uint8_t input)
{
    if(!putIntoBuf(&input_buf, input))
    {
        print("INPUT BUFFER OVERFLOW");
    }
}

void input_init(volatile InputBuffer *ib)
{
    ib->head = 0;
    ib->tail = 0;
}

bool input_isEmpty(volatile InputBuffer *ib)
{
    return ib->head == ib->tail;
}

bool input_isFull(volatile InputBuffer *ib)
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

bool putIntoBuf(volatile InputBuffer *ib, const uint8_t byte)
{
    if(input_isFull(ib))
    {
        return false;
    }

    ib->data[ib->head] = byte;
    ib->head = (ib->head + 1) % INPUT_BUF_SIZE;
    return true;
}