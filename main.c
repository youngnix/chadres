#include "board.h"
#include "pieces.h"
#include <stdio.h>

static void
draw_piece(struct Piece *piece)
{
	const char *color_code = piece->color ? "\033[1;39m" : "\033[1;30m";
	char fmt = 0;

	switch (piece->type)
	{
		case PIECE_KING:
			fmt = 'k';
		break;
		case PIECE_KNIGHT:
			fmt = 'n';
		break;
		case PIECE_PAWN:
			fmt = 'p';
		break;
		case PIECE_BISHOP:
			fmt = 'b';
		break;
		case PIECE_QUEEN:
			fmt = 'q';
		break;
		case PIECE_ROOK:
			fmt = 'r';
		break;
			default:
		break;
	}

	printf("%s%c\033[m", color_code, fmt);
}

int
main(void)
{
    struct Board board;

    board_init(&board);

    int checker_state = 0;

    for (unsigned int i = 0; i < BOARD_SQRT; i++)
    {
        for (unsigned int j = 0; j < BOARD_SQRT; j++)
        {
            struct Piece *piece = board.squares[i * BOARD_SQRT + j];

            if (checker_state)
            {
                printf("\033[42m");
            }
            else
            {
                printf("\033[47m");
            }

            if (piece)
            {
                draw_piece(piece);
            }
            else
            {
                printf(" ");
            }

            printf("\033[m");

            checker_state = !checker_state;
        }

        checker_state = !checker_state;
        printf("\n");
    }
}
