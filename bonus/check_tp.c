/*
** EPITECH PROJECT, 2023
** check_tp
** File description:
** check_tp
*/
#include "sokoban.h"
#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

void check_tp(char **map, char **map_o, int lines, int columns)
{
    int x = player_x(map, lines, columns);
    int y = player_y(map, lines, columns);
    int x_tp = get_x_tp(map_o, lines, columns);
    int y_tp = get_y_tp(map_o, lines, columns);
    int x_tp_two = get_x_tp_two(map_o, lines, columns);
    int y_tp_two = get_y_tp_two(map_o, lines, columns);

    if (map_o[y][x] == 'T') {
        if (y == y_tp && x == x_tp && map[y_tp_two][x_tp_two] == ' ') {
            map[y_tp_two][x_tp_two] = 'P';
            map[y][x] = ' ';
        } else if (map[y_tp][x_tp] == ' '){
            map[y_tp][x_tp] = 'P';
            map[y][x] = ' ';
        }
    }
}

void check_tp_two(char **map, char **map_o, int lines, int columns)
{
    int x = player_x_two(map, lines, columns);
    int y = player_y_two(map, lines, columns);
    int x_tp = get_x_tp(map_o, lines, columns);
    int y_tp = get_y_tp(map_o, lines, columns);
    int x_tp_two = get_x_tp_two(map_o, lines, columns);
    int y_tp_two = get_y_tp_two(map_o, lines, columns);

    if (map_o[y][x] == 'T') {
        if (y == y_tp && x == x_tp && map[y_tp_two][x_tp_two] == ' ') {
            map[y_tp_two][x_tp_two] = 'p';
            map[y][x] = ' ';
        } else if (map[y_tp][x_tp] == ' ') {
            map[y_tp][x_tp] = 'p';
            map[y][x] = ' ';
        }
    }
}

void check_tp_box(char **map, char **map_o, int lines, int columns)
{
    int x_tp = get_x_tp_l(map_o, lines, columns);
    int y_tp = get_y_tp_l(map_o, lines, columns);
    int x_tp_two = get_x_tp_two_l(map_o, lines, columns);
    int y_tp_two = get_y_tp_two_l(map_o, lines, columns);

    for (int y = 0; y < lines; y++) {
        for (int x = 0; x < columns; x++) {
            if (map_o[y][x] == 't' && map[y][x] == 'X') {
                if (y == y_tp && x == x_tp && map[y_tp_two][x_tp_two] == ' ') {
                    map[y_tp_two][x_tp_two] = 'X';
                    map[y][x] = ' ';
                } else if (map[y_tp][x_tp] == ' ') {
                    map[y_tp][x_tp] = 'X';
                    map[y][x] = ' ';
                }
            }
        }
    }
}
