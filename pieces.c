#include "pieces.h"
#include "board.h"
#include <stdlib.h>

struct Piece *
piece_create(enum PieceType type, int color)
{
    struct Piece *piece = calloc(1, (sizeof *piece));

    *piece = (struct Piece){.type = type, .color = color};

    return piece;
}
