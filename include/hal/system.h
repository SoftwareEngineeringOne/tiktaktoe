/**
 * @file system.h
 *
 * @brief System control interface for hardware abstraction layer.
 *
 * @details
 * This file contains macros and function declarations for controlling
 * system-level operations such as soft reset and power-off mode.
 *
 * @ingroup HAL
 *
 * @see system.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

/**
 * @def SYS_AIRCR
 * @brief Address of the Application Interrupt and Reset Control Register.
 */
#define SYS_AIRCR 0xE000ED0C

/**
 * @def SYS_VECTKEY
 * @brief Key required to write to SYS_AIRCR.
 */
#define SYS_VECTKEY (0x5FA << 16)

/**
 * @def SYS_SYSRESETREQ
 * @brief Bit mask to trigger a system reset.
 */
#define SYS_SYSRESETREQ (1 << 2)

/**
 * @def SYS_POWER
 * @brief Base address for power control registers.
 */
#define SYS_POWER 0x40000000

/**
 * @def SYS_SYSTEMOFF
 * @brief Offset for the system off mode register.
 */
#define SYS_SYSTEMOFF 0x500

/**
 * @brief Trigger a soft reset of the system.
 *
 * @note **Never returns**
 */
void system_softReset();

/**
 * @brief Triggers "off" mode of the system.
 *
 * @note **Never returns**
 */
void system_offMode();

#endif// SYSTEM_H
