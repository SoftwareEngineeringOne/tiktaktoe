#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdint.h>
#include <stddef.h>

#define ASCII_NUM_OFFSET 48

int8_t int_to_str(uint32_t num, char *buf, const size_t buf_size);

char int_to_char(uint8_t num);

#endif// CONVERTER_H