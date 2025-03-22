/**
 * @file style.h
 *
 * @brief Contains several constants to simplify the styling of output.
 *
 * @details
 * This file defines macros for terminal styling, a `Style` struct for grouping
 * style attributes, and several predefined style constants.
 *
 * @ingroup Presentation
 *
 * @see style.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef STYLE_H
#define STYLE_H

/**
 * @brief Represents a style with foreground color, background color, and font style.
 *
 * @details
 * This struct is used to define a combination of terminal styling attributes.
 */
typedef struct
{
        char *fg_color;  ///< Foreground color escape sequence.
        char *bg_color;  ///< Background color escape sequence.
        char *font_style;///< Font style escape sequence.
} Style;

#define CLEAR_SCREEN "\e[1;1H\e[2J"///< Escape sequence to clear the terminal screen.

#define DEFAULT ""///< Default style with no attributes.

#define RESET "\e[0m"///< Escape sequence to reset all styling attributes.

#define FG_RED "\e[31m"///< Escape sequence to set the foreground color to red.

#define FG_GREEN "\e[32m"///< Escape sequence to set the foreground color to green.

#define FG_YELLOW "\e[33m"///< Escape sequence to set the foreground color to yellow.

#define FG_BLUE "\e[34m"///< Escape sequence to set the foreground color to blue.

#define FG_MAGENTA "\e[35m"///< Escape sequence to set the foreground color to magenta.

#define BG_GREEN "\e[42m"///< Escape sequence to set the background color to green.

#define BG_YELLOW "\e[43m"///< Escape sequence to set the background color to yellow.

#define BOLD "\e[1m"///< Escape sequence to apply bold font style.

#define DIM "\e[2m"///< Escape sequence to apply dim font style.

#define ITALIC "\e[3m"///< Escape sequence to apply italic font style.

#define INVERSE "\e[7m"///< Escape sequence to apply inverse font style.

#define HIDDEN "\e[8m"///< Escape sequence to apply hidden font style.

#define HIDE_CURSOR "\e[?25l"///< Escape sequence to hide the terminal cursor.

#define SHOW_CURSOR "\e[?25h"///< Escape sequence to show the terminal cursor.

#define ERASE_LINE_FROM_CURSOR "\e[0K"///< Escape sequence to erase the line from the cursor.

/**
 * @brief Default style with bold font.
 */
extern const Style DEFAULT_BOLD;

/**
 * @brief Default style with italic font.
 */
extern const Style DEFAULT_ITALIC;

/**
 * @brief Default style with dim font.
 */
extern const Style DEFAULT_DIM;

/**
 * @brief Style combining bold and dim font.
 */
extern const Style BOLD_DIM;

/**
 * @brief Style combining italic and dim font.
 */
extern const Style ITALIC_DIM;

/**
 * @brief Default style for circles with magenta foreground.
 */
extern const Style DEFAULT_CIRCLE;

/**
 * @brief Bold style for circles with magenta foreground.
 */
extern const Style BOLD_CIRCLE;

/**
 * @brief Default style for crosses with green foreground.
 */
extern const Style DEFAULT_CROSS;

/**
 * @brief Bold style for crosses with green foreground.
 */
extern const Style BOLD_CROSS;

/**
 * @brief Style for headings with blue foreground and bold font.
 */
extern const Style HEADING_STYLE;

#endif// STYLE_H
