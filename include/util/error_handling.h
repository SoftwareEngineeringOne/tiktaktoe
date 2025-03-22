/**
 * @file error_handling.h
 *
 * @brief Contains functions to react on errors.
 *
 * @ingroup Utility
 *
 * @see error_handling.c
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef HARD_FAULT_H
#define HARD_FAULT_H

/**
 * @brief Handles hard faults.
 *
 * @details
 * This function is triggered when a hard fault occurs. It provides
 * a mechanism to handle the fault and display an appropriate message.
 */
void HardFault_Handler() __attribute__((interrupt));

/**
 * @brief Handles unexpected interrupts.
 *
 * @details
 * This function is triggered when an unexpected interrupt occurs. It provides
 * a mechanism to handle the interrupt and display an appropriate message.
 */
void Default_Handler() __attribute__((interrupt));

#endif// HARD_FAULT_H
