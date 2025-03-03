# TicTacToe project

Fork of https://github.com/infohoschie/arm-cortex-m0-cmake-start

Students: Simon Blum, Max Rodler, Ben Oeckl, Paul Stöckle

## How to build/run the project
### Using CMake and qemu directly
To build the project using CMake and qemu some dependencies,
which can be found under [dependencies] are required.
#### Linux
```sh
# 1. Configure the cmake project
cmake --preset arm-cortex-m0-unix

# 2. Build the project
cmake --build --preset arm-cortex-m0-unix

# 3. Run the project
qemu-system-arm -M microbit -device loader,file=build-cortex-m0/game.elf -nographic -s -serial mon:stdio
```

#### Windows
!TODO!

### Using the provided Makefile
#### Linux
The provided [Makefile](Makefile) can be used to easily build and run
the project using a single command.
```sh
# Configure, build and run the project
make run

# Configure and build the project
make 

# Remove the build directory
make clean

# Generate doxygen documentation (requires doxygen installed)
make generate_documentation
```

#### Windows
!TODO!

### Using Docker
Docker can be used to build and run the application without the need
for external dependencies. For this you have to options:
#### Use the image from Dockerhub
```sh
# Using DockerHub
docker run definitelynotsimon13/tiktaktoe:latest
# Using GitHub Container Registry
docker run ghcr.io/softwareengineeringone/tiktaktoe:latest
```
#### Build the image locally
```sh
docker build -t [TAGNAME] .
docker run [TAGNAME]
```
## Compile time configurations
The project has a few options that can be changed before compilation.
- Number of rows (default is 4)
- Number of columns (default is 4)
- Ticks per turn (default is 20)
- Tick speed (default is 12, lower is faster)
- Unicode support (default is "ON")
- ASCII Art (default is "ON", may look broken on small screens) 

These can be set by:
### Directly passing to CMake
When configuring the project the default command `cmake --preset arm-cortex-m0-{unix/mingw}` can be
appended by:
- for the number of rows: `[...] --DCELLS_PER_COL=$(NUMBER)`
- for the number of cols: `[...] --DCELLS_PER_ROW=$(NUMBER)`
- for ticks per turn: `[...] --DTICKS_PER_TURN=$(NUMBER)`
- for tick speed: `[...] --DTICK_SPEED=$(NUMBER)`
- for unicode: `[...] --DENABLE_UNICODE=$(ON/OFF)`
- for ascii art: `[...] --DENABLE_ASCII_ART=$(ON/OFF)`
_All options can be combined._


### Using the included Makefile
When using the Makefile to configure/build the project variables can be passed like this:
- for the number of rows: `make ROWS=$(NUMBER)`
- for the number of cols: `make COLS=$(NUMBER)`
- for ticks per turn: `make TICKS_PER_TURN=$(NUMBER)`
- for tick speed: `make TICK_SPEED=$(NUMBER)`
- for unicode: `make UNICODE=$(ON/OFF)`
- for ascii art: `make ASCII_ART=$(ON/OFF)`
_All options can be combined._

Due to the way the Makefile is structured, these may also be passed when using e.g. `make run`.
However please note, that in order for changes to take affect the build directory may have to be deleted.
This can be done using `make clean` or by manually deleting the directory.


## Architecture
See [Architecture.md](Architecture.md)

## Conventions
See [Conventions.md](Conventions.md)

## Dependencies (TODO: CHECK CORRECT)
### Ubuntu/Debian
```sh
sudo apt install gcc-arm-none-eabi cmake qemu-system-arm
```
### Arch
```sh
# Using yay
yay -S gcc-arm-none-eabi-bin cmake qemu-system-arm
# Using paru
paru -S gcc-arm-none-eabi-bin cmake qemu-system-arm
# Using pacman
sudo pacman -S ?GCC? cmake qemu-system-arm
```
!TODO - gcc for arm gotta be in the main repo?
### Nix / NixOS
You can either use the provided [Flake](flake.nix), or add the following
packages:
```nix
gcc-arm-embedded
cmake
qemu
```
### macOS
```sh
brew install gcc-arm-embedded cmake qemu
```
### Windows
TODO/CHECK
