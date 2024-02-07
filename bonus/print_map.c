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

    if ((map_o[i][j] == 'O' || map_o[i][j] == 'T' || map_o[i][j] == 't') && map[i][j] != 'X' && map[i][j] != 'P' && map[i][j] != 'p') {
        if (map_o[i][j] == 'T')
            attron(COLOR_PAIR(3));
        if (map_o[i][j] == 't')
            attron(COLOR_PAIR(4));
        mvprintw((LINES / 2) - (lines / 2) + i,
            (COLS / 2) - (columns / 2) + j, &map_o[i][j]);
        attron(COLOR_PAIR(2));
    } else {
        if (map[i][j] == 'p') {
            attron(COLOR_PAIR(5));
            mvprintw((LINES / 2) - (lines / 2) + i,
                (COLS / 2) - (columns / 2) + j, &map[i][j]);
            attron(COLOR_PAIR(2));
        } else if (map_o[i][j] == 'O' && map[i][j] == 'X') {
            attron(COLOR_PAIR(1));
            mvprintw((LINES / 2) - (lines / 2) + i,
                (COLS / 2) - (columns / 2) + j, &map[i][j]);
            attron(COLOR_PAIR(2));
        } else {
            mvprintw((LINES / 2) - (lines / 2) + i,
                (COLS / 2) - (columns / 2) + j, &map[i][j]);
        }
    }
}

void print_map(char **map, char **map_o, int lines, int columns)
{
    int vals[2];
    int cols[2] = {lines, columns};

    refresh();
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            vals[0] = i;
            vals[1] = j;
            print_good_map(map, map_o, vals, cols);
        }
    }
}
