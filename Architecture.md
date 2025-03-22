# 🏗️ Architecture

<div style="visibility:hidden">[TOC]</div>

This project is an embedded application, designed to run on an `nRF51` microcontroller with an
`arm-cortex-m0` CPU. The architecture is seperated into three main layers; the hardware abstraction layer,
the logic layer and the presentation layer. Additionally modules for the entry process and utility functions
exist. This encapsulation allows for a flexible design.

## 🚪 Entry Module

_files: entry/entry.S, entry/linker_script.ls_

This module is responsible for the startup process of the microcontroller. Here important
elements, such as the entry point, interrupt vector table and memory regions are defined
and actions such as copying data from ROM to RAM are performed.

## 📟 Hardware Abstraction Layer

_files: include/hal/\*.h, src/hal/\*.c_

The hardware abstraction layer, short hal, abstracts low level operations such as register access and encapsulates
these operations, allowing the layers above to refrain from interacting with any of the peripherals directly.

## 🧩 Logic Layer

_files: include/logic/\*.h, src/logic/\*.c_

Within this layer, the game logic itself resides. Here you can find the main game
loop, the timer and the game state.

## 🖥️ Presentation Layer

_files: include/presentation/\*.h, src/presentation/\*.c_

This layer contains everything used to display a pretty output to the user.
Menus, ui and styling can all be found here.

The seperation from the logic layer allows for flexible configuration, such as
changing field sizes during the game.

## 🛠️ Utility Layer

_files: include/util/\*.h, src/util/\*.c_

Modules used throughout the layer, or which can't be directly assigned to one
certain layer can be found here.

## ➕ Other relevant files

- config.h.in / config.h
  - The `config.h.in` file is used for the compile time configurations and is processed
    into `config.h` by CMake
- entry-S.c
  - Since Doxygen can't parse assembly files, the `entry.S` file is converted to
    stubbed C file by a helper script, which can then be parsed.
- main.c
  - The main file for the game itself, containing the `main()` function which is invoked by the `Reset_Handler`
