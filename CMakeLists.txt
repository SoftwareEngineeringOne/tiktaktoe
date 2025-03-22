# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

# --- Project Configuration ---
cmake_minimum_required(VERSION 3.22)
project(TikTakToe LANGUAGES ASM C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# --- Options and Variables ---
set(GENERATED_WARNING "!! This file has been generated automatically, any changes may be overridden !!")

set(CELLS_PER_ROW 4 CACHE STRING "Number of cells in each row")
set(CELLS_PER_COL 4 CACHE STRING "Number of cells in each column")

set(TICKS_PER_TURN 20 CACHE STRING "Number of ticks per round")
set(TICK_SPEED 12 CACHE STRING "Speed of each tick in milliseconds")

option(ENABLE_UNICODE "Enable Unicode support" ON)
option(ENABLE_ASCII_ART "Enable ASCII Art" ON)

# As discovered in the lectures, the TIMER device doesn't seem to work on Windows
if(CMAKE_GENERATOR MATCHES "MinGW")
    option(DISABLE_TIMER "Disable timer for MinGW" ON)
    message(WARNING "Timer is disabled for MinGW builds")
else()
    option(DISABLE_TIMER "Disable timer for MinGW" OFF)
endif()

# --- Configure Files ---
configure_file(
    ${CMAKE_SOURCE_DIR}/include/config.h.in
    ${CMAKE_SOURCE_DIR}/include/config.h @ONLY
)

# --- Source Files ---
file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "include/*.h")

# --- Executable Target ---
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

set_target_properties(
    TikTakToe
    PROPERTIES ADDITIONAL_CLEAN_FILES $<TARGET_FILE_BASE_NAME:TikTakToe>.bin)

target_compile_options(TikTakToe PRIVATE -Wall -Wextra -Werror -Wno-unused-parameter)


# --- Post Build Commands ---

find_program(OBJ_COPY "${OBJ_COPY_PATH}") # ${OBJ_COPY_PATH} is defined in toolchain.cmake
if(NOT OBJ_COPY)
    message(FATAL "${OBJ_COPY_PATH} not found")
endif()

# To copy out the binary:
#   arm-none-eabi-objcopy -O binary base.elf output.bin
add_custom_command(
    TARGET TikTakToe
    POST_BUILD
    COMMAND "${OBJ_COPY}"
    ARGS -O binary $<TARGET_FILE:TikTakToe> $<TARGET_FILE_BASE_NAME:TikTakToe>.bin)

# --- Custom Targets ---

# Target to copy compile_commands.json to the project root
add_custom_target(
    copy-compile-commands ALL
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_LIST_DIR}
)


# Format target using clang-format
find_program(CLANG_FORMAT NAMES clang-format)
if(CLANG_FORMAT)
    add_custom_target(
        format ALL
        COMMAND ${CLANG_FORMAT} -i ${HEADERS} ${SOURCES}
        VERBATIM
    )
else()
    message(WARNING "clang-format executable not found, unable to format code")
endif()


# Documentation target using Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYFILE ${PROJECT_SOURCE_DIR}/Doxyfile)
    add_custom_target(
        documentation
        COMMENT "Generating documentation with Doxygen..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        VERBATIM
    )

    find_program(PERL NAMES perl)
    if(PERL)
        add_custom_command(
            TARGET documentation
            PRE_BUILD
            COMMAND "${PROJECT_SOURCE_DIR}/util/asm4doxy.pl"
            ARGS -undoc -od ../entry/entry.S
        )
        if(NOT EXISTS ${PROJECT_SOURCE_DIR}/entry/entry-S.c)
            message(WARNING "If the entry-S.c file does not exist, the documentation target has to be run twice!")
        endif()
    else()
        message(WARNING "Perl not found, unable to generate documentation for Assembly files")
    endif()
else()
    message(WARNING "Doxygen not found, unable to build documentation")
endif()

