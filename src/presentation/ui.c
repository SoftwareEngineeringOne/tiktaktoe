#include "presentation/ui.h"
#include "presentation/cursor.h"
#include "presentation/print.h"
#include <stddef.h>

void ui_displayTimer(uint16_t remaining_time) {
    cursor_moveTo(1, TIMER_ROW);
    print("Remaining: ");
    ui_updateTimer(remaining_time);
}

void ui_updateTimer(uint16_t remaining_time) {
    cursor_moveTo(1 + 11, TIMER_ROW);
    print(ERASE_LINE_FROM_CURSOR);
    for(uint16_t i = 0; i < remaining_time - 1; i++) {
        print("- ");
    }

}
void ui_displayTurn(uint8_t current_turn, char* playerName) {
    cursor_moveTo(1, TURN_ROW);

    print("Turn");
    cursor_moveTo(1 + 5 + 3, TURN_ROW);
    print(" Waiting for ");
    ui_updateTurn(current_turn, playerName);
}

void ui_updateTurn(uint8_t current_turn, char* playerName) {
    static char buf[3];
    static size_t size = sizeof(buf);


    int_to_str(current_turn, buf, size);

    cursor_moveTo(1 + 5, TURN_ROW);
    print(buf);

    cursor_moveTo(1 + 5 + 3 + 13, TURN_ROW);
    print(playerName);
    print("...");
}
