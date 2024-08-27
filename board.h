#pragma once

#include "pieces.h"
#include "util.h"

static const unsigned int BOARD_SQUARED = 8;
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
