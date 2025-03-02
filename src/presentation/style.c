#include "presentation/style.h"

const Style DEFAULT_BOLD = {
    .font_style = BOLD,
};

const Style DEFAULT_ITALIC = {
    .font_style = ITALIC,
};

const Style DEFAULT_DIM = {
    .font_style = DIM,
};

const Style BOLD_DIM = {
    .font_style = BOLD,
    .fg_color = DIM,
};

const Style ITALIC_DIM = {
    .font_style = ITALIC,
    .fg_color = DIM,
};

const Style DEFAULT_CIRCLE = {
    .fg_color = FG_MAGENTA,
};

const Style BOLD_CIRCLE = {
    .fg_color = FG_MAGENTA,
    .font_style = BOLD,
};

const Style DEFAULT_CROSS = {
    .fg_color = FG_GREEN,
};

const Style BOLD_CROSS = {
    .fg_color = FG_GREEN,
    .font_style = BOLD,
};

const Style HEADING_STYLE = {
    .fg_color = FG_BLUE,
    .font_style = BOLD,
};
