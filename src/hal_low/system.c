#include "hal_low/system.h"

#include "def.h"
#include <hal_low/register_access.h>

void system_softReset()
{
    register_write(SYS_AIRCR, SYS_VECTKEY | SYS_SYSRESETREQ);
    // ReSharper disable once CppDFAEndlessLoop
    while(true)
        ;
}


void system_offMode()
{
    register_write(SYS_POWER | SYS_SYSTEMOFF, 1);
    // ReSharper disable once CppDFAEndlessLoop
    while(true)
        ;
}
