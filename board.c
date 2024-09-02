#include "board.h"
#include "pieces.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void
board_place(struct Board *const board, char piece, unsigned int x, unsigned int y)
{
    struct Piece **square = &board->squares[y * BOARD_SQRT + x];

    enum PieceType type;
    int color;

    if (islower(piece))
    {
        color = 1;
    }

    switch (piece)
    {
    case 'q':
    case 'Q':
        type = PIECE_QUEEN;
        break;
    case 'r':
    case 'R':
        type = PIECE_ROOK;
        break;
    case 'b':
    case 'B':
        type = PIECE_BISHOP;
        break;
    case 'k':
    case 'K':
        type = PIECE_KING;
        break;
    case 'n':
    case 'N':
        type = PIECE_KNIGHT;
        break;
    case 'P':
    case 'p':
        type = PIECE_PAWN;
        break;
    default:
        return;
        break;
    }

    *square = piece_create(type, color);
}

void
board_init(struct Board *board)
{
    board->squares = calloc(BOARD_SQRT * BOARD_SQRT, (sizeof board->squares));

    for (unsigned int i = 0; i < strlen(BOARD_ARRANGEMENT); i++)
    {
        board_place(board, BOARD_ARRANGEMENT[i], i % BOARD_SQRT, i / BOARD_SQRT);
    }
}
