# TicTacToe project

Fork of https://github.com/infohoschie/arm-cortex-m0-cmake-start

Students: Simon Blum, Max Rodler, Ben Oeckl, Paul Stöckle

## How to build/run the project
### Using CMake and qemu directly
To build the project using CMake and qemu some dependencies,
which can be found under [dependencies] are required.

### Using the provided Makefile

### Using Docker
Docker can be used to build and run the application without the need
for external dependencies. For this you have to options:
#### Use the image from Dockerhub
```sh
# Using DockerHub
docker run definitelynotsimon13/tiktaktoe:latest
# Using GitHub Container Registry
docker run
```
#### Build the image locally
```sh
docker build -t [TAGNAME] .
docker run [TAGNAME]
```

ST182165
## Compile time configurations
The project has a few options that can be changed before compilation.
- Number of rows (default is 4)
- Number of columns (default is 4)
- Ticks per turn (default is 20)
- Tick speed (default is 12, lower is faster)
- Unicode support (default is "ON")

These can be set by:
### Directly passing to CMake
When configuring the project the default command `cmake --preset arm-cortex-m0-{unix/mingw}` can be
appended by:
- for the number of rows: `[...] --DCELLS_PER_COL=$(NUMBER)`
- for the number of cols: `[...] --DCELLS_PER_ROW=$(NUMBER)`
- for ticks per turn: `[...] --DTICKS_PER_TURN=$(NUMBER)`
- for tick speed: `[...] --DTICK_SPEED=$(NUMBER)`
- for unicode support: `[...] --DENABLE_UNICODE=$(ON/OFF)`

### Using the included Makefile
When using the Makefile to configure/build the project variables can be passed like this:
- for the number of rows: `make ROWS=$(NUMBER)`
- for the number of cols: `make COLS=$(NUMBER)`
- for ticks per turn: `make TICKS_PER_TURN=$(NUMBER)`
- for tick speed: `make TICK_SPEED=$(NUMBER)`
- for unicode support: `make UNICODE=$(ON/OFF)`
_All options can be combined._

Due to the way the Makefile is structured, these may also be passed when using e.g. `make run`.
However please note, that in order for changes to take affect the build directory may have to be deleted.
This can be done using `make clean` or by manually deleting the directory.


## Architecture
See [Architecture.md](Architecture.md)

## Conventions
See [Conventions.md](Conventions.md)

## Dependencies

