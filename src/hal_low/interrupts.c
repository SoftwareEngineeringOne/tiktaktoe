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
#include "hal_low/interrupts.h"

#include "hal_high/input_buf.h"
#include "hal_low/nvic.h"
#include "hal_low/register_access.h"
#include "hal_low/timer.h"
#include "hal_low/uart.h"
#include "logic/time.h"

void Interrupt2_Handler(void)
{
    input_onInterrupt(uart_readByte());
    register_write(Interrupt_ICPR, Interrupt_ID2);
}

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
