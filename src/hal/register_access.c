/**
 * @file register_access.c
 *
 * @brief Register Access Implementation
 *
 * @see
 *  register_access.h
 *
 * @author Thomas Vogt
 * @author Sven Reis
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "hal/register_access.h"

void register_write(const uint32_t address, const uint32_t value)
{
    // Assign pointer to given address:
    uint32_t * const pointer_to_address = (uint32_t *)address;

    // Write to the End of the Pointer
    *pointer_to_address = value;
}

uint32_t register_read(const uint32_t address)
{
    // Assign pointer to given address:
    uint32_t const * const pointer_to_address = (uint32_t *)address;

    // Read from the End of the Pointer
    const uint32_t value = *pointer_to_address;

    // Return the read value
    return value;
}
