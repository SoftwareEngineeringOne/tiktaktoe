/**
 * @file system.c
 *
 * @brief Implementation of system control functions.
 *
 * @see system.h
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "hal/system.h"
#include "def.h"
#include "hal/register_access.h"

void system_softReset()
{
    register_write(SYS_AIRCR, SYS_VECTKEY | SYS_SYSRESETREQ);
    // ReSharper disable once CppDFAEndlessLoop
    while(true)
        ;
}

void system_offMode()
{
    register_write(SYS_POWER | SYS_SYSTEMOFF, 1);
    // ReSharper disable once CppDFAEndlessLoop
    while(true)
        ;
}
