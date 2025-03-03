#ifndef SYSTEM_H
#define SYSTEM_H

#define SYS_AIRCR 0xE000ED0C
#define SYS_VECTKEY (0x5FA << 16)
#define SYS_SYSRESETREQ (1 << 2)

#define SYS_POWER 0x40000000
#define SYS_SYSTEMOFF 0x500

void system_softReset();

void system_offMode();

#endif// SYSTEM_H
