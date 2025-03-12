/**
 * @file system.h
 *
 * @brief Contains system calls to change the system status
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef SYSTEM_H
#define SYSTEM_H

#define SYS_AIRCR 0xE000ED0C
#define SYS_VECTKEY (0x5FA << 16)
#define SYS_SYSRESETREQ (1 << 2)

#define SYS_POWER 0x40000000
#define SYS_SYSTEMOFF 0x500

/**
 * @brief Call the soft reset of the system
 **/
void system_softReset();

/**
 * @brief Call the shutdown of the system
 **/
void system_offMode();

#endif// SYSTEM_H
