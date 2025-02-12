#include "hal/interrupts.h"

#include "hal/register_access.h"
#include "hal/uart.h"
#include "hal/nvic.h"

#include <stddef.h>
#include <hal/timer.h>

interrupt_function interrupt2 = &default_handler;

void Interrupt2_Handler(void) {
  if(interrupt2 != NULL) {
    interrupt2();
  }

  register_write(UART_BASE_ADDRESS | UART_RXDRDY, 0);
  register_write(Interrupt_ICPR, Interrupt_ID2);
}

void Interrupt8_Handler(void)
{
  register_write( TIMER0_BASE_ADDRESS | TIMER_COMPARE_0, 0 );
  register_write( Interrupt_ICPR, Interrupt_ID8 );
}

void default_handler() {
  uart_writeByte('F');
  for(;;) {

  }
}
