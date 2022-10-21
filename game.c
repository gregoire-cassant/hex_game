#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "board.h"
#include "ia.h"

// This is the main file of the project to be completed.
int _size;

void createBoard()
{
    // color **board = malloc(sizeof(color) * size * size);

    // for (int i = 0; i < size; i++)
    // {
    //     color board[i] = malloc(sizeof(color) * size);

    //     for (int j = 0; j < size; j++)
    //     {
    //         board[i][j] = GREY;
    //     }
    // }
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
void inputUser()
{
    printf("Enter a valid cell name (e.g. AA): ");
    int a = getchar();
    int b = getchar();
    flushStdin();
    while (a > 122 || a < 65 || b > 122 || b < 65 || (a < 97 && a > 90) || (b < 97 && b > 90))
    {
        printf("Invalid cell name, please enter a valid cell name (e.g. AA): ");
        a = getchar();
        b = getchar();
        flushStdin();
    }
    // At this point, I guarantee that a,b are integers that correspond to valid cell names
    // that is of the form XY with X and Y two letters, upper or lower; and nothing else.
    // to be completed.
}

// To use upon victory of a player.
// This might need to be completed.
void uponVictory(color c, hIA winner)
{
    system("clear");
    print_board();
    if (winner == IA)
        printf("%s IA WINS !\n", colorToString(c));
    else
        printf("%s WINS !\n", colorToString(c));
    printf("Press ENTER to return to Main Menu.\n");
    flushStdin();
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

    // To remove:
    printf("Not implemented yet, sorry !\n");
    printf("Press ENTER to return to Main Menu.\n");
    flushStdin();
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
