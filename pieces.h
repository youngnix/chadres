#pragma once

#include "board.h"
#include "util.h"

enum PieceType
{
    PIECE_PAWN,
    PIECE_ROOK,
    PIECE_KNIGHT,
    PIECE_BISHOP,
    PIECE_QUEEN,
    PIECE_KING,
    PIECE_TYPE,
};

/** @struct Piece
 *  @brief Chess pieces
 *  @var Piece::color
 *  Used for determining the piece's color. Use 'false' or 0 for black and 'true' or 1 for white.
 */
struct Piece
{
    enum PieceType type;
    int color;
};

struct Piece *piece_create(enum PieceType type, int color);
