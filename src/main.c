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
#include "hal/nvic.h"
#include "hal/random.h"
#include "hal/uart.h"
#include "presentation/print.h"
#include "presentation/style.h"
#include "presentation/ui.h"
#include "util/input_buf.h"

#include "hal/system.h"
#include "presentation/menu.h"

int main(void)
{
    uart_init(true);
    input_init(&g_input_buf);

    if(menu_showMainMenu())
    {
        print_clearConsole();
        ui_printHeading();
        println_styled("The game will be reset...", &DEFAULT_BOLD);
        println_styled("Press any key to continue...", &ITALIC_DIM);

        static uint8_t input;
        while(!input_getNext(&g_input_buf, &input))
        {
            __WFI();
        }
        system_softReset();
    }
    else
    {
        print_clearConsole();
        ui_printHeading();
        println_styled("Thanks for playing!", &DEFAULT_BOLD);
        println_styled(
            "Hint: If you are using the qemu emulator, you can exit using \"<CTR> + a,  x\".\n",
            &ITALIC_DIM);
        print(SHOW_CURSOR);
        system_offMode();
    }
}
