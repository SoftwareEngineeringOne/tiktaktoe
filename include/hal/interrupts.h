/**
 * @file interrupts.h
 *
 * @brief Contains the relevant interrupt handlers
 *
 * @details
 * This file declares the interrupt handler functions for UART and Timer interrupts.
 * These handlers are triggered by specific hardware events and perform the necessary
 * actions to handle the interrupts.
 *
 * @ingroup HAL
 *
 * @see interrupts.c
 *
 * @note
 * Ensure the corresponding peripherals are properly configured before enabling these interrupts.
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

/**
 * @brief UART interrupt handler
 *
 * @details
 * This function is triggered when a UART interrupt occurs. It reads a byte
 * from the UART peripheral and processes it using the input buffer. The
 * interrupt pending bit is cleared after handling the interrupt.
 *
 * @see uart_readByte
 */
void Interrupt2_Handler();

/**
 * @brief Timer interrupt handler
 *
 * @details
 * This function is triggered when a timer interrupt occurs. It resets the
 * timer compare register and clears the interrupt pending bit. Additionally,
 * it notifies the time module about the interrupt event.
 *
 * @see time_onInterrupt
 */
void Interrupt8_Handler();

#endif// INTERRUPTS_H
