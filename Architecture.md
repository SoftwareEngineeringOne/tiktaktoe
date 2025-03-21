# Architecture

The architecture is interrupt-based and with the use cases package divided.
The program starts at main.c. This file is only used for restarting and
shutting down the system. The program can run infinitely, dependent on the users
actions. Package descriptions are following:

## Hardware Abstraction Layer (`hal`)

The hardware abstraction layer package gives the developer the possibility to
call neutral and machine-independent functions without knowing the hardware
implementation. \
\
A specialty in this package are the interrupts. They make a user and time
action-based system possible. It is the only component that calls functions 
outside the hal.

## Game Logic (`logic`)

The logic package is the most important part of the game. It manages the
process of the game.

## Output (`presentation`)

The presentation package abstracts the whole output that is shown to the user.
It simplifies the UART transmission.

## Utilities (`util`)

The util package includes independent (from another) helpers that are used from
several packages.

RAM Layout (Cortex-M):
0x20000000 ┌────────────────┐
           │     .data      │
           ├────────────────┤
           │     .bss       │
           ├────────────────┤
           │     Heap       │
           ├────────────────┤
           │   Free Space   │
           ├────────────────┤
           │     Stack      │
           │(grows downward)│ 
0x20004000 ├────────────────┤ ← \_\_StackTop (initial SP)
           │                │
           │                │
           ├────────────────┤ ← \_\_StackLimit
           │                │
           └────────────────┘
