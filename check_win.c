/*
** EPITECH PROJECT, 2023
** check_win
** File description:
** check_win
*/
#include "my.h"

static int all_line_good(char **map, char **map_o, int columns, int i)
{
    for (int j = 0; j < columns; j++) {
        if (map_o[i][j] == 'O' && map[i][j] != 'X') {
            return 0;
        }
    }
    return 1;
}

int check_win(char **map, char **map_o, int lines, int columns)
{
    for (int i = 0; i < lines; i++) {
        if (all_line_good(map, map_o, columns, i) == 0) {
            return 0;
        }
    }
    return 1;
}
