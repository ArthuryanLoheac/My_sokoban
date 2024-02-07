/*
** EPITECH PROJECT, 2023
** input_player
** File description:
** input_player
*/
#include <ncurses.h>
#include "sokoban.h"

static void move_up(int x, int y, char **map)
{
    if (map[y - 1][x] != '#' && map[y - 1][x] != 'X') {
        map[y][x] = ' ';
        map[y - 1][x] = 'P';
    }
    if (map[y - 1][x] == 'X' && y > 1 &&
        map[y - 2][x] != '#' && map[y - 2][x] != 'X') {
        map[y][x] = ' ';
        map[y - 1][x] = 'P';
        map[y - 2][x] = 'X';
    }
}

static void move_down(int x, int y, char **map, int lines)
{
    if (map[y + 1][x] != '#' && map[y + 1][x] != 'X') {
        map[y][x] = ' ';
        map[y + 1][x] = 'P';
    }
    if (map[y + 1][x] == 'X' && y < lines - 2 &&
        map[y + 2][x] != '#' && map[y + 2][x] != 'X') {
        map[y][x] = ' ';
        map[y + 1][x] = 'P';
        map[y + 2][x] = 'X';
    }
}

static void move_left(int x, int y, char **map)
{
    if (map[y][x - 1] != '#' && map[y][x - 1] != 'X') {
        map[y][x] = ' ';
        map[y][x - 1] = 'P';
    }
    if (map[y][x - 1] == 'X' && x > 1 &&
        map[y][x - 2] != '#' && map[y][x - 2] != 'X') {
        map[y][x] = ' ';
        map[y][x - 1] = 'P';
        map[y][x - 2] = 'X';
    }
}

static void move_right(int x, int y, char **map, int columns)
{
    if (map[y][x + 1] != '#' && map[y][x + 1] != 'X') {
        map[y][x] = ' ';
        map[y][x + 1] = 'P';
    }
    if (map[y][x + 1] == 'X' && x < columns - 2 &&
        map[y][x + 2] != '#' && map[y][x + 2] != 'X') {
        map[y][x] = ' ';
        map[y][x + 1] = 'P';
        map[y][x + 2] = 'X';
    }
}

static void check_up(int key, char **map, int lines, int columns)
{
    int x = player_x(map, lines, columns);
    int y = player_y(map, lines, columns);

    if (key == KEY_UP) {
        if (y > 0) {
            move_up(x, y, map);
        }
    }
}

static void check_down(int key, char **map, int lines, int columns)
{
    int x = player_x(map, lines, columns);
    int y = player_y(map, lines, columns);

    if (key == KEY_DOWN) {
        if (y < lines - 1) {
            move_down(x, y, map, lines);
        }
    }
}

static void check_left(int key, char **map, int lines, int columns)
{
    int x = player_x(map, lines, columns);
    int y = player_y(map, lines, columns);

    if (key == KEY_LEFT) {
        if (x > 0) {
            move_left(x, y, map);
        }
    }
}

static void check_right(int key, char **map, int lines, int columns)
{
    int x = player_x(map, lines, columns);
    int y = player_y(map, lines, columns);

    if (key == KEY_RIGHT) {
        if (x < columns - 1) {
            move_right(x, y, map, columns);
        }
    }
}

void input_player(int key, char **map, int *lines, int *columns)
{
    check_up(key, map, *lines, *columns);
    check_down(key, map, *lines, *columns);
    check_left(key, map, *lines, *columns);
    check_right(key, map, *lines, *columns);
    clear();
}
