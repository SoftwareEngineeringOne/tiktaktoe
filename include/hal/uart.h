/**
 * @file uart.h
 *
 * @brief Contains UART constants and abstraction functions
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef UART_H
#define UART_H

#include "def.h"
#include <stdint.h>

// Base Address (Instance)
#define UART_BASE_ADDRESS 0x40002000

// Register Offsets (from Table 275, page 154)
// Tasks:
#define UART_STARTRX 0x000// Start UART receiver
#define UART_STOPRX 0x004 // Stop UART receiver
#define UART_STARTTX 0x008// Start UART transmitter
#define UART_STOPTX 0x00C // Stop UART transmitter
#define UART_SUSPEND 0x01C// Suspend UART

// Events:
#define UART_CTS 0x100   // CTS is activated (set low). Clear To Send.
#define UART_NCTS 0x104  // CTS is deactivated (set high). Not Clear To Send.
#define UART_RXDRDY 0x108// Data received in RXD
#define UART_TXDRDY 0x11C// Data sent from TXD
#define UART_ERROR 0x124 // Error detected
#define UART_RXTO 0x144  // Receiver timeout

// Registers:
#define UART_INTEN 0x300   // Enable or disable interrupt
#define UART_INTENSET 0x304// Enable interrupt
#define UART_INTENCLR 0x308// Disable interrupt
#define UART_ERRORSRC 0x480// Error source
#define UART_ENABLE 0x500  // Enable UART
#define UART_PSELRTS 0x508 // Pin select for RTS
#define UART_PSELTXD 0x50C // Pin select for TXD
#define UART_PSELCTS 0x510 // Pin select for CTS
#define UART_PSELRXD 0x514 // Pin select for RXD
#define UART_RXD 0x518     // RXD register
#define UART_TXD 0x51C     // TXD register
#define UART_BAUDRATE 0x524// Baud rate
#define UART_CONFIG 0x56C  // Configuration of parity and hardware flow control

// Other:
#define UART_TASK_START 1   // Value for starting a Task
#define UART_EVENT_TRIGGER 1// Value for setting/starting an Event
#define UART_EVENT_CLEAR 0  // Value for clearing/stopping an Event

#define UART_INT_RXDRDY (1 << 2)

/**
 * @brief Initializing the UART with the following Settings:
 * 115200-8-N-1
 */
void uart_init(bool with_interrupts);

/**
 * @brief Writes/Sends a byte over the serial Port
 *
 * @param data byte to send (ASCII)
 */
void uart_writeByte(uint8_t data);

/**
 * @brief Read/Receive a byte from the serial Port
 *
 * @return uint8_t received Byte or 0 (zero) if nothing was received
 */
uint8_t uart_readByte();

#endif// UART_H
