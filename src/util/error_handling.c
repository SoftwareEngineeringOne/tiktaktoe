#include "util/error_handling.h"
#include "presentation/ui.h"

#include "hal/system.h"
#include "hal/uart.h"
#include "presentation/print.h"
#include "presentation/style.h"

static void handleError(const char *hint);

void HardFault_Handler()
{
    handleError(
        "You have encountered a hard fault. If this error persists please contact the developer!");
}

void Default_Handler()
{
    handleError(
        "An unexpected interrupt occurred. If this error persists please contact the developer!");
}

static void handleError(const char *hint)
{
    print_clearConsole();
    ui_printHeading();
    print(FG_RED);
    print(BOLD);
    print("Ooops, something went very wrong!\n");
    print(RESET);
    println(hint);
    print("\nPress any key to try to reset the game... ");
    print(DIM);
    println("(This is not guaranteed to fix the error)");
    print(RESET);

    while(uart_readByte() == 0)
    {
    }

    system_softReset();
}
