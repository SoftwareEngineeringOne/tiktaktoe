#ifndef MENU_H
#define MENU_H

#include "logic/game.h"

#define RETURN_MENU_HINT "\nPress any key to return to the menu..."

#ifdef ENABLE_UNICODE
#define ARROW_LEFT "←"
#define ARROW_UP "↑"
#define ARROW_RIGHT "→"
#define ARROW_DOWN "↓"
#else
#define ARROW_LEFT "<LEFT>"
#define ARROW_UP "<UP>"
#define ARROW_RIGHT "<RIGHT>"
#define ARROW_DOWN "<DOWN>"
#endif

bool menu_showMainMenu();

void menu_showControls(const char *continue_hint);

void menu_showCredits();

void menu_showGameOver(const GameState *game_info);

void menu_anyKeyToContinue(const char *continue_hint);

#endif// MENU_H
