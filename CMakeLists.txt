# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required( VERSION 3.22 )

project( arm_cortex_m0_start LANGUAGES ASM C )

# Define all Files:
add_executable( testApp )

target_sources(
  testApp
  PRIVATE
    entry.S
    entry_c.h
    entry_c.c
    main.c
    hal_high/nvic.h
    hal_high/random.h
    hal_high/random.c
    hal_high/timer.h
    hal_high/timer.c
    hal_high/uart.h
    hal_high/uart.c
    hal_low/register_access.h
    hal_low/register_access.c
    interrupts/input.h
    interrupts/input.c
    interrupts/time.h
    interrupts/time.c
    output/field.h
    output/field.c
    logic/game.h
    logic/game.c
)

target_link_libraries( testApp PRIVATE gcc )

target_link_options(
  testApp
  PRIVATE
    -Wl,-Map=testApp.map
    -T ${CMAKE_SOURCE_DIR}/linker_script.lds )
set_target_properties(
  testApp
  PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/linker_script.lds )


#####################################################################
# Post Build Commands:
# - extract binary


# To copy out the binary:
#arm-none-eabi-objcopy -O binary base.elf output.bin

add_custom_command(
  TARGET testApp
  POST_BUILD
  COMMAND "${OBJ_COPY}"
  ARGS -O binary $<TARGET_FILE:testApp> $<TARGET_FILE_BASE_NAME:testApp>.bin )

set_target_properties(
  testApp
  PROPERTIES ADDITIONAL_CLEAN_FILES $<TARGET_FILE_BASE_NAME:testApp>.bin )
