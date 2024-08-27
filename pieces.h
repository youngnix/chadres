#pragma once

#include "board.h"
#include "util.h"
enum PieceType
{
    PIECE_PAWN,
    PIECE_ROOK,
    PIECE_KING,
    PIECE_KNIGHT,
    PIECE_QUEEN,
    PIECE_BISHOP,
    PIECE_TYPE_COUNT,
};

enum PieceColor
{
    PIECE_BLACK,
    PIECE_WHITE,
    PIECE_COLOR_COUNT,
};

struct Piece
{
    enum PieceType type;
    unsigned char color;
	vec2 *(*possibilities)(const struct Board *, unsigned int, unsigned int);
};

struct Piece *create_piece(enum PieceType type, enum PieceColor color, vec2 *(*possibilities_func)(const struct Board *, unsigned int, unsigned int));
