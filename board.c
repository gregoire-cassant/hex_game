#include "types.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// This file should be completed.

// Useful symbols.
// 🟥🔴
// 🔵🟦

// This function is complete, do not modify.
void printCellTop(color c, char a, char b)
{
    if (c == RED)
        printf("/🔴");
    else if (c == BLUE)
        printf("/🔵");
    else
        printf("/%c%c", a, b);
}
// This function is complete, do not modify.
void printCellBot(color c)
{
    if (c == RED)
        printf("\\__");
    else if (c == BLUE)
        printf("\\__");
    else
        printf("\\__");
}

// These 4 functions are complete, do not modify.
void startLineTop()
{
    printf(" 🟥");
}

void endLineTop()
{
    printf("\\🟦 \n");
}

void startLineBot()
{
    printf(" 🟦");
}

void endLineBot()
{
    printf("/🟥 \n");
}

// This function is complete, do not modify.
char numToChar(int n)
{
    if (n < 26)
        return (char)(n + 65);
    else
        return (char)(n - 26 + 97);
}

// TODO: Should be completed.
// As such, it solely print an empty board.
// You should give it extra arguments so that it can print
// the current state of the board.
void print_board(int size, color **board)
{
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
                int a = i - (j + 1) / 2;
                int b = j / 2;

                char row = numToChar(a);
                char col = numToChar(b);

                printCellTop(board[b][a], row, col);
            }
            else
            {
                printCellBot(GREY);
            }
        }
        // closing the last hexagone + blue camp
        endLineTop();
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
            if ((j) % 2 == 1)
            {
                int b = size - 1 - (i - (j + 1) / 2);
                int a = size - 1 - j / 2;
    
                char row = numToChar(a);
                char col = numToChar(b);

                printCellTop(board[b][a], row, col);
            }
            else
            {
                printCellBot(GREY);
            }
        }
        // closing the last hexagone + blue camp
        endLineBot();
    }
    for (int j = 0; j < 3 * size; j++)
        printf(" ");
    printf("🟦🟥\n");
}
