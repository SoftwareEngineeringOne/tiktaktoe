#ifndef UI_H
#define UI_H

#include <stdint.h>

#define TURN_ROW 1
#define TIMER_ROW 2

void ui_displayTimer(uint16_t remaining_time);
void ui_displayTurn(uint8_t current_turn, char* playerName);

#endif // !UI_H
