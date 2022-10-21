#include <stdio.h>
#include "types.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

// This file should not be modified.

void endLineTopMenu()
{
    printf("\\🟦");
}

void endLineBotMenu()
{
    printf("/🟥");
}

void printMenu()
{
    // To print colored text:
    char blue[] = "$(tput setaf 4)";
    char normal[] = "$(tput sgr0)";

    // Printing Menu:
    int size = 20;
    color tab[20][20];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            tab[i][j] = GREY;
    }
    // vertical bars of H
    for (int i = 0; i < 8; i++)
    {
        tab[12 + i][i] = RED;
        tab[12 + i][i + 1] = RED; // double bar
        // tab[10+i][i+2] = RED ; if one bar
        tab[10 + i][i + 3] = RED;
        tab[10 + i][i + 4] = RED;
    }
    // Horizontal bar of H
    /* if one bar
       tab[15][4] = RED ;
    tab[15][5] = RED ;
    tab[14][4] = RED ;
    tab[14][5] = RED ;
    */
    tab[15][5] = RED;
    tab[15][6] = RED;
    tab[14][5] = RED;
    tab[14][6] = RED;
    // horizontal top bar of E
    tab[4][4] = BLUE;
    tab[5][4] = BLUE;
    tab[5][3] = BLUE;
    tab[4][5] = BLUE;
    tab[3][5] = BLUE;
    tab[3][6] = BLUE;
    tab[2][6] = BLUE;
    tab[6][3] = BLUE;
    tab[6][2] = BLUE;
    // vertical bar of E
    for (int i = 0; i < 12; i++)
    {
        tab[7 + i][3 + i] = BLUE;
        tab[7 + i][4 + i] = BLUE;
    }
    // horizontal bot bar of E
    tab[17][15] = BLUE;
    tab[17][16] = BLUE;
    tab[16][16] = BLUE;
    tab[16][17] = BLUE;
    tab[15][17] = BLUE;
    tab[15][18] = BLUE;
    tab[14][18] = BLUE;
    // horizontal middle bar of E
    tab[11][9] = BLUE;
    tab[11][10] = BLUE;
    tab[10][9] = BLUE;
    tab[10][10] = BLUE;
    tab[9][10] = BLUE;
    tab[10][11] = BLUE;
    tab[9][11] = BLUE;
    // X top right to bot left

    tab[8][14] = RED;
    tab[9][14] = RED;
    tab[10][14] = RED;
    tab[7][14] = RED;
    tab[6][14] = RED;
    tab[5][14] = RED;
    tab[4][14] = RED;
    tab[3][14] = RED;
    tab[1][14] = RED;
    tab[2][14] = RED;
    // tab[11][14] = RED ;

    tab[10][15] = RED;
    tab[9][15] = RED;
    tab[8][15] = RED;
    tab[7][15] = RED;
    tab[6][15] = RED;
    tab[5][15] = RED;
    tab[4][15] = RED;
    tab[3][15] = RED;
    tab[2][15] = RED;
    tab[1][15] = RED;
    // tab[11][15] = RED ;

    // X bot right to top left
    // tab[3][8] = RED ;
    // tab[3][9] = RED ;
    tab[5][9] = RED;
    tab[5][10] = RED;
    tab[5][11] = RED;
    tab[5][12] = RED;
    tab[5][13] = RED;
    tab[5][14] = RED;
    tab[5][16] = RED;
    tab[5][17] = RED;
    tab[5][18] = RED;
    // tab[5][8] = RED ;

    tab[6][9] = RED;
    tab[6][10] = RED;
    tab[6][11] = RED;
    tab[6][12] = RED;
    tab[6][13] = RED;
    tab[6][14] = RED;
    tab[6][15] = RED;
    tab[6][16] = RED;
    tab[6][17] = RED;
    tab[6][18] = RED;
    //  tab[6][8] = RED ;

    system("clear");
    // TOP HALF
    for (int j = 0; j < 3 * size; j++)
        printf(" ");
    printf("🟥🟦\n");
    for (int i = 0; i < size; i++)
    {
        // print spaces
        for (int j = 0; j < 3 * size - 3 * i - 3; j++)
            printf(" ");
        // print Red Camp
        startLineTop();
        // print actual Board
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if ((j) % 2 == 0)
            {
                char row = numToChar(i - (j + 1) / 2);
                char col = numToChar(j / 2);
                printCellTop(tab[i - (j + 1) / 2][j / 2], row, col);
            }
            else
            {
                printCellBot(tab[i - (j + 1) / 2][j / 2]);
            }
        }
        // closing the last hexagone + blue camp
        endLineTopMenu();
        // printing spaces after the HEX
        for (int j = 0; j < 3 * size - 3 * i - 3; j++)
            printf(" ");
        printf("\n");
    }
    // BOT HALF
    for (int i = size - 1; i >= 0; i--)
    {
        // print spaces
        for (int j = 0; j < 3 * size - 3 * i - 3; j++)
            printf(" ");
        // print Red Camp
        startLineBot();
        // print actual Board
        for (int j = 0; j < 2 * i + 1; j++)
        {
            int a = size - 1 - j / 2;
            int b = size - 1 - (i - (j + 1) / 2);
            if ((j) % 2 == 1)
            {
                char row = numToChar(a);
                char col = numToChar(b);
                printCellTop(tab[a][b], row, col);
            }
            else
            {
                printCellBot(tab[a][b]);
            }
        }
        // closing the last hexagone + blue camp
        endLineBotMenu();
        // print spaces after the hex
        for (int j = 0; j < 3 * size - 3 * i - 3; j++)
            printf(" ");
        printf("\n");
    }
    for (int j = 0; j < 3 * size; j++)
        printf(" ");
    printf("🟦🟥\n");

    printf("\033[0;31m");
    printf("Main Menu:\n");
    printf("\033[0m");

    printf("\033[0;35m");
    printf("\t\t1. New PvP Game");
    printf("\t\t\t\t2. New PvIA Game");
    printf("\t\t\t3. New IAvIA Game \n");
    printf("\t\t4. Load PvP Game");
    printf("\t\t\t5. Load PvIA Game");
    printf("\t\t\t6. Quit \n");
    printf("\033[0m");
}
