//
// Created by paul on 2/17/25.
//

#include "logic/time.h"
#include "presentation/print.h"
#include "presentation/cursor.h"
#include "hal_low/timer.h"

volatile int time_sumTicks = 0;
volatile int time_roundTicks = 0;

void time_init()
{
    timer_init_detailed(TIMER0, 15, TIMER_MODE_TIMER, TIMER_BIT_MODE_32);
    timer_captureCompareSet(TIMER0, CC0, 2000, true);
    timer_start(TIMER0);

    println("Time: ");
    println("Remaining Time: ");
    time_sumTicks = 0;
    time_roundTicks = 0;
}

void time_update()
{
    time_sumTicks++;
    time_roundTicks++;

    char *buf[10];

    int_to_str(time_sumTicks, buf, 10);
    cursor_moveTo(7, 1);
    print(buf);

    int_to_str(TICKS_PER_ROUND - time_roundTicks, buf, 10);
    cursor_moveTo(17, 2);
    print(buf);
}
