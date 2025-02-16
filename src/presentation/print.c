#include "presentation/print.h"

#include "hal_low/uart.h"

#include <stdint.h>
#include <stddef.h>

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

int8_t int_to_str(uint32_t num, char *buf, const size_t buf_size)
{
    if(buf == NULL || buf_size == 0)
    {
        return -1;
    }

    if(num < 10)
    {
        buf[0] = num + ASCII_NUM_OFFSET;
        buf[1] = '\0';
        return 0;
    }

    size_t i = 0;
    do
    {
        if(i > buf_size)
        {
            return -1;
        }
        buf[i++] = num % 10 + '0';
        num /= 10;
    } while(num);

    for(size_t j = 0, k = i - 1; j < k; j++, k--)
    {
        const char temp = buf[j];
        buf[j] = buf[k];
        buf[k] = temp;
    }

    return 0;
}

char int_to_char(uint8_t num)
{
    while(num >= 10)
    {
        num -= 10;
    }

    return num + ASCII_NUM_OFFSET;
}
