# Architecture

This project is an embedded application, designed to run on an `nRF51` microcontroller with an
`arm-cortex-m0` CPU. The architecture is seperated into three main layers; the hardware abstraction layer,
the logic layer and the presentation layer. Additionally modules for the entry process and utility functions
exist. This encapsulation allows for a flexible design.

## Entry Module
_files: entry/entry.S, entry/linker_script.ls_

This module is responsible for the startup process of the microcontroller. Here important
elements, such as the entry point, interrupt vector table and memory regions are defined
and actions such as copying data from ROM to RAM are performed.


## Hardware Abstraction Layer 
_files: include/hal/\*.h, src/hal/\*.c_

The hardware abstraction layer, short hal, abstracts low level operations such as register access and encapsulates
these operations, allowing the layers above to refrain from interacting with any of the peripherals directly. 

## Logic Layer
_files: include/logic/\*.h, src/logic/\*.c_

Within this layer, the game itself resides. The whole logic is based here.

!TODO!


## Presentation Layer 
_files: include/presentation/\*.h, src/presentation/\*.c_

!TODO!


## Utility Layer
_files: include/util/\*.h, src/util/\*.c_

!TODO!

## Other relevant files

- config.h.in / config.h
    - !TODO!
- !TODO!

