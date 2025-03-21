# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.22)

project(TikTakToe LANGUAGES ASM C)

set(GENERATED_WARNING "!! This file has been generated automatically, any changes may be overridden !!")

set(CELLS_PER_ROW 4 CACHE STRING "Number of cells in each row")
set(CELLS_PER_COL 4 CACHE STRING "Number of cells in each column")

set(TICKS_PER_TURN 20 CACHE STRING "Number of ticks per round")
set(TICK_SPEED 12 CACHE STRING "Speed of each tick in milliseconds")

option(ENABLE_UNICODE "Enable Unicode support" ON)
option(ENABLE_ASCII_ART "Enable ASCII Art" ON)

configure_file(
        ${CMAKE_SOURCE_DIR}/include/config.h.in
        ${CMAKE_SOURCE_DIR}/include/config.h @ONLY
)

# Define all Files:
FILE(GLOB_RECURSE SOURCES "src/*.c")
add_executable(TikTakToe ${SOURCES})

target_sources(
        TikTakToe
        PRIVATE
        ${CMAKE_SOURCE_DIR}/entry/entry.S
)

target_include_directories(
        TikTakToe
        PRIVATE
        include
)

target_link_libraries(TikTakToe PRIVATE gcc)

target_link_options(
        TikTakToe
        PRIVATE
        -Wl,-Map=TikTakToe.map
        -T ${CMAKE_SOURCE_DIR}/entry/linker_script.ld)
set_target_properties(
        TikTakToe
        PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/entry/linker_script.ld)


#####################################################################
# Post Build Commands:
# - extract binary


# To copy out the binary:
#arm-none-eabi-objcopy -O binary base.elf output.bin

add_custom_command(
        TARGET TikTakToe
        POST_BUILD
        COMMAND "${OBJ_COPY}"
        ARGS -O binary $<TARGET_FILE:TikTakToe> $<TARGET_FILE_BASE_NAME:TikTakToe>.bin)

set_target_properties(
        TikTakToe
        PROPERTIES ADDITIONAL_CLEAN_FILES $<TARGET_FILE_BASE_NAME:TikTakToe>.bin)
