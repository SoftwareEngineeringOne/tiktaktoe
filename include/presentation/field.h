#ifndef FIELD_H
#define FIELD_H

#include <stddef.h>

#define CELLS_PER_ROW 4
#define CELLS_PER_COL 4

#define FIELD_X_OFFSET 1
#define FIELD_Y_OFFSET 2

#define UNICODE// if not UNICODE then ascii automatically

#ifdef UNICODE
#define CORNER_TOP_LEFT "╭"
#define CORNER_BOT_LEFT "╰"
#define CORNER_TOP_RIGHT "╮"
#define CORNER_BOT_RIGHT "╯"

#define T_LEFT "├"
#define T_RIGHT "┤"
#define T_TOP "┬"
#define T_BOT "┴"

#define CROSS "┼"

#define SIDE "│"
#define TOP_BOTTOM "─"
#define EMPTY " "

#define DIAGONAL_FW "╱"
#define DIAGONAL_BW "╲"
#define DIAGONAL_MID "╳"
#else
#define CORNER_TOP_LEFT "+"
#define CORNER_BOT_LEFT "+"
#define CORNER_TOP_RIGHT "+"
#define CORNER_BOT_RIGHT "+"

#define T_LEFT "+"
#define T_RIGHT "+"
#define T_TOP "+"
#define T_BOT "+"

#define CROSS "+"

#define SIDE "|"
#define TOP_BOTTOM "-"
#define EMPTY " "

#define DIAGONAL_FW "/"
#define DIAGONAL_BW "\\"
#define DIAGONAL_MID "X"
#endif

/**
 * @brief Redraw the whole 2D field
 **/
void field_redraw();

/**
 * @brief Print one row
 * @param [in] row
 * String to print
 * @param [in] row_length
 * Length of string
 */
static void printRow(char **row, size_t row_length);

#endif// FIELD_H
