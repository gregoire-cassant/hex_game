#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "board.h"
#include "ia.h"

// This is the main file of the project to be completed.
int _size;

color **createBoard()
{
    int size = _size;

    color **board = malloc(sizeof(color *) * size);

    for (int i = 0; i < size; i++)
    {
        board[i] = malloc(sizeof(color) * size);

        for (int j = 0; j < size; j++)
        {
            board[i][j] = GREY;
        }
    }

    return board;
}

/* Functions used for interfacing with User */

// Do not modify.
char *colorToString(color c)
{
    if (c == RED)
        return "RED";
    else
        return "BLUE";
}

// Do not modify.
void flushStdin()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

// TODO: To be completed
cords inputUser(color **board)
{
    printf("Enter a valid cell name (e.g. AA): ");
    int a = getchar();
    int b = getchar();
    flushStdin();
    int size = _size;
    goto check;

already_taken:
    printf("Cell already taken, please enter another cell name (e.g. AA): ");
    a = getchar();
    b = getchar();
    flushStdin();
    goto check;

not_valid:
    printf("Invalid cell name, please enter a valid cell name (e.g. AA): ");
    a = getchar();
    b = getchar();
    flushStdin();
    goto check;

check:
    if (a >= 65 && a <= 90)
    {
        a = a - 65;
    }
    else if (a >= 97 && a <= 122)
    {
        a = a - 97 + 26;
    }
    else
    {
        goto not_valid;
    }

    if (b >= 65 && b <= 90)
    {
        b = b - 65;
    }
    else if (b >= 97 && b <= 122)
    {
        b = b - 97 + 26;
    }
    else
    {
        goto not_valid;
    }

    if (a >= size || b >= size)
    {
        goto not_valid;
    }

    if (board[b][a] != GREY)
    {
        goto already_taken;
    }

    cords xy = {a, b};

    return xy;
    // At this point, I guarantee that a,b are integers that correspond to valid cell names
    // that is of the form XY with X and Y two letters, upper or lower; and nothing else.
    // to be completed.
}

// To use upon victory of a player.
// This might need to be completed.
void uponVictory(color **board, color c, hIA winner)
{
    int size = _size;
    system("clear");
    print_board(size, board);
    if (winner == IA)
        printf("%s IA WINS !\n", colorToString(c));
    else
        printf("%s WINS !\n", colorToString(c));
    printf("Press ENTER to return to Main Menu.\n");
    flushStdin();
}

void has_won_recursive(color **board, color player, int start, int *found)
{
    int size = _size;

    if (start >= size)
        return;

    if (player == RED)
    {
        for (int i = 0; i < size; i++)
        {
            if (
                (start == 0 && board[start][i] == RED) ||
                (board[start][i] == RED &&
                 (found[i] || (start > 0 && i > 0 && board[start - 1][i - 1] == RED) ||
                  (i > 0 && board[start][i - 1] == RED))))
            {
                found[i] = 1;
            }
            else
            {
                found[i] = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {

            if (
                (start == 0 && board[i][start] == BLUE) ||
                (board[i][start] == BLUE &&
                 (found[i] || (start > 0 && i > 0 && board[i - 1][start - 1] == BLUE) ||
                  (i > 0 && board[i - 1][start] == BLUE))))
            {
                found[i] = 1;
            }
            else
            {
                found[i] = 0;
            }
        }
    }

    has_won_recursive(board, player, start + 1, found);
}

int has_won(color **board, color player)
{
    int size = _size;
    int start = 0;
    int *found = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        found[i] = 0;

    has_won_recursive(board, player, 0, found);

    for (int i = 0; i < size; i++)
    {
        if (found[i])
            return 0;
    }

    free(found);

    return 1;
}

// To be completed:
void newGame(hIA opponent)
{
    // do not modify until ...
    printf("Size of the board: ");
    int size;
    scanf("%d", &size);
    flushStdin();
    // ... here.
    _size = size;

    int playing = 1;
    int curr_player = 0;
    color **board = createBoard();

    print_board(size, board);

    while (playing)
    {
        print_board(size, board);

        printf((curr_player) ? "PLayer 2: " : "PLayer 1: ");
        cords player_cord = inputUser(board);
        board[player_cord.y][player_cord.x] = (curr_player) ? BLUE : RED;
        playing = has_won(board, curr_player);

        curr_player = (curr_player + 1) % 2;
    }

    uponVictory(board, curr_player ? RED : BLUE, HUMAN);
    flushStdin();

    free(board);
    // To remove:
    // printf("Not implemented yet, sorry !\n");
    // printf("Press ENTER to return to Main Menu.\n");
}

// To be completed:
void newIA()
{
    // do not modify until ...
    printf("Size of the board: ");
    int size;
    scanf("%d", &size);
    flushStdin();
    // ... here.
    _size = size;

    createBoard();

    // To remove:
    printf("Not implemented yet, sorry !\n");
    printf("Press ENTER to return to Main Menu.\n");
    flushStdin();
}

// Partie Optionnel du projet: sauvegarde de partie.

void load(hIA opponent)
{
    printf("Not implemented yet, sorry !\n");
    printf("Press ENTER to return to Main Menu.\n");
    flushStdin();
}
