# Architecture
1. Main initializes the program (UART etc.) and prints the first output
2. Infinity loop in main
3. The game is interrupt based. Interrupts are defined in "interrupts". They will call functions in "logic". The logic is based on "hal_high" and "output"

## Hardware Abstraction Layer (hal_high and hal_low)

## Interrupt handling (interrupts)

## Game Logic (logic)

## Output (output)

