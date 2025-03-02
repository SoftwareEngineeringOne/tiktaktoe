CMAKE_PRESET := arm-cortex-m0-unix
BUILD_DIR := build-cortex-m0
EXECUTABLE := game.elf
ROWS ?= 4
COLS ?= 4
UNICODE ?= ON

# Default target
all: build

$(BUILD_DIR):
	cmake --preset $(CMAKE_PRESET) -DCELLS_PER_COL=$(ROWS) -DCELLS_PER_ROW=$(COLS) -DENABLE_UNICODE=$(UNICODE)

configure: $(BUILD_DIR)

build: $(BUILD_DIR)
	cmake --build --preset $(CMAKE_PRESET)

run: build
	qemu-system-arm -M microbit -device loader,file=$(BUILD_DIR)/$(EXECUTABLE) -nographic -s -serial mon:stdio
	make cursor

clean:
	rm -rf $(BUILD_DIR)

cursor:
	@printf "\e[?25h"
	@echo "Cursor should be visible again"

.PHONY: all configure build run clean cursor
