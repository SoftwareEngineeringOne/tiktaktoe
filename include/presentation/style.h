/**
 * @file style.h
 *
 * @brief Contains several constants to simplify the styling of output
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef STYLE_H
#define STYLE_H

typedef struct
{
        char *fg_color;
        char *bg_color;
        char *font_style;
} Style;

#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define DEFAULT ""
#define RESET "\e[0m"

#define FG_RED "\e[31m"
#define FG_GREEN "\e[32m"
#define FG_YELLOW "\e[33m"
#define FG_BLUE "\e[34m"
#define FG_MAGENTA "\e[35m"

#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"

#define BOLD "\e[1m"
#define DIM "\e[2m"
#define ITALIC "\e[3m"
#define INVERSE "\e[7m"
#define HIDDEN "\e[8m"

#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

#define ERASE_LINE_FROM_CURSOR "\e[0K"

extern const Style DEFAULT_BOLD;
extern const Style DEFAULT_ITALIC;
extern const Style DEFAULT_DIM;


extern const Style BOLD_DIM;
extern const Style ITALIC_DIM;

extern const Style DEFAULT_CIRCLE;
extern const Style BOLD_CIRCLE;

extern const Style DEFAULT_CROSS;
extern const Style BOLD_CROSS;

extern const Style HEADING_STYLE;

#endif// STYLE_H
