/**
 * @file error_handling.h
 *
 * @brief Contains functions to react on inevitable errors
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef HARD_FAULT_H
#define HARD_FAULT_H


void HardFault_Handler() __attribute__((interrupt));

void Default_Handler() __attribute__((interrupt));

#endif// HARD_FAULT_H
