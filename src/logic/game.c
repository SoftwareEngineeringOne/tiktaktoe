#include "logic/game.h"

#include "hal_low/nvic.h"
#include "hal_low/uart.h"
#include "hal_low/random.h"
#include "hal_high/input_buf.h"
#include "logic/input.h"
#include "presentation/cell.h"
#include "presentation/cursor.h"
#include "presentation/field.h"
#include "presentation/print.h"
#include "logic/time.h"
#include "logic/bot.h"

void game_run()
{
    input_init(&input_buf);
    rng_init();
    print(HIDE_CURSOR);

    static uint8_t input;

    for(int y = 0; y < CELLS_PER_COL; y++)
    {
        for(int x = 0; x < CELLS_PER_ROW; x++)
        {
            cells[y][x] = (Cell){
                .col = x,
                .row = y,
                .marked_by = None,
            };
        }
    }

    Cell *selected_cell = &cells[0][0];

    clearConsole();
    time_init();
    field_redraw();
    cell_select(selected_cell);
    while(true)
    {
        while(!input_getNext(&input_buf, &input))
        {
            __WFI();
        }

        bool should_redraw_field = false;
        bool should_quit = false;
        switch(input)
        {
            case '\e':
                input_handleEscapeSequence(cells, &selected_cell);
                break;
            case ' ':
                if (selected_cell->marked_by == None) {
                    selected_cell->marked_by = Human;
                    bot_mark(cells);
                }
                break;
            case 'w':
                CELL_HEIGHT += 1;
                CELL_WIDTH += 1;
                should_redraw_field = true;
                break;
            case 's':
                CELL_HEIGHT -= 1;
                CELL_WIDTH -= 1;
                should_redraw_field = true;
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

        if(should_redraw_field)
        {
            clearConsole();
            field_redraw();
        }

        // For Debug
        const char selected_col = int_to_char(selected_cell->col);
        const char selected_row = int_to_char(selected_cell->row);
        cursor_moveTo(1, 20);
        print("Col: ");
        uart_writeByte(selected_col);
        print("\nRow: ");
        uart_writeByte(selected_row);
        // End Debug

        cell_select(selected_cell);
    }
    println("Thanks for playing! Soon you'll see a menu here...");
    println("For now you can press \"CTR + A\" and then \"x\" to exit qemu!");
    print(SHOW_CURSOR);
    while(true)
    {
        // Für deine CPU Usage noch besser :))
        __WFI();
    }
}

void game_markPosition()
{
}

void game_updateTime()
{
    if(time_roundTicks == TICKS_PER_ROUND - 1)
    {
        time_roundTicks = 0;
        // TODO: Change player
    }
    time_update();
}
