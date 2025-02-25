#include "presentation/print.h"

#include "hal_low/uart.h"
#include "hal_low/nvic.h"
#include "util/conversion.h"

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

void print_int(const uint32_t number)
{
    static char string[11];
    int_to_str(number, string, 11);
    print(string);
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

void entry_c(void);
void print_hardFault()
{
    clearConsole();
    println("HardFault bitch");
    println("Press any key to continue...");
    while(uart_readByte() == 0)
    {
        __WFI();
    }
    entry_c();
}
