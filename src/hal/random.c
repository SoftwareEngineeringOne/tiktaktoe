/**
 * @file random.c
 *
 * @brief Implementation of the RNG HAL for random number generation.
 *
 * @see random.h
 *
 * @note
 * Based on version by Thomas Vogt
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "hal/random.h"
#include "hal/register_access.h"
#include <stdint.h>

void rng_init()
{
    // Write a '1' to the Start Task, to start the generation of random numbers
    register_write(RNG_BASE_ADDRESS | RNG_START, RNG_TASK_START);
}

uint8_t rng_getRandomValue_immediately()
{
    // Read 32-Bit Register containing the RNG Value
    const uint32_t randomValue = register_read(RNG_BASE_ADDRESS | RNG_VALUE);

    // It's actually just 8-Bit, so cast it.
    return (uint8_t)randomValue;
}

uint8_t rng_getRandomValue_waiting()
{
    // Wait until the Value Ready event is set
    while(register_read(RNG_BASE_ADDRESS | RNG_VALRDY) == 0)
    {
        // Wait until the Value is ready
    }

    // Clear the Value Ready event
    register_write(RNG_BASE_ADDRESS | RNG_VALRDY, RNG_EVENT_CLEAR);

    // Return the random value
    return rng_getRandomValue_immediately();
}
