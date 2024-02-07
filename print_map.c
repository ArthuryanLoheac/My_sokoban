/*
** EPITECH PROJECT, 2023
** print_map
** File description:
** print_map
*/
#include <ncurses.h>

void print_good_map(char **map, char **map_o, int vals[2], int cols[2])
{
    int i = vals[0];
    int j = vals[1];
    int lines = cols[0];
    int columns = cols[1];

    if (map_o[i][j] == 'O' && map[i][j] != 'X' && map[i][j] != 'P') {
        mvprintw((LINES / 2) - (lines / 2) + i,
            (COLS / 2) - (columns / 2) + j, &map_o[i][j]);
    } else {
        mvprintw((LINES / 2) - (lines / 2) + i,
            (COLS / 2) - (columns / 2) + j, &map[i][j]);
    }
}

void print_map(char **map, char **map_o, int lines, int columns)
{
    int vals[2];
    int cols[2] = {lines, columns};

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            vals[0] = i;
            vals[1] = j;
            print_good_map(map, map_o, vals, cols);
        }
    }
    refresh();
}
