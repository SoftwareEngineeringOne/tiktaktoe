#include "presentation/print.h"

#include "hal_low/uart.h"



void clearConsole()
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
void println(const char *string)
{
    print(string);
    uart_writeByte(LINE_SEPERATOR);
}

void printStyled(const char *string, const Style *style)
{
    print(style->fg_color);
    print(style->bg_color);
    print(style->font_style);
    print(string);
    print(RESET);
}

void printlnStyled(const char *string, const Style *style)
{
    printStyled(string, style);
    uart_writeByte(LINE_SEPERATOR);
}
