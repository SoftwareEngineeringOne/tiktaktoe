#include "presentation/ui.h"
#include "presentation/cursor.h"
#include "presentation/print.h"

void ui_displayTimer(uint16_t remaining_time) {
    cursor_moveTo(1, TIMER_ROW);
    print("Remaining: ");
    for(uint16_t i = 0; i < remaining_time; i++) {
        print("- ");
    }
}
void ui_displayTurn(uint8_t current_turn, char* playerName);
