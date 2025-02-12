//
// Created by paul on 2/10/25.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <presentation/field.h>
#include <presentation/print.h>

void output_drawField() {
    const uint8_t length = 2*FIELD_SIZE+2;
    char horizontal[length];
    char vertical[length];

    for (uint8_t x = 0; x < length; x++) {
        horizontal[x] = (x%2) ? '-' : '+';
        vertical[x] = (x%2) ? ' ' : '|';
    }
    horizontal[length-1] = '\0';
    vertical[length-1] = '\0';

    for (uint8_t y = 0; y < FIELD_SIZE; y++) {
        println(horizontal);
        println(vertical);
        println(horizontal);
    }
}