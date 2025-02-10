//
// Created by paul on 2/10/25.
//

#ifndef FIELD_H
#define FIELD_H

#include <stdint.h>

/**
 * @brief Initial drawing of the playing field
 **/
void output_drawField();

/**
 * @brief Draws the cursor of the player on the given field
 *
 * @param[in] posX
 *   X coordinate
 * @param[in] posY
 *   Y coordinate
 **/
void output_setCursor(uint8_t posX, uint8_t posY);

/**
 * @brief Draws the given character on the given field
 *
 * @param[in] posX
 *   X coordinate
 * @param[in] posY
 *   Y coordinate
 * @param[in] symbol
 *   Character to draw
 **/
void output_setField(uint8_t posX, uint8_t posY, char symbol);

/**
 * @brief Draws the new time on the screen
 *
 * @param[in] seconds
 *   Time in seconds
 **/
void output_setTimer(uint8_t seconds);

#endif //FIELD_H
