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
 *
 */
#include "presentation/print.h"

#include "hal_low/uart.h"
#include "presentation/style.h"
#include "util/conversion.h"


void print_clearConsole()
{
    print(CLEAR_SCREEN);
}

void print(const char *string)
{
    while(*string != '\0')
    {
        uart_writeByte(*string);
        string++;
    }
}

void print_int(const uint32_t number)
{
    char buf[11] = {0};
    int_to_str(number, buf, 11);
    print(buf);
}

void println(const char *string)
{
    print(string);
    uart_writeByte(LINE_SEPERATOR);
}

void println_int(const uint32_t number)
{
    print_int(number);
    uart_writeByte(LINE_SEPERATOR);
}

void print_styled(const char *string, const Style *style)
{
    printStyle(style);
    print(string);
    print(RESET);
}

void println_styled(const char *string, const Style *style)
{
    print_styled(string, style);
    uart_writeByte(LINE_SEPERATOR);
}

void printStyle(const Style *style)
{
    // assuming the if checks are cheaper then printing if NULL
    if(style->fg_color != NULL)
    {
        print(style->fg_color);
    }
    if(style->bg_color != NULL)
    {
        print(style->bg_color);
    }
    if(style->font_style != NULL)
    {
        print(style->font_style);
    }
}
