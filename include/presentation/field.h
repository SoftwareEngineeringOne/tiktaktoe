//
// Created by paul on 2/10/25.
//

#ifndef FIELD_H
#define FIELD_H

#include <stdint.h>

#define FIELDS_PER_ROW 4
#define FIELDS_PER_COL 4

#define FIELD_HEIGHT 3
#define FIELD_WIDTH 3

#define CORNER_TOP_LEFT "┌"
#define CORNER_TOP_RIGHT "┐"
#define CORNER_BOTTOM_LEFT "└"
#define CORNER_BOTTOM_RIGHT "┘"
#define SIDE "│"    
#define TOP_BOTTOM "─"

typedef struct {
  uint16_t top;
  uint16_t left;
    char* color;
} Field;

static Field fields[FIELDS_PER_ROW][FIELDS_PER_COL];

void output_initFields();

void output_changeFieldColor(Field field, char* color);

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


// Private stuff
void assignChar(uint8_t row, uint8_t col, uint16_t top, uint16_t left, char* color);
void updateField(Field field);
#endif //FIELD_H
