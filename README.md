# TicTacToe project

Fork of https://github.com/infohoschie/arm-cortex-m0-cmake-start

Students: Simon Blum, Max Rodler, Ben Oeckl, Paul Stöckle

## Architecture description
1. Main initializes the program (UART etc.) and prints the first output
2. Infinity loop in main
3. The game is interrupt based. Interrupts are defined in "interrupts". They will call functions in "logic". The logic is based on "hal_high" and "output"

### Hardware Abstraction Layer (hal_high and hal_low)

### Interrupt handling (interrupts)

### Game Logic (logic)

### Output (output)

## Coding Conventions
- Conventional Commits (https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)
- The architecture is documented in this README
- Every file must have a short description at the beginning
- Every function must have a doc comment with a short description
- Not self describing code must be commented
- Public functions start with the package name followed by an underscore
- Private functions should therefore not be called from outside
- Private functions should follow the public functions in the header files