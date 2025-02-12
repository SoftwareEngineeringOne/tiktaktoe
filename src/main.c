#include "hal/random.h"
#include "hal/timer.h"
#include "hal/uart.h"
#include "presentation/print.h"
#include "presentation/field.h"

#include <stdbool.h>

static void waitRelease(void);

static void randomNumberTest(void);

static void timerTest(void);

char input_buf[256];
size_t pos = 0;
void on_rxrdy_interrupt(void) {
  uint8_t b = uart_readByte();
  if (b == '\r') {
    uart_writeByte('\n');
    print("You wrote: ");
    println(input_buf);
    pos = 0;
    return;
  } 
  input_buf[pos] = b;
  input_buf[++pos] = '\0';
  uart_writeByte(b);
}

int main(void) {
  // waitRelease();

  uart_init(true, &on_rxrdy_interrupt);
  /* uart_writeString( "Hello World!\n" ); */
  print("Hello,");
  println(" World!");

  Style style1 = {
      .fg_color = FG_GREEN,
      .bg_color = BG_YELLOW,
      .font_style = BOLD,
  };

  Style style2 = {
      .fg_color = FG_MAGENTA,
      .bg_color = DEFAULT,
      .font_style = DEFAULT,
  };

  clear_console();
  char buf[12];
  int_to_str(0, buf, sizeof(buf));
  print("Zero: ");
  char output[256];
  println_styled(buf, &style1);
  print(RESET);
  char buf2[12];
  print("Max: ");
  int_to_str(UINT32_MAX, buf2, sizeof(buf2));
  println_styled(buf2, &style2);

  clear_console();
  output_drawField();
}

static void waitRelease(void) {
  bool start = false;
  while (!start) {
  }
}

static void randomNumberTest(void) {
  // Initialize the Module
  rng_init();

  while (true) {
    uint8_t randomNumber = rng_getRandomValue_waiting();

    //uart_writeNumber(randomNumber);
    //uart_writeString("\n");
  }
}

static void timerTest(void) {
  // timer_init( TIMER0 );

  timer_init_detailed(TIMER0, 15, TIMER_MODE_TIMER, TIMER_BIT_MODE_32);

  timer_captureCompareSet(TIMER0, CC0, 2000, true);

  timer_start(TIMER0);

  while (true) {
    timer_capture(TIMER0, CC1);

    uint32_t captureValue = timer_captureCompareGet(TIMER0, CC1);

    // uart_writeNumber( captureValue );
  }
}
