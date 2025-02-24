#include "hal_low/nvic.h"

void __WFI(void)
{
    __asm volatile("wfi" ::: "memory");
}