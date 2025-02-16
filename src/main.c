#include "hal_low/random.h"
#include "hal_low/uart.h"
#include "presentation/print.h"
#include "logic/game.h"

int main(void)
{
    uart_init(true);

    clearConsole();
    game_run();
}


/* static void waitRelease(void) */
/* { */
/*     bool start = false; */
/*     while(!start) {} */
/* } */
/**/
/* static void randomNumberTest(void) */
/* { */
/*     // Initialize the Module */
/*     rng_init(); */
/**/
/*     while(true) */
/*     { */
/*         uint8_t randomNumber = rng_getRandomValue_waiting(); */
/**/
/*         // uart_writeNumber(randomNumber); */
/*         // uart_writeString("\n"); */
/*     } */
/* } */
/**/
/* static void timerTest(void) */
/* { */
/*     // timer_init( TIMER0 ); */
/**/
/*     timer_init_detailed(TIMER0, 15, TIMER_MODE_TIMER, TIMER_BIT_MODE_32); */
/**/
/*     timer_captureCompareSet(TIMER0, CC0, 2000, true); */
/**/
/*     timer_start(TIMER0); */
/**/
/*     while(true) */
/*     { */
/*         timer_capture(TIMER0, CC1); */
/**/
/*         uint32_t captureValue = timer_captureCompareGet(TIMER0, CC1); */
/**/
/*         // uart_writeNumber( captureValue ); */
/*     } */
/* } */
