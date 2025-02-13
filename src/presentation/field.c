//
// Created by paul on 2/10/25.
//

#include "presentation/field.h"
#include "hal/uart.h"
#include "presentation/print.h"
#include <stddef.h>
#include <stdint.h>

void output_drawField() {
    const uint8_t row_length = (FIELDS_PER_ROW * FIELD_WIDTH);
    char* divider[row_length + 8];
    char* non_divider[row_length + 8];

    uint8_t offset = 0;
    for(uint8_t i = 0; i < row_length; i++) {
        if(i % ((FIELD_WIDTH)) == 0) {
            divider[i + offset] = "┼";
            non_divider[i + offset] = SIDE;
        } else if(i % ((FIELD_WIDTH) + 1) == 0) {
            divider[i + offset] = "┼";
            non_divider[i + offset] = SIDE;
            offset++;
            i--;
        } else {
            divider[i + offset] = TOP_BOTTOM;
            non_divider[i + offset] = " ";
        }
         
        
    }

    divider[row_length] = "\0";
    non_divider[row_length] = "\0";

    for(uint8_t y = 0; y < FIELDS_PER_COL; y++) {
        println(divider);
        println(non_divider);
        println(divider);
    }


}

/* void updateField(Field field) { */
/*         for (uint8_t row = 0; row < FIELD_HEIGHT; row++) { */
/*             for (uint8_t col = 0; col < FIELD_WIDTH; col++) { */
/*                 assignChar(row, col, field.top, field.left, field.color); */
/*             } */
/*         } */
/* } */
/**/
/* void output_changeFieldColor(Field field, char* color) { */
/*     field.color = color; */
/*     updateField(field); */
/* } */
/**/
/* void output_initFields() { */
/*     for (uint8_t row = 0; row < FIELDS_PER_ROW; row++) { */
/*         for (uint8_t col = 0; col < FIELDS_PER_COL; col++) { */
/*             char* color = NULL; */
/*             if(row == 1 && col == 3) { */
/*                 color = FG_GREEN; */
/*             } */
/*             fields[row][col] = */
/*                     (Field){.top = (row * FIELD_HEIGHT), .left = (col * FIELD_WIDTH), .color = color}; */
/**/
/*         updateField(fields[row][col]); */
/*         } */
/*     } */
/**/
/* } */
/**/
/* void assignChar(uint8_t row, uint8_t col, uint16_t top, uint16_t left, char *color) { */
/*     char *symbol; */
/*     if (row == 0 && col == 0) { */
/*         symbol = CORNER_TOP_LEFT; */
/*     } else if (row == 0 && col == (FIELD_WIDTH - 1)) { */
/*         symbol = CORNER_TOP_RIGHT; */
/*     } else if (row == (FIELD_HEIGHT - 1) && col == 0) { */
/*         symbol = CORNER_BOTTOM_LEFT; */
/*     } else if (row == (FIELD_HEIGHT - 1) && col == (FIELD_WIDTH - 1)) { */
/*         symbol = CORNER_BOTTOM_RIGHT; */
/*     } else if (row == 0 || row == (FIELD_HEIGHT - 1)) { */
/*         symbol = TOP_BOTTOM; */
/*     } else if (col == 0 || col == (FIELD_WIDTH - 1)) { */
/*         symbol = SIDE; */
/*     } else { */
/*         symbol = " "; */
/*     } */
/**/
/*     displayed_chars[row + top][col + left] = (StyledChar){ */
/*         .symbol = symbol, */
/*         .color = color, */
/*     }; */
/* } */
/**/
/* void output_drawField() { */
/*     for (uint8_t i = 0; i < FIELDS_PER_ROW * FIELD_HEIGHT; i++) { */
/*         for (uint8_t j = 0; j < FIELDS_PER_COL * FIELD_WIDTH; j++) { */
/*             StyledChar c = displayed_chars[i][j]; */
/*             if (c.color != NULL) { */
/*                 print(c.color); */
/*                 print(c.symbol); */
/*                 print(RESET); */
/*             } else { */
/*                 print(c.symbol); */
/*             } */
/*         } */
/*         print("\n"); */
/*     } */
/* } */
