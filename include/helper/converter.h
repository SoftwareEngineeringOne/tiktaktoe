#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdint.h>
#include <stddef.h>

#define ASCII_NUM_OFFSET 48

/**
 * Converts an integer to a string
 * @param [in] num
 * Integer to convert
 * @param [out] buf
 * String
 * @param [in] buf_size
 * Size of the string
 * @return False when no error occured
 */
int8_t int_to_str(uint32_t num, char *buf, const size_t buf_size);

/**
 * Converts an integer to a character
 * @param num
 * Integer to convert
 * @return Suitable character
 */
char int_to_char(uint8_t num);

#endif// CONVERTER_H