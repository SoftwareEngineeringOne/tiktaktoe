/**
 * @file register_access.h
 *
 * @brief Register Access Interface
 *
 * @details
 * This file provides an interface for reading from and writing to hardware registers.
 *
 * @ingroup HAL
 *
 * @see
 *  register_access.c
 *
 * @note
 *  Ensure that the provided addresses are valid and aligned as required by the hardware.
 *
 * @author Thomas Vogt
 * @author Sven Reis
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef REGISTERACCESS_H
#define REGISTERACCESS_H

#include <stdint.h>

/**
 * @brief Write a value to a hardware register.
 *
 * @param[in] address Memory address of the register.
 * @param[in] value Value to write to the register.
 */
void register_write(uint32_t address, uint32_t value);

/**
 * @brief Read a value from a hardware register.
 *
 * @param[in] address Memory address of the register.
 *
 * @return Value read from the register.
 */
uint32_t register_read(uint32_t address);

#endif// REGISTERACCESS_H
