/**
 * @file 
 *
 * @author 
 *
 * @date 
 *
 * @brief 
 *
 * @see 
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
#include "def.h"
#include "hal_high/input_buf.h"
#include "hal_low/nvic.h"
#include "hal_low/random.h"
#include "hal_low/uart.h"
#include "logic/game.h"
#include "presentation/print.h"
#include "presentation/style.h"

void menu_todo()
{
    print_clearConsole();
    println("Not yet implemented, any key to continue...");
    while(input_isEmpty(&input_buf))
    {
        __WFI();
    }
}

static char *HEADING = "\
.___________. __   __  ___ .___________.    ___       __  ___ .___________.  ______    _______  \n\
|           ||  | |  |/  / |           |   /   \\     |  |/  / |           | /  __  \\  |   ____| \n\
`---|  |----`|  | |  '  /  `---|  |----`  /  ^  \\    |  '  /  `---|  |----`|  |  |  | |  |__    \n\
    |  |     |  | |    <       |  |      /  /_\\  \\   |    <       |  |     |  |  |  | |   __|   \n\
    |  |     |  | |  .  \\      |  |     /  _____  \\  |  .  \\      |  |     |  `--'  | |  |____  \n\
    |__|     |__| |__|\\__\\     |__|    /__/     \\__\\ |__|\\__\\     |__|      \\______/  |_______| \n\
_______________________________________________________________________________________________\n\
";

int main(void)
{
    uart_init(true);
    input_init(&input_buf);

    print(HIDE_CURSOR);
    uint8_t input;
    while(true)
    {
        print_clearConsole();
        print(BOLD);
        print(FG_GREEN);
        print(HEADING);
        print("\e[1E");
        print(RESET);
        print(BOLD);
        println("Choose your option:\n");
        print(RESET);
        println("\t1. Player vs Player");
        println("\t2. Player vs Computer");
        println("\t3. Settings");
        println("\t4. Credits");
        println("\t5. Quit (not really hahahahaha)");

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
