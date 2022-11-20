#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "board.h"
#include "save.h"
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

color **copy_board(color **board)
{
    int size = _size;

    color **copy_board = malloc(sizeof(color *) * size);

    for (int i = 0; i < size; i++)
    {
        copy_board[i] = malloc(sizeof(color) * size);

        for (int j = 0; j < size; j++)
        {
            copy_board[i][j] = board[i][j];
        }
    }

    return copy_board;
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
    int size = _size;
    printf("Enter a valid cell name (e.g. AA): ");
    int a = getchar();
    int b = getchar();
    flushStdin();
    goto check;

already_taken:
    printf("This cell is already occupied !");
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

int has_won_rec_helper(color **board_copy, int x, int y, color curr_color)
{
    int size = _size;
    int WALKED_ON = 3;

    if ((int)(board_copy[x][y]) == WALKED_ON)
        return 0;

    if (
        (curr_color == RED && (x == 0 && board_copy[x][y] == curr_color)) ||
        (curr_color == BLUE && (y == 0 && board_copy[x][y] == curr_color)))
    {
        return 1;
    }

    int reached = 0;

    board_copy[x][y] = WALKED_ON;

    if (x > 0 && board_copy[x - 1][y] == curr_color)
        reached = has_won_rec_helper(board_copy, x - 1, y, curr_color);

    if (x < size - 1 && board_copy[x + 1][y] == curr_color)
        reached = reached | has_won_rec_helper(board_copy, x + 1, y, curr_color);

    if (x < size - 1 && y < size - 1 && board_copy[x + 1][y + 1] == curr_color)
        reached = reached | has_won_rec_helper(board_copy, x + 1, y + 1, curr_color);

    if (x > 0 && y > 0 && board_copy[x - 1][y - 1] == curr_color)
        reached = reached | has_won_rec_helper(board_copy, x - 1, y - 1, curr_color);

    if (y > 0 && board_copy[x][y - 1] == curr_color)
        reached = reached | has_won_rec_helper(board_copy, x, y - 1, curr_color);

    if (y < size - 1 && board_copy[x][y + 1] == curr_color)
        reached = reached | has_won_rec_helper(board_copy, x, y + 1, curr_color);

    return reached;
}

int has_won(color **board, color player)
{
    int size = _size;
    int start = size - 1;
    int has_reached_start = 0;

    color **board_copy = copy_board(board);

    for (int i = 0; i < size; i++)
    {
        if (player == RED && board_copy[start][i] == RED)
        {
            has_reached_start = has_reached_start | has_won_rec_helper(board_copy, start, i, RED);
        }

        if (player == BLUE && board_copy[i][start] == BLUE)
        {
            has_reached_start = has_reached_start | has_won_rec_helper(board_copy, i, start, BLUE);
        }
    }

    free(board_copy);

    return !has_reached_start;
}

// To be completed:
void newGame(hIA opponent, color **saved_board, char *save_name)
{
    int size;

    if (saved_board == NULL)
    {
        // do not modify until ...
        printf("Size of the board: ");
        scanf("%d", &size);
        flushStdin();
        // ... here.
        _size = size;
    }
    else
    {
        size = _size;
    }

    int is_playing = 1;
    int curr_player = 0;

    if (save_name == NULL)
    {
        save_name = malloc(sizeof(char) * 30);
        for (int i = 0; i < 30; i++)
            save_name[i] = '\0';
    }

    color **board = saved_board != NULL ? saved_board : createBoard();

    while (is_playing)
    {
        print_board(size, board);
        printf((curr_player) ? ((opponent == IA) ? "Ai: " : "PLayer 2: ") : "PLayer 1: ");
        cords player_cord = (curr_player == 1 && opponent == IA) ? inputIA(BLUE, size, board) : inputUser(board);

        board[player_cord.y][player_cord.x] = (curr_player) ? BLUE : RED;

        is_playing = has_won(board, curr_player);

        curr_player = (curr_player + 1) % 2;

        save_name = save_game(board, save_name);
    }

    // reverse curr_player color because it is switched at the end of the while
    uponVictory(board, curr_player ? RED : BLUE, HUMAN);

    flushStdin();

    free(board);
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
