#ifndef CURSOR_H

#include <stdint.h>

void cursor_moveTo(uint8_t x, uint8_t y);

static void writeNumToBuf(uint8_t num, char *num_buf, char *buf, uint8_t *buf_pos);

#endif// !CURSOR_H
