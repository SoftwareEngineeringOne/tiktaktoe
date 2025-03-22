# 🎮 TikTakToe

<div style="visibility:hidden">[TOC]</div>

[![MPL-2.0 License](https://img.shields.io/github/license/SoftwareEngineeringOne/tiktaktoe
)](https://choosealicense.com/licenses/mpl-2.0/)
![microcontroller](https://img.shields.io/badge/microcontroller-nRF51-blue?logo=nordicsemiconductor
)
![cpu](https://img.shields.io/badge/cpu-cortex--m0-darkgreen?logo=arm
)
![Release](https://img.shields.io/github/v/release/SoftwareEngineeringOne/tiktaktoe
)
![Image Size](https://img.shields.io/docker/image-size/definitelynotsimon13/tiktaktoe
)

A TikTakToe game written for the `nRF-51` microcontroller with an `arm-cortex-m0` CPU.

## ✨ Features

- 🎮 **PVP and PVE modes**
- 🖥️ **Cross-Platform Compatibility**
- ⚙️ **Highly Customizable**
- 🐳 **Docker Support for 0 dependency execution**

## 📚 Documentation

Check out our [documentation](https://tiktaktoe.episko.de) to learn more about
the code and for an improved version of this file!

## 🛠️ Build and Run

### 🖥️ Using CMake and qemu

To build the project using CMake and qemu some dependencies,
which can be found under [dependencies](#dependencies) are required.

<div class="tabbed">

- <b class="tab-title"> 🐧 Linux </b>

    ```sh
    # 1. Configure the cmake project
    cmake --preset arm-cortex-m0-unix

    # 2. Build the project
    cmake --build --preset arm-cortex-m0-unix

    # 3. Run the project
    qemu-system-arm -M microbit -device loader,file=build-cortex-m0/TikTakToe.elf -nographic -s -serial mon:stdio
    ```

- <b class="tab-title"> 🪟 Windows </b>

    ```pwsh
    # 1. Configure the cmake project
    cmake --preset arm-cortex-m0-mingw

    # 2. Build the project
    cmake --build --preset arm-cortex-m0-mingw

    # 3. Run the project
    qemu-system-arm -M microbit -device loader,file=build-cortex-m0/TikTakToe.elf -nographic -s -serial mon:stdio
    ```

    @warning
        Due to a problem with the `TIMER` device on Windows, functionality regarding turn time limits
        are disabled when building with the MinGW generator!

</div>

### 🛠️ Using the provided Makefile

<div class="tabbed">

- <b class="tab-title"> 🐧 Linux </b>

    The provided Makefile can be used to easily build and run
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

- <b class="tab-title"> 🪟 Windows </b>

    The provided Makefile was created with Linux in mind, while it may be possible
    to use it on Windows with small modifications, we recomend using CMake directly!

</div>

### 🐳 Using Docker

Docker can be used to build and run the application without the need
for external dependencies. For this you have to options:

#### ☁️ Use Dockerhub

```sh
# Using DockerHub
docker run -it definitelynotsimon13/tiktaktoe:latest
# Using GitHub Container Registry
docker run -it ghcr.io/softwareengineeringone/tiktaktoe:latest
```

#### 🏗️ Build locally

```sh
docker build -t [TAGNAME] .
docker run -it [TAGNAME]
```

@warning
  In either case the `-it` flags are required to properly
  capture input from stdin!

### 🍎 MacOS

We are currently unable to test the game under MacOS. Since it's unix based, it's assumed that,
provided all dependencies are available, you can proceed as described in the Linux sections.

However no guarantees regarding functionality or possible bugs can be made.

## ⚙️ Configuration

The project has a few options that can be changed before compilation.

- Number of rows (default is 4)
- Number of columns (default is 4)
- Ticks per turn (default is 20)
- Tick speed (default is 12, lower is faster)
- Unicode support (default is "ON")
- ASCII Art (default is "ON", may look broken on small screens)

@warning
    No restrictions have been set on any of the configurations. Beware that extrem
    deviation from the default values, may result in a degraded playing experience

These can be set by:

<div class="tabbed">

- <b class="tab-title"> Using CMake </b>

    When configuring the project the default command `cmake --preset arm-cortex-m0-{unix/mingw}` can be
    appended by:

  - for the number of rows: `[...] -DCELLS_PER_COL=$(NUMBER)`
  - for the number of cols: `[...] -DCELLS_PER_ROW=$(NUMBER)`
  - for ticks per turn: `[...] -DTICKS_PER_TURN=$(NUMBER)`
  - for tick speed: `[...] -DTICK_SPEED=$(NUMBER)`
  - for unicode: `[...] -DENABLE_UNICODE=$(ON/OFF)`
  - for ascii art: `[...] -DENABLE_ASCII_ART=$(ON/OFF)`

  _All options can be combined._

- <b class="tab-title"> Using the Makefile </b>

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

</div>


## 📦 Dependencies 
<div class="tabbed">

- <b class="tab-title"> Ubuntu/Debian </b>

    ```bash
    sudo apt install gcc-arm-none-eabi cmake qemu-system-arm
    ```

- <b class="tab-title"> Nix / NixOS </b>

    You can either use the provided Flake, or add the following
    packages:

    ```text
    gcc-arm-embedded
    cmake
    qemu
    ```

- <b class="tab-title"> Arch </b>

    ```bash
    sudo pacman -S arm-none-eabi-gcc cmake qemu-system-arm
    ```

- <b class="tab-title"> MacOS </b>

    ```bash
    brew install gcc-arm-embedded cmake qemu
    ```

- <b class="tab-title"> Windows </b>

    - [CMake](https://cmake.org/download/)
      ```pwsh
      # Using Winget
      winget install CMake.CMake

      # Using Chocolatey
      choco install cmake --pre 

      # Or manually using the link above
      ```

    - MinGW Makefiles (we recommend using MSYS2, but other prebuilt options are available)
        1. Install [MSYS2](https://www.msys2.org/#installation)
        2. Open `MSYS2 UCRT64` shell
        3. Install Make `pacman -S mingw-w64-ucrt-x86_64-make`
        4. Ensure `C:\msys64\ucrt64\bin` is added to `PATH`
            - _Directory may differ based on your choice during installation_

    - [Qemu](https://www.qemu.org/download/#windows)
        1. Install [MSYS2](https://www.msys2.org/#installation)
        2. Open `MSYS2 UCRT64` shell
        3. Install Make `pacman -S mingw-w64-ucrt-x86_64-qemu`
        4. Ensure `C:\msys64\ucrt64\bin` is added to `PATH`
            - _Directory may differ based on your choice during installation_

    - [GNU Toolchain for arm-eabi](https://gnutoolchains.com/arm-eabi/)
        1. Install from link above
        2. Ensure installation location is added to `PATH`
</div>

## 🏗️ Architecture

To learn more about the the architecture we used to create this game check out [Architecture.md](Architecture.md)!

## 📜 Conventions

If you want to know about the coding convection we used when creating code check out [Conventions.md](Conventions.md)!

## 👥 Authors

- [Simon Blum](https://www.github.com/DefinitelyNotSimon13)
- [Ben Oeckl](https://github.com/benoeckl)
- [Paul Stöckle](https://github.com/DosKobold)
- [Max Rodler](https://github.com/MaxRodler)

## 🙏 Acknowledgements

- [arm-cortex-m0-cmake-start](https://github.com/infohoschie/arm-cortex-m0-cmake-start) - Base template used for the project

