/**
 * @file 
 *
 * @author Thomas Vogt
 *
 * @date 
 *
 * @brief ARM Cortex-M4 Linker Script.
 *
 * @see 
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/* 
* Flash Configuration:
* - Start:        0x00000000
* - Size:         262KB
*/
__ROM_BASE = 0x00000000;
__ROM_SIZE = 0x00040000;

/* 
* RAM Configuration:
* - Start:        0x20000000 
* - Total Size:   16KB
* - Stack Size:   16KB
* - Heap Size:    0KB
*/
__RAM_BASE = 0x20000000;
__RAM_SIZE = 0x00004000;
__STACK_SIZE = 0x00000400;
__HEAP_SIZE  = 0x00000C00;


ENTRY ( Reset_Handler )

MEMORY
{
    FLASH (rx)  : ORIGIN = __ROM_BASE, LENGTH = __ROM_SIZE
    RAM   (rwx) : ORIGIN = __RAM_BASE, LENGTH = __RAM_SIZE
}

SECTIONS
{
    /* Executable Code */
    .text :
    {
        KEEP(*(.isr_vectors))
        *(.text*)
    } > FLASH

    /* Read Only Data */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata*)
        . = ALIGN( 4 );
    } > FLASH

    /* Initialized Data */
    .data : 
    {
        . = ALIGN(4);
        __data_start__ = .;
        __data_load_addr__ = LOADADDR(.data);
        *(.data*)
        . = ALIGN( 4 );
        __data_end__ = .;
    } > RAM AT > FLASH

    /* Unitialized data */
    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM AT > RAM

    /* Heap, if it existed */

    /* Stack is located on top of RAM */
    .stack (ORIGIN(RAM) + LENGTH(RAM) - __STACK_SIZE) (NOLOAD) :
    {
        . = ALIGN(8);
        __StackLimit = .;
        . = . + __STACK_SIZE;
        . = ALIGN(8);
        __StackTop = .;
    } > RAM

    PROVIDE( __stack = __StackTop );
}
