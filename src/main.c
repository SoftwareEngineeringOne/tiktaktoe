#include "def.h"
#include "hal_high/input_buf.h"
#include "hal_low/nvic.h"
#include "hal_low/random.h"
#include "hal_low/uart.h"
#include "logic/game.h"
#include "presentation/print.h"

void menu_todo()
{
    clearConsole();
    println("Not yet implemented, any key to continue...");
    while(input_isEmpty(&input_buf))
    {
        __WFI();
    }
}

int main(void)
{
    uart_init(true);
    input_init(&input_buf);


    uint8_t input;
    while(true)
    {
        clearConsole();
        print("\e[H");
        println("Arrows to move");
        println("1. Play");
        println("2. Settings");
        println("3. Credits");
        println("4. Quit (not really hahahahaha)");

        while(!input_getNext(&input_buf, &input))
        {
            __WFI();
        }

        bool should_quit = false;
        switch(input)
        {
            case '1':
                game_run();
                break;
            case '2':
                menu_todo();
                break;
            case '3':
                menu_todo();
                break;
            case '4':
                should_quit = true;
                break;
            default:
                continue;
        }

        if(should_quit)
        {
            break;
        }
    }
    println("Thanks for playing!");
    println("For now you can press \"CTR + A\" and then \"x\" to exit qemu!");

    print(SHOW_CURSOR);
}
