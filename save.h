#pragma once

linked_t *read_saves();
char *open_save(char *save_path);
int inputUserSaveNumber(int max);
color **create_board_from_save(char *save);
void load(hIA opponent);
char *save_game(color **board, char *save_name);