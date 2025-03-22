/**
 * \file entry-S.c
 * \brief entry.S



 @file entry.S

 @brief Entry point and initialization routines for the Tic-Tac-Toe project.

 @details
 This file contains the interrupt vector table, reset handler, and initialization
 routines for the Cortex-M0 processor. It also includes default handlers for
 interrupts and exceptions.

 @note
 This file is written in ARM assembly and is intended to be processed by the
 `asm4doxy.pl` script for generating Doxygen-compatible documentation.
 Generated documentation can be found under the file `entry-S.c`

 @see entry-S.c

 @note
 Based on version by Thomas Vogt and Sven Reis

 @copyright
 This Source Code Form is subject to the terms of the Mozilla Public
 License, v2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 */


/**

 @brief Default handler for unimplemented interrupts.

 @details
 This is a weak symbol that can be overridden by a user-defined handler.

 */
void Default_Handler (void)
{
}
/**

 @brief Default HardFault handler.

 @details
 This is a weak symbol that can be overridden by a user-defined handler.

 */
void HardFault_Handler (void)
{
}
/**

 @brief Reset handler.

 @details
 This function is the entry point after a reset. It initializes the `.bss`
 and `.data` sections and then calls the `main` function.

 */
void Reset_Handler (void)
{
}
/**

 @brief Macro which defines a default handler for an interrupt or exception.

 @details
 This macro creates a weak alias for the `Default_Handler` for the specified
 interrupt or exception.

 Example:
 @code
   Set_Default_Handler NMI_Handler
 @endcode

 */
void Set_Default_Handler (void)
{
}
/**

 @brief Copies the `.data` section from flash to RAM.

 @details
 This function initializes the `.data` section by copying its contents
 from the load address in flash to the execution address in RAM.

 */
void copyData (void)
{
}
/**

 @brief Interrupt vector table.

 @details
 This table defines the initial stack pointer and the entry points for
 various exceptions and interrupts.

 */
void g_pfnVectors (void)
{
}
/**

 @brief Zeroes the `.bss` section.

 @details
 This function sets all bytes in the `.bss` section to zero.

 */
void zeroBss (void)
{
}
