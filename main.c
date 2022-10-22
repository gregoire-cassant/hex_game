#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "save.h"
#include "board.h"
#include "menu.h"
#include "game.h"

// This file should not be modified.
int main()
{
    char answer = 0;
    while (answer != '6')
    {
        system("clear"); // Clear Terminal
        printMenu();
        printf("Enter the number corresponding to your choice: ");
        answer = getchar();
        flushStdin();
        if (answer == '1')
            newGame(HUMAN, NULL, NULL);
        else if (answer == '2')
            newGame(IA, NULL, NULL);
        else if (answer == '3')
            newIA();
        else if (answer == '4')
            load(HUMAN);
        else if (answer == '5')
            load(IA);
    }
}
