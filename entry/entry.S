/**
 * @file 
 *
 * @author Thomas Vogt
 * @author Sven Reis
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
    .syntax unified
    .cpu cortex-m0
    .thumb

    /* External Symbols */
    /* From linker_script.ld */
    .extern __StackTop
    .extern __data_start__
    .extern __data_end__
    .extern __data_load_addr__
    .extern __bss_start__
    .extern __bss_end__
    /* From c code */
    .extern main
    .extern HardFault_Handler
    .extern Default_Handler

/* ==== Interrupt Vector Table ==== */
    .section .isr_vectors, "a", %progbits
    .align 2
    .type g_pfnVectors, %object
g_pfnVectors:
    .long __StackTop          /*      Top of Stack  */
    .long Reset_Handler       /*      Reset Handler  */
    .long NMI_Handler         /* -14  NMI Handler  */
    .long HardFault_Handler   /* -13  Hard Fault Handler  */
    .long 0                   /*      Reserved  */
    .long 0                   /*      Reserved  */
    .long 0                   /*      Reserved  */
    .long 0                   /*      Reserved  */
    .long 0                   /*      Reserved  */
    .long 0                   /*      Reserved  */
    .long 0                   /*      Reserved  */
    .long SVC_Handler         /*  -5  SVC Handler  */
    .long DebugMon_Handler    /*  -4  Debug Monitor Handler  */
    .long 0                   /*      Reserved  */
    .long PendSV_Handler      /*  -2  PendSV Handler  */
    .long SysTick_Handler     /*  -1  SysTick Handler  */

    /*  Interrupts  */
    .long Interrupt0_Handler  /*   0  Interrupt 0  */
    .long Interrupt1_Handler  /*   1  Interrupt 1  */
    .long Interrupt2_Handler  /*   2  Interrupt 2  */
    .long Interrupt3_Handler  /*   3  Interrupt 3  */
    .long Interrupt4_Handler  /*   4  Interrupt 4  */
    .long Interrupt5_Handler  /*   5  Interrupt 5  */
    .long Interrupt6_Handler  /*   6  Interrupt 6  */
    .long Interrupt7_Handler  /*   7  Interrupt 7  */
    .long Interrupt8_Handler  /*   8  Interrupt 8  */
    .long Interrupt9_Handler  /*   9  Interrupt 9  */

    .space   (22 * 4)         /* Interrupts 10 to 31 are left out  */
    .size g_pfnVectors, . - g_pfnVectors


    .section .text, "ax", %progbits

/* ==== Entry Point ==== */
    .global Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:
    bl zeroBss
    bl copyData
    bl main
1:
    bkpt
    b 1b

/* ==== Initialising functions ==== */
    .global zeroBss
    .type zeroBss, %function
zeroBss:
    ldr r0, =__bss_start__
    ldr r1, =__bss_end__
    movs r2, #0
    b 2f
1:  
    str r2, [r0]
    adds r0, #4
2:  
    cmp r0, r1
    blo 1b
    bx lr

    .global copyData
    .type copyData, %function
copyData:
    ldr r0, =__data_start__
    ldr r1, =__data_end__
    ldr r2, =__data_load_addr__
    cmp r0, r1
    bhs 2f
1:
    ldr r3, [r2]
    str r3, [r0]
    adds r0, #4
    adds r2, #4
    cmp r0, r1
    blo 1b
2:
    bx lr


/* ==== Fallbacks and Defaults ==== */

    /* Fallback incase C implementation does not exist */
    .type    HardFault_Handler, %function
    .weak    HardFault_Handler
HardFault_Handler:
    bkpt
    b HardFault_Handler

    .size    HardFault_Handler, . - HardFault_Handler

    /* Fallback incase C implementation does not exist */
    .type    Default_Handler, %function
    .weak    Default_Handler
Default_Handler:
    bkpt
    b Default_Handler

    .size    Default_Handler, . - Default_Handler

    /* Macro to define default exception/interrupt handlers.
     * Default handler are weak symbols with an endless loop.
     * They can be overwritten by real handlers.
     */
    .macro   Set_Default_Handler  Handler_Name
    .weak    \Handler_Name
    .set     \Handler_Name, Default_Handler
    .endm

    Set_Default_Handler  NMI_Handler
    Set_Default_Handler  SVC_Handler
    Set_Default_Handler  DebugMon_Handler
    Set_Default_Handler  PendSV_Handler
    Set_Default_Handler  SysTick_Handler

    Set_Default_Handler  Interrupt0_Handler
    Set_Default_Handler  Interrupt1_Handler
    Set_Default_Handler  Interrupt2_Handler
    Set_Default_Handler  Interrupt3_Handler
    Set_Default_Handler  Interrupt4_Handler
    Set_Default_Handler  Interrupt5_Handler
    Set_Default_Handler  Interrupt6_Handler
    Set_Default_Handler  Interrupt7_Handler
    Set_Default_Handler  Interrupt8_Handler
    Set_Default_Handler  Interrupt9_Handler

    .end
