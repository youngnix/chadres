#include "board.h"
#include "pieces.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    struct Board board;

    board_init(&board);

    for (unsigned int i = 0; i < BOARD_SQUARED; i++)
    {
        for (unsigned int k = 0; k < BOARD_SQUARED; k++)
        {
            const struct Piece *piece = board.squares[i * 8 + k];

            if (piece)
            {
                switch (piece->type)
                {
                case PIECE_BISHOP:
                        printf("%s", piece->color ? "B" : "b");
                    break;
                case PIECE_KNIGHT:
                        printf("%s", piece->color ? "N" : "n");
                    break;
                case PIECE_ROOK:
                        printf("%s", piece->color ? "R" : "r");
                    break;
                case PIECE_QUEEN:
                        printf("%s", piece->color ? "Q" : "q");
                    break;
                case PIECE_KING:
                        printf("%s", piece->color ? "K" : "k");
                    break;
                case PIECE_PAWN:
                        printf("%s", piece->color ? "P" : "p");
                    break;
                default:
                    break;
                }

                continue;
            	// Checkerboard pattern
            } else if ((i * BOARD_SQUARED + k + i % 2) % 2)
            {
                printf("#");
            }
            else
            {
                printf("+");
            }
        }
        printf("\n");
    }
}
