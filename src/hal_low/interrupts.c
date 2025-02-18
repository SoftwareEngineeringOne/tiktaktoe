#include "hal_low/interrupts.h"

#include "logic/game.h"
#include "hal_high/input_buf.h"
#include "hal_low/nvic.h"
#include "hal_low/register_access.h"
#include "hal_low/timer.h"
#include "hal_low/uart.h"
#include "logic/time.h"

#include <stddef.h>

/**
 * UART interrupt handler
 */
void Interrupt2_Handler(void)
{
    input_onInterrupt(uart_readByte());
    register_write(Interrupt_ICPR, Interrupt_ID2);
}

/**
 * Timer interrupt handler
 */
void Interrupt8_Handler(void)
{
    register_write(TIMER0_BASE_ADDRESS | TIMER_COMPARE_0, 0);
    register_write(Interrupt_ICPR, Interrupt_ID8);
    time_onInterrupt();
}

void default_handler()
{
    uart_writeByte('F');
    for(;;) {}
}
