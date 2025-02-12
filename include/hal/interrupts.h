#ifndef INTERRUPTS_H
#define INTERRUPTS_H


void default_handler(void);

typedef void (*interrupt_function)(void);
extern interrupt_function interrupt2;

void Interrupt1_Handler(void);
void Interrupt2_Handler(void);
void Interrupt3_Handler(void);
void Interrupt4_Handler(void);
void Interrupt5_Handler(void);
void Interrupt6_Handler(void);
void Interrupt7_Handler(void);
void Interrupt8_Handler(void);
void Interrupt9_Handler(void);

#endif // !INTERRUPTS_H
