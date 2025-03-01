#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>

/**
 * @brief Move cursor to the given coordinates
 * @param [in] x
 * X-Position
 * @param [in] y
 * Y-Position
 */
void cursor_moveTo(uint8_t x, uint8_t y);

/**
 * @brief TODO: ?????
 * @param num
 * @param num_buf
 * @param buf
 * @param buf_pos
 */
static void _writeNumToBuf(uint8_t num, const char *num_buf, char *buf, uint8_t *buf_pos);

#endif// CURSOR_H
