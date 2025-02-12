CMAKE_PRESET := arm-cortex-m0-unix
BUILD_DIR := build-cortex-m0
EXECUTABLE := game.elf

# Default target
all: build

$(BUILD_DIR):
	cmake --preset $(CMAKE_PRESET)

configure: $(BUILD_DIR)

build: $(BUILD_DIR)
	cmake --build --preset $(CMAKE_PRESET)

run: build
	qemu-system-arm -M microbit -device loader,file=$(BUILD_DIR)/$(EXECUTABLE) -nographic -s -serial mon:stdio

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all configure build run clean
