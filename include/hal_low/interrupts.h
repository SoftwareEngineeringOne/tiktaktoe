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