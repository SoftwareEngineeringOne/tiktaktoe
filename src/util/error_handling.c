#include "util/hard_fault.h"

#include "../../entry/entry_c.h"

#include <hal_high/input_buf.h>
#include <hal_low/nvic.h>
#include <hal_low/system.h>
#include <presentation/print.h>
#include <presentation/style.h>

static void _handleError(const char* hint);

void handleHardFault()
{
    _handleError("You have encountered a hard fault. If this error persists please contact the developer!");
}

void handleUnexpectedInterrupt()
{
    _handleError("An unexpected interrupt occurred. If this error persists please contact the developer!");
}

static void _handleError(const char* hint)
{
    print_clearConsole();
    print(FG_RED);
    print(BOLD);
    print("Ooops, something went very wrong!\n");
    print(RESET);
    println(hint);
    print("\nPress any key to try to reset the game... ");
    print(DIM);
    println("(This is not guaranteed to fix the error)");
    print(RESET);

    while(input_isEmpty(&g_input_buf))
    {
        __WFI();
    }

    system_softReset();
}
