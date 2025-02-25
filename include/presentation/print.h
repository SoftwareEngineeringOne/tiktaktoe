#ifndef PRINT_H
#define PRINT_H

#define LINE_SEPERATOR '\n'

#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define DEFAULT ""
#define RESET "\e[0m"

#define FG_GREEN "\e[32m"
#define FG_MAGENTA "\e[35m"

#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"

#define BOLD "\e[1m"

#define INVERSE "\e[7m"

#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

#define ERASE_LINE_FROM_CURSOR "\e[0K"

typedef struct
{
        char *fg_color;
        char *bg_color;
        char *font_style;
} Style;

/**
 * @brief Clear the whole terminal
 */
void clearConsole();

/**
 * @brief Prints the given string
 * @param [in] string
 */
void print(const char *string);

/**
 * @brief Prints the given string with a new line character
 * @param [in] string
 */
void println(const char *string);

/**
 * @brief Prints the given string with a predefined style
 * @param [in] string
 * @param [in] style
 */
void printStyled(const char *string, const Style *style);

/**
 * @brief Prints the given string with a predefined style and a new line character
 * @param [in] string
 * @param [in] style
 */
void printlnStyled(const char *string, const Style *style);

void print_hardFault();

#endif// PRINT_H
