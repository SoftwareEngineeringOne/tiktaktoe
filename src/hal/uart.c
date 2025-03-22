/**
 * @file uart.c
 *
 * @brief Implements UART initialization and data transfer functions.
 *
 * @see uart.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "hal/uart.h"
#include "hal/nvic.h"
#include "hal/register_access.h"

#include <stdint.h>

void uart_init(const bool with_interrupts)
{
    // Set Flow-Control and/or Parity (see Table 288, page 156).
    // Hardware flow control: Disabled = 0 (default).
    // Parity: Exclude parity bit = 0x0 (default).
    // register_write((UART_BASE_ADDRESS + UART_CONFIG), 0); // Optional.

    // Configure GPIO Pins for RXD, TXD.
    // PSELRTS - disconnected (default).
    // register_write((UART_BASE_ADDRESS + UART_PSELRTS), 0xFFFFFFFF); // Optional.

    // Set baud rate (see Table 287 on page 156).
    // Baud115200 = 0x01D7E000.
    // register_write((UART_BASE_ADDRESS + UART_BAUDRATE), 0x01D7E000);

    // Enable UART.
    register_write(UART_BASE_ADDRESS + UART_ENABLE, 4);

    // Fire the START event for the Transmitter.
    register_write(UART_BASE_ADDRESS + UART_STARTTX, UART_TASK_START);

    // Fire the START event for the Receiver.
    register_write(UART_BASE_ADDRESS + UART_STARTRX, UART_TASK_START);

    if(with_interrupts)
    {
        // Enable Interrupt for RXDRDY.
        register_write(UART_BASE_ADDRESS | UART_INTENSET, UART_INT_RXDRDY);

        // Enable User-Interrupt from Cortex-M0 (ID2 is the UART).
        register_write(Interrupt_Set_Enable, Interrupt_ID2);
    }
}

void uart_writeByte(const uint8_t data)
{
    // Write the data to the TXD register.
    register_write(UART_BASE_ADDRESS + UART_TXD, data);

    // Wait until the data is transmitted (polling TXDRDY).
}

uint8_t uart_readByte()
{
    // Check if RXDRDY event is ready.
    const uint32_t receiveIsReady = register_read(UART_BASE_ADDRESS + UART_RXDRDY);

    if(!receiveIsReady)
    {
        // FIFO is not ready to read, return 0.
        return 0;
    }

    // Clear the RXDRDY event before reading from RXD.
    register_write(UART_BASE_ADDRESS + UART_RXDRDY, UART_EVENT_CLEAR);

    // Read and return the received byte from RXD.
    return register_read(UART_BASE_ADDRESS + UART_RXD);
}
