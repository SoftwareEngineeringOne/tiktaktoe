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

    print("HardFault incoming...");

    // char test[3];
    // int i = 0;
    // while(true)
    // {
    //     if(i < 0)
    //     {
    //         break;
    //     }
    //     test[i++] = 5;
    //
    // }

    uint8_t input;
    while(true)
    {
        clearConsole();
        print("\e[H");
        println("Arrows to move");
        println("1. Player vs Player");
        println("2. Player vs Computer");
        println("3. Settings");
        println("4. Credits");
        println("5. Quit (not really hahahahaha)");

        while(!input_getNext(&input_buf, &input))
        {
            __WFI();
        }

        bool should_quit = false;
        switch(input)
        {
            case '1':
                game_run(PVP);
                break;
            case '2':
                game_run(PVE);
                break;
            case '3':
                menu_todo();
                break;
            case '4':
                menu_todo();
                break;
            case '5':
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
