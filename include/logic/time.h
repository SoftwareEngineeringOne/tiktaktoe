#ifndef TIME_H
#define TIME_H

#define TICKS_PER_ROUND 20
#define TICK_SPEED 11

extern volatile int time_sumTicks;
extern volatile int time_roundTicks;

/**
 * @brief Initializes the timer
 */
void time_init();

/**
 * @brief Increments the ticks and can finish the round
 */
void time_onInterrupt();

/**
 * @brief Resets the ticks
 */
void time_finishRound();

#endif// TIME_H
