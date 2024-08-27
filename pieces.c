#include "pieces.h"
#include <stdlib.h>

struct Piece *
create_piece(enum PieceType type, enum PieceColor color, vec2 *(*possibilities_func)(const struct Board *, unsigned int, unsigned int))
{
    struct Piece *piece = calloc(1, (sizeof *piece));

    *piece = (struct Piece){.type = type, .color = color, .possibilities = possibilities_func};

    return piece;
}
