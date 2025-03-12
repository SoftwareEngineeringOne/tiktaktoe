/*! !! This file has been generated automatically, any changes may be overridden !! !*/
/**
 * @file config.h
 *
 * @brief Contains important compile-time options
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef CONFIG_H
#define CONFIG_H

// if UNICODE is not defined, ascii characters are used
#define ENABLE_UNICODE

#define ENABLE_ASCII_ART

// size of the field
#define CELLS_PER_ROW 3
#define CELLS_PER_COL 3

// game speed
#define TICKS_PER_TURN 20
#define TICK_SPEED 12

#endif //CONFIG_H
