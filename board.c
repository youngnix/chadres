#include "board.h"
#include "pieces.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
place_piece(const struct Board *board, const char piece, unsigned int x, unsigned int y)
{
    struct Piece **square = &board->squares[y * 8 + x];

    switch (piece)
    {
    case 'R':
        *square = create_piece(PIECE_ROOK, PIECE_BLACK, NULL);
        break;
    case 'N':
        *square = create_piece(PIECE_KNIGHT, PIECE_BLACK, NULL);
        break;
    case 'B':
        *square = create_piece(PIECE_BISHOP, PIECE_BLACK, NULL);
        break;
    case 'Q':
        *square = create_piece(PIECE_QUEEN, PIECE_BLACK, NULL);
        break;
    case 'K':
        *square = create_piece(PIECE_KING, PIECE_BLACK, NULL);
        break;
    case 'P':
        *square = create_piece(PIECE_PAWN, PIECE_BLACK, NULL);
        break;
    case 'r':
        *square = create_piece(PIECE_ROOK, PIECE_WHITE, NULL);
        break;
    case 'n':
        *square = create_piece(PIECE_KNIGHT, PIECE_WHITE, NULL);
        break;
    case 'b':
        *square = create_piece(PIECE_BISHOP, PIECE_WHITE, NULL);
        break;
    case 'q':
        *square = create_piece(PIECE_QUEEN, PIECE_WHITE, NULL);
        break;
    case 'k':
        *square = create_piece(PIECE_KING, PIECE_WHITE, NULL);
        break;
    case 'p':
        *square = create_piece(PIECE_PAWN, PIECE_WHITE, NULL);
        break;
    default:
        *square = NULL;
        break;
    }
}

void
board_init(struct Board *board)
{
    board->squares = calloc(8 * 8, (sizeof *board->squares));

    for (unsigned int i = 0; i < strlen(BOARD_ARRANGEMENT); i++)
    {
        place_piece(board, BOARD_ARRANGEMENT[i], i % 8, i / 8);
    }
}
