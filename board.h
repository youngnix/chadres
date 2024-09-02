#pragma once

#include "pieces.h"

static const unsigned int BOARD_SQRT = 8;
static const char *BOARD_ARRANGEMENT =
    "RNBQKBNR"
    "PPPPPPPP"
    "        "
    "        "
    "        "
    "        "
    "pppppppp"
    "rnbqkbnr";

struct Board
{
    struct Piece **squares;
};

void board_init(struct Board *board);
