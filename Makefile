CMAKE_PRESET := arm-cortex-m0-unix
BUILD_DIR := build-cortex-m0
EXECUTABLE := TikTakToe.elf

# Game configs
ROWS ?= 4
COLS ?= 4

PORT ?= 1234

TICKS_PER_TURN ?= 20
TICK_SPEED ?= 12

UNICODE ?= ON
ASCII_ART ?= ON

# Default target
all: build

$(BUILD_DIR):
	cmake --preset $(CMAKE_PRESET) \
		-DCELLS_PER_COL=$(ROWS) \
		-DCELLS_PER_ROW=$(COLS) \
		-DTICKS_PER_TURN=$(TICKS_PER_TURN) \
		-DTICK_SPEED=$(TICK_SPEED) \
		-DENABLE_UNICODE=$(UNICODE) \
		-DENABLE_ASCII_ART=$(ASCII_ART)


configure: $(BUILD_DIR)

build: $(BUILD_DIR)
	cmake --build --preset $(CMAKE_PRESET)

run: build
	qemu-system-arm -M microbit -device loader,file=$(BUILD_DIR)/$(EXECUTABLE) -nographic -gdb tcp::$(PORT) -serial mon:stdio
	@printf "\e[?25h"

clean:
	rm -rf $(BUILD_DIR)

generate_documentation:
	doxygen Doxyfile 1>/dev/null

clean_documentation:
	rm docs/html docs/rtf docs/man docs/latex -r

cursor:
	@printf "\e[?25h"
	@echo "Cursor should be visible again"

.PHONY: all configure build run clean cursor clean_documentation generate_documentation
