#include "presentation/print.h"
#include "hal/uart.h"
#include <stdint.h>
#include <stddef.h>

void clear_console() {
  print(CLEAR_SCREEN);
}
void print(const char *string) {
  while (*string != '\0') {
    uart_writeByte(*string);
    string++;
  }
}
void println(const char *string) {
  print(string);
  uart_writeByte(LINE_SEPERATOR);
}

void print_styled(const char* string, const Style* style) {
  print(style->fg_color);
  print(style->bg_color);
  print(style->font_style);
  print(string);
  print(RESET);
}

void println_styled(const char* string, const Style* style) {
  print_styled(string, style);
  uart_writeByte(LINE_SEPERATOR);
}

int8_t int_to_str(uint32_t num, char* buf, size_t buf_size) {
  if (buf == NULL || buf_size == 0) {
    return -1;
  }

  size_t i = 0;

  char buf2[12];
  do {
    if(i > buf_size) {
      return -1;
    }
    buf[i++] = (num % 10) + '0';
    num /= 10;
  } while (num);

  for (int j = 0, k = i - 1; j < k; j++, k--) {
    char temp = buf[j];
    buf[j] = buf[k];
    buf[k] = temp;
  }

  return 0;
}
