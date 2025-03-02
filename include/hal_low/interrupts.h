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
 */
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void default_handler(void);

void Interrupt1_Handler(void);

/**
 * @brief UART interrupt handler
 */
void Interrupt2_Handler(void);

void Interrupt3_Handler(void);

void Interrupt4_Handler(void);

void Interrupt5_Handler(void);

void Interrupt6_Handler(void);

void Interrupt7_Handler(void);

/**
 * @brief Timer interrupt handler
 */
void Interrupt8_Handler(void);

void Interrupt9_Handler(void);

#endif// INTERRUPTS_H
