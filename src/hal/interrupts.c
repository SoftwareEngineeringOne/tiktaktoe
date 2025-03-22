/**
 * @file interrupts.c
 *
 * @brief Implements the interrupt handlers for UART and Timer interrupts.
 *
 * @see interrupts.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "hal/interrupts.h"

#include "hal/nvic.h"
#include "hal/register_access.h"
#include "hal/timer.h"
#include "hal/uart.h"
#include "logic/time.h"
#include "util/input_buf.h"

void Interrupt2_Handler()
{
    input_onInterrupt(uart_readByte());
    register_write(Interrupt_ICPR, Interrupt_ID2);
}

void Interrupt8_Handler()
{
    register_write(TIMER0_BASE_ADDRESS | TIMER_COMPARE_0, 0);
    register_write(Interrupt_ICPR, Interrupt_ID8);
    time_onInterrupt();
}
