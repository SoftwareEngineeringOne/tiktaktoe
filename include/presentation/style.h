/**
 * @file 
 *
 * @author 
 *
 * @date 
 *
 * @brief 
 *
 * @see 
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef STYLE_H
#define STYLE_H

#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define DEFAULT ""
#define RESET "\e[0m"

#define FG_RED "\e[31m"
#define FG_GREEN "\e[32m"
#define FG_YELLOW "\e[33m"
#define FG_MAGENTA "\e[35m"

#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"

#define BOLD "\e[1m"
#define ITALIC "\e[3m"
#define INVERSE "\e[7m"

#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

#define ERASE_LINE_FROM_CURSOR "\e[0K"

#endif //STYLE_H
