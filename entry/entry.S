/**
 *
 * @file entry.S
 *
 * @brief Entry point and initialization routines for the Tic-Tac-Toe project.
 *
 * @details
 * This file contains the interrupt vector table, reset handler, and initialization
 * routines for the Cortex-M0 processor. It also includes default handlers for
 * interrupts and exceptions.
 *
 * @note
 * This file is written in ARM assembly and is intended to be processed by the
 * `asm4doxy.pl` script for generating Doxygen-compatible documentation.
 * Generated documentation can be found under the file `entry-S.c`
 *
 * @see entry-S.c
 *
 * @note
 * Based on version by Thomas Vogt and Sven Reis
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
    /* From C code */
    .extern main
    .extern HardFault_Handler
    .extern Default_Handler

/* ==== Interrupt Vector Table ==== */
    .section .isr_vectors, "a", %progbits
    .align 2
    .type g_pfnVectors, %object
/**
 * @brief Interrupt vector table.
 *
 * @details
 * This table defines the initial stack pointer and the entry points for
 * various exceptions and interrupts.
 */
g_pfnVectors:
    .long __StackTop          /* Top of Stack */
    .long Reset_Handler       /* Reset Handler */
    .long NMI_Handler         /* -14 NMI Handler */
    .long HardFault_Handler   /* -13 Hard Fault Handler */
    .long 0                   /* Reserved */
    .long 0                   /* Reserved */
    .long 0                   /* Reserved */
    .long 0                   /* Reserved */
    .long 0                   /* Reserved */
    .long 0                   /* Reserved */
    .long 0                   /* Reserved */
    .long SVC_Handler         /* -5 SVC Handler */
    .long DebugMon_Handler    /* -4 Debug Monitor Handler */
    .long 0                   /* Reserved */
    .long PendSV_Handler      /* -2 PendSV Handler */
    .long SysTick_Handler     /* -1 SysTick Handler */

    /* Interrupts */
    .long Interrupt0_Handler  /* 0 Interrupt 0 */
    .long Interrupt1_Handler  /* 1 Interrupt 1 */
    .long Interrupt2_Handler  /* 2 Interrupt 2 */
    .long Interrupt3_Handler  /* 3 Interrupt 3 */
    .long Interrupt4_Handler  /* 4 Interrupt 4 */
    .long Interrupt5_Handler  /* 5 Interrupt 5 */
    .long Interrupt6_Handler  /* 6 Interrupt 6 */
    .long Interrupt7_Handler  /* 7 Interrupt 7 */
    .long Interrupt8_Handler  /* 8 Interrupt 8 */
    .long Interrupt9_Handler  /* 9 Interrupt 9 */

    .space   (22 * 4)         /* Interrupts 10 to 31 are left out */
    .size g_pfnVectors, . - g_pfnVectors

    .section .text, "ax", %progbits

/* ==== Entry Point ==== */
    .global Reset_Handler
    .type Reset_Handler, %function
/**
 * @brief Reset handler.
 *
 * @details
 * This function is the entry point after a reset. It initializes the `.bss`
 * and `.data` sections and then calls the `main` function.
 */
Reset_Handler:
    bl zeroBss
    bl copyData
    bl main
1:
    bkpt
    b 1b

/* ==== Initializing Functions ==== */
    .global zeroBss
    .type zeroBss, %function
/**
 * @brief Zeroes the `.bss` section.
 *
 * @details
 * This function sets all bytes in the `.bss` section to zero.
 */
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
/**
 * @brief Copies the `.data` section from flash to RAM.
 *
 * @details
 * This function initializes the `.data` section by copying its contents
 * from the load address in flash to the execution address in RAM.
 */
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
    .type    HardFault_Handler, %function
    .weak    HardFault_Handler
/**
 * @brief Default HardFault handler.
 *
 * @details
 * This is a weak symbol that can be overridden by a user-defined handler.
 */
HardFault_Handler:
    bkpt
    b HardFault_Handler
    .size    HardFault_Handler, . - HardFault_Handler

    .type    Default_Handler, %function
    .weak    Default_Handler
/**
 * @brief Default handler for unimplemented interrupts.
 *
 * @details
 * This is a weak symbol that can be overridden by a user-defined handler.
 */
Default_Handler:
    bkpt
    b Default_Handler
    .size    Default_Handler, . - Default_Handler


/**
 * @brief Macro which defines a default handler for an interrupt or exception.
 *
 * @details
 * This macro creates a weak alias for the `Default_Handler` for the specified
 * interrupt or exception.
 *
 * Example:
 * @code
 *   Set_Default_Handler NMI_Handler
 * @endcode
 */
Set_Default_Handler:
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
