/**
 * @file
 *
 * @author Thomas Vogt
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
 *
 */

#include "entry_c.h"

#include <stdint.h>

/**
 * @brief Zeros the BSS Section.
 **/
static void zeroBss(void);

/**
 * @brief Copies Data Section from Flash to RAM.
 **/
static void copyData(void);

/**
 * @brief Initializes memory sections and transfers control to the main function.
 *
 * This function zeros out the BSS section and copies the initialized data from ROM to RAM,
 * setting up the runtime environment before calling the externally defined main function.
 * It is marked with the `used` attribute to ensure it is retained by the linker.
 */
__attribute__((used)) void entry_c(void)
{
    zeroBss();
    copyData();

    extern int main(void);// TODO: make it better!!!

    main();

    // endless loop
    /* for (;;) */
    /* { */
    /* } */
}
/**
 * @brief Zeros out the BSS memory section.
 *
 * This function iterates from the start of the BSS section (__bss_start__) to its end (__bss_end__)
 * and sets each 32-bit word to zero. It ensures that all uninitialized global and static variables
 * in the BSS segment are cleared before the application's main function is executed.
 */
static void zeroBss(void)
{
    // Symbol is located on start of BSS Section
    extern uint32_t __bss_start__;// NOLINT
    // Symbol is located on end of BSS Section
    extern uint32_t __bss_end__;// NOLINT

    /* loop over BSS Section and set to Zero */
    for(uint32_t *bssPos = &__bss_start__; bssPos < &__bss_end__; ++bssPos)
    {
        *bssPos = 0U;
    }
}

/**
 * @brief Copies initialized data from Flash memory to RAM.
 *
 * This function copies each 32-bit word from the source data section in Flash,
 * starting at `__data_start_rom__`, to the destination data section in RAM,
 * spanning from `__data_start__` (inclusive) to `__data_end__` (exclusive).
 */
static void copyData(void)
{
    // Symbol is located on start of Data Section
    extern uint32_t __data_start__;// NOLINT
    // Symbol is located on end of Data Section
    extern uint32_t __data_end__;// NOLINT
    // Symbol is located on start of LMA Data Section located in Flash
    extern const uint32_t __data_start_rom__;// NOLINT

    // Source of Data (in Flash)
    uint32_t const *dataCopyPos = &__data_start_rom__;

    /* loop over Data Section and copy data from flash */
    for(uint32_t *dataPos = &__data_start__; dataPos < &__data_end__; ++dataPos)
    {
        *dataPos = *dataCopyPos;
        ++dataCopyPos;
    }
}
