# Stage 1: Build stage
FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-arm-none-eabi \
    gdb-multiarch \
    cmake \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN cmake --preset arm-cortex-m0-unix && \
    cmake --build --preset arm-cortex-m0-unix

# Stage 2: Runtime stage
FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    qemu-system-arm \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/build-cortex-m0/game.elf /app/game.elf

CMD ["qemu-system-arm", "-machine", "microbit", "-device", "loader,file=/app/game.elf", "-s", "-nographic", "-serial", "mon:stdio"]
