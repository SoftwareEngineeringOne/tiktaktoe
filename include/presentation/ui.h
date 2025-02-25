#ifndef UI_H
#define UI_H

#include <stdint.h>

#define TURN_ROW 1
#define TIMER_ROW 2

/**
 * @brief Writes the timer text to the screen
 * @param [in] remaining_time
 */
void ui_displayTimer(uint16_t remaining_time);

/**
 * @brief Updates the time on the screen
 * @param [in] remaining_time
 */
void ui_updateTimer(uint16_t remaining_time);

/**
 * @brief Writes the turn text to the screen
 * @param [in] current_turn
 * @param [in] playerName
 */
void ui_displayTurn(uint8_t current_turn, char *playerName);

/**
 * @brief Updates the turn number on the screen
 * @param [in] current_turn
 * @param [in] playerName
 */
void ui_updateTurn(uint8_t current_turn, char *playerName);

#endif// UI_H
