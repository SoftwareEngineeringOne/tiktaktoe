#include "logic/game.h"

#include "hal_low/nvic.h"
#include "hal_high/input_buf.h"
#include "logic/input.h"
#include "presentation/cell.h"
#include "presentation/field.h"
#include "presentation/print.h"
#include "logic/time.h"


void game_run()
{
    input_init(&input_buf);
    print(HIDE_CURSOR);

    static uint8_t input;
    static Cell cell = {
        .col = 0,
        .row = 0,
        .marked_by = None,
    };

    clearConsole();
    time_init();
    field_redraw();
    cell_select(&cell);
    while(true)
    {
        while(!input_getNext(&input_buf, &input)) {
            __WFI();
        }

        bool should_redraw = false;
        bool should_quit = false;
        switch(input)
        {
            case '\e':
                input_handleEscapeSequence(&cell);
                break;
            case 'w':
                CELL_HEIGHT += 1;
                CELL_WIDTH += 1;
                should_redraw = true;
                break;
            case 's':
                CELL_HEIGHT -= 1;
                CELL_WIDTH -= 1;
                should_redraw = true;
                break;
            case 'q':
                should_quit = true;
                break;
            default:;
        }

        if(should_quit)
        {
            clearConsole();
            break;
        }

        if(should_redraw)
        {
            clearConsole();
            field_redraw();
        }

        cell_select(&cell);
    }
    println("Thanks for playing! Soon you'll see a menu here...");
    println("For now you can press \"CTR + A\" and then \"x\" to exit qemu!");
    print(SHOW_CURSOR);
}

void game_markPosition()
{
}

void game_updateTime() {
    if (time_roundTicks == (TICKS_PER_ROUND-1)) {
        time_roundTicks = 0;
        //TODO: Change player
    }
    time_update();
}
