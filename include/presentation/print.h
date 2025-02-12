#ifndef PRINT_H
#define PRINT_H

#include <stdint.h>
#include <stddef.h>

#define LINE_SEPERATOR '\n'

#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define DEFAULT ""
#define RESET "\e[0m"

#define FG_GREEN "\e[32m"
#define FG_MAGENTA "\e[35m"

#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"

#define BOLD "\e[1m"

typedef struct {
    char* fg_color;
    char* bg_color;
    char* font_style;
} Style;

void clear_console();
void print(const char* string);
void println(const char* string);

void print_styled(const char* string, const Style* style);
void println_styled(const char* string, const Style* style);

int8_t int_to_str(uint32_t num, char* buf, size_t buf_size);

#endif // !PRINT_H
