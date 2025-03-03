#include "util/error_handling.h"
#include "presentation/ui.h"

#include <hal_high/input_buf.h>
#include <hal_low/system.h>
#include <hal_low/uart.h>
#include <presentation/print.h>
#include <presentation/style.h>

static void handleError(const char *hint);

void handleHardFault()
{
    handleError(
        "You have encountered a hard fault. If this error persists please contact the developer!");
}

void handleUnexpectedInterrupt()
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
        // __WFI();
    }

    system_softReset();
}
