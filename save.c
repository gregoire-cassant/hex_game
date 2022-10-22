#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "game.h"
#include "board.h"

// Partie Optionnel du projet: sauvegarde de partie.

extern int _size;

linked_t *read_saves()
{
    DIR *dp = opendir(".");
    if (!dp)
    {
        perror(".");
        return NULL;
    }

    struct dirent *ep;

    linked_t *link_list = malloc(sizeof(linked_t));
    linked_t *first_node = link_list;

    while (ep = readdir(dp))
    {
        if (strncmp(ep->d_name, ".hex-save", 9) == 0)
        {
            linked_t *new_node = malloc(sizeof(linked_t));
            new_node->item = strdup(ep->d_name);
            new_node->next = NULL;

            link_list->next = new_node;
            link_list = link_list->next;
        }
    }

    closedir(dp);

    return first_node->next;
}

char *open_save(char *save_path)
{
    int fd;
    char buffer[20] = {'\0'};
    int f_size = 0;
    int size = 1;

    // get file size for malloc
    fd = open(save_path, O_RDONLY);
    while (size)
    {
        size = read(fd, buffer, 20);
        f_size += size;
    }
    close(fd);
    //

    char *save_content = malloc(sizeof(char) * (f_size + 1));
    for (int i = 0; i < f_size + 1; i++)
        save_content[i] = '\0';

    fd = open(save_path, O_RDONLY);
    read(fd, save_content, f_size);

    close(fd);

    return save_content;
}

int inputUserSaveNumber(int max)
{
    int number = max;
    printf("Select a save number: (e.g. 0)\n");
    scanf("%d", &number);
    flushStdin();
    goto check;

choose_correct_number:
    printf("Select a valid save number: (e.g. 0)\n");
    scanf("%d", &number);
    flushStdin();
    goto check;

check:
    if (number >= max)
    {
        goto choose_correct_number;
    }

    return number;
}

char *save_game(color **board, char *file_name)
{
    int fd;
    int size = _size;

    if (file_name[0] == '\0')
    {
        int size = _size;

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(file_name, ".hex-save_%d-%02d-%02d_%02d:%02d:%02d",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

        fd = open(file_name, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        close(fd);
    }

    fd = open(file_name, O_RDONLY | O_WRONLY | O_TRUNC);

    char size_chr[200] = {'\0'};
    sprintf(size_chr, "%d", size);

    write(fd, size_chr, strlen(size_chr));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char color[2];
            color[0] = ';';
            color[1] = board[i][j] + '0';

            write(fd, color, 2);
        }
    }

    close(fd);

    return file_name;
}

color **create_board_from_save(char *save)
{
    int size = atoi(save);
    _size = size;

    int index = 0;
    while (save[index] != ';')
        index++;
    index++;

    color **board = createBoard();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = atoi(&(save[index]));
            index += 2;
        }
    }

    return board;
}

int print_saves(linked_t *saves)
{
    int i = 0;

    while (saves != NULL)
    {
        printf(PURPLE("\tsave number: %d (%s)"), i, saves->item);
        saves = saves->next;
        i++;
    }

    return i;
}

void load(hIA opponent)
{
    linked_t *saves = read_saves();
    system("clear");

    if (saves == NULL)
    {
        printf(RED("There are no saved games."));
        printf("Press ENTER to return to Main Menu.\n");
        flushStdin();
        return;
    }
    else
        printf(RED("Saves:"));

    int nb_saves = print_saves(saves);
    int chosen_index = inputUserSaveNumber(nb_saves);
    char *save;

    for (int i = 0; i < nb_saves; i++)
    {
        if (i == chosen_index)
        {
            save = open_save(saves->item);
            break;
        }
        saves = saves->next;
    }

    color **saved_board = create_board_from_save(save);

    // send the save_name so that it remains in the same save file
    newGame(opponent, saved_board, saves->item);
}