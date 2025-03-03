# Architecture
1. Main initializes the program (UART etc.) and prints the first output
2. Infinity loop in main
3. The game is interrupt based (not really thouh). Interrupts are defined in "interrupts". They will call functions in "logic". The logic is based on "hal" and "output"(also wrong tbh)

## Hardware Abstraction Layer (util and hal)

## Interrupt handling (interrupts)

## Game Logic (logic)

## Output (output)

