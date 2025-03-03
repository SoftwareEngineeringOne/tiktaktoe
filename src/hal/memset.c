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
