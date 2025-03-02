# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.22)

project(game LANGUAGES ASM C)

set(GENERATED_WARNING "!! This file has been generated automatically, any changes may be overridden !!")

set(CELLS_PER_ROW 4 CACHE STRING "Number of cells in each row")
set(CELLS_PER_COL 4 CACHE STRING "Number of cells in each column")
option(ENABLE_UNICODE "Enable Unicode support" ON)

configure_file(
        ${CMAKE_SOURCE_DIR}/include/config.h.in
        ${CMAKE_SOURCE_DIR}/include/config.h @ONLY
)

# Define all Files:
FILE(GLOB_RECURSE SOURCES "src/*.c")
add_executable(game ${SOURCES})

target_sources(
        game
        PRIVATE
        ${CMAKE_SOURCE_DIR}/entry/entry.S
        ${CMAKE_SOURCE_DIR}/entry/entry_c.c
        ${CMAKE_SOURCE_DIR}/entry/entry_c.h
)

target_include_directories(
        game
        PRIVATE
        include
)

target_link_libraries(game PRIVATE gcc)

target_link_options(
        game
        PRIVATE
        -Wl,-Map=game.map
        -T ${CMAKE_SOURCE_DIR}/entry/linker_script.lds)
set_target_properties(
        game
        PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/entry/linker_script.lds)


#####################################################################
# Post Build Commands:
# - extract binary


# To copy out the binary:
#arm-none-eabi-objcopy -O binary base.elf output.bin

add_custom_command(
        TARGET game
        POST_BUILD
        COMMAND "${OBJ_COPY}"
        ARGS -O binary $<TARGET_FILE:game> $<TARGET_FILE_BASE_NAME:game>.bin)

set_target_properties(
        game
        PROPERTIES ADDITIONAL_CLEAN_FILES $<TARGET_FILE_BASE_NAME:game>.bin)
