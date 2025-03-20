/**
 * @file register_access.h
 *
 * @author Thomas Vogt
 * @author Sven Reis
 *
 * @brief Contains abstraction functions of the register access
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
 * @brief Write Value to Register
 *
 * @param[in] address Register Address
 * @param[in] value Register Value
 **/
void register_write(uint32_t address, uint32_t value);

/**
 * @brief Read from Register.
 *
 * @param[in] address Register Address
 *
 * @return Register Value
 **/
uint32_t register_read(uint32_t address);

#endif// REGISTERACCESS_H
