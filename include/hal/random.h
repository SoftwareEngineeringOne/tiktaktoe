/**
 * @file random.h
 *
 * @brief Contains constants and abstraction functions for the RNG device
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

// Base Address (Instance)
#define RNG_BASE_ADDRESS 0x4000D000

// Register Offsets (from Table 174, page 115)
// Tasks:
#define RNG_START 0x000// Task starting the random number generator
#define RNG_STOP 0x004 // Task stopping the random number generator

// Events:
#define RNG_VALRDY \
    0x100// Event being generated for every new random number written to the VALUE register

// Registers:
#define RNG_SHORTS 0x200  // Shortcut register
#define RNG_INTEN 0x300   // Enable or disable interrupt
#define RNG_INTENSET 0x304// Enable interrupt
#define RNG_INTENCLR 0x308// Disable interrupt
#define RNG_CONFIG 0x504  // Configuration register
#define RNG_VALUE 0x508   // Output random number

// Other:
#define RNG_TASK_START 1   // Value for starting a Task
#define RNG_EVENT_TRIGGER 1// Value for setting/starting an Event
#define RNG_EVENT_CLEAR 0  // Value for clearing/stopping an Event

/**
 * @brief Enables the generation of random numbers
 */
void rng_init(void);

/**
 * @brief Get the Random Value from the generator immediately.
 *
 * The function will **NOT** wait until the next value is generated!
 *
 * @return uint8_t A random byte
 */
uint8_t rng_getRandomValue_immediately(void);

/**
 * @brief This is a function stub. Implement it, if needed.
 *
 * @return uint8_t A random byte
 */
uint8_t rng_getRandomValue_waiting(void);

#endif// RANDOM_H
