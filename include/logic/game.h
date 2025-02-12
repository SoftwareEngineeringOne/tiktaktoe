//
// Created by paul on 2/10/25.
//

#ifndef GAME_H
#define GAME_H

enum CursorDirection{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

/**
 * @brief Tries to move the cursor into the given direction
 *
 * @param[in] direction
 *   One of the main directions
 **/
void logic_moveCursor(enum CursorDirection direction);

/**
 * @brief Tries to mark the current position
 **/
void logic_markPosition();

/**
 * @brief Increase the clock by one second
 **/
void logic_updateTime();

/**
 * @brief Exits the game
 **/
void logic_quit();

#endif //GAME_H
