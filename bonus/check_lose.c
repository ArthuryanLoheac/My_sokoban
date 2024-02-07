/*
** EPITECH PROJECT, 2023
** check_lose
** File description:
** check_lose
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "sokoban.h"

static int check_line(char **map, char **map_o, int vals[2], int i)
{
    int bad = 0;

    for (int j = 0; j < vals[1]; j++) {
        if (map[i][j] == 'X' && map_o[i][j] != 'O' &&
        ((i == 0 && j == 0) ||
        (i == 0 && j == vals[1] - 1) ||
        (i == vals[0] - 1 && j == 0) ||
        (i == vals[0] - 1 && j == vals[1] - 1))) {
            bad += 1;
        }
    }
    return bad;
}

static int check_corner(char **map, char **map_o, int vals[2])
{
    int bad = 0;

    for (int i = 0; i < vals[0]; i ++) {
        bad += check_line(map, map_o, vals, i);
    }
    return bad;
}

static int up_left(char **map, int value[2])
{
    int good = 0;

    if (value[0] > 0) {
        if (map[value[0] - 1][value[1]] == '#' ||
        map[value[0] - 1][value[1]] == 'X') {
            good += 1;
        }
    }
    if (value[1] > 0) {
        if (map[value[0]][value[1] - 1] == '#' ||
        map[value[0]][value[1] - 1] == 'X') {
            good += 1;
        }
    }
    if (good == 2) {
        return 1;
    }
    return 0;
}

static int left_down(char **map, int value[2], int vals[2])
{
    int good = 0;

    if (value[1] > 0) {
        if (map[value[0]][value[1] - 1] == '#' ||
        map[value[0]][value[1] - 1] == 'X') {
            good += 1;
        }
    }
    if (value[0] < vals[0] - 1) {
        if (map[value[0] + 1][value[1]] == '#' ||
        map[value[0] + 1][value[1]] == 'X') {
            good += 1;
        }
    }
    if (good == 2) {
        return 1;
    }
    return 0;
}

static int down_right(char **map, int value[2], int vals[2])
{
    int good = 0;

    if (value[0] < vals[0] - 1) {
        if (map[value[0] + 1][value[1]] == '#' ||
        map[value[0] + 1][value[1]] == 'X') {
            good += 1;
        }
    }
    if (value[1] < vals[1] - 1) {
        if (map[value[0]][value[1] + 1] == '#' ||
        map[value[0]][value[1] + 1] == 'X') {
            good += 1;
        }
    }
    if (good == 2) {
        return 1;
    }
    return 0;
}

static int right_up(char **map, int value[2], int vals[2])
{
    int good = 0;

    if (value[0] > 0) {
        if (map[value[0] - 1][value[1]] == '#' ||
            map[value[0] - 1][value[1]] == 'X') {
            good += 1;
        }
    }
    if (value[1] < vals[1] - 1) {
        if (map[value[0]][value[1] + 1] == '#' ||
        map[value[0]][value[1] + 1] == 'X') {
            good += 1;
        }
    }
    if (good == 2) {
        return 1;
    }
    return 0;
}

static int check_every_direction(char **map, char **map_o,
    int vals[2], int value[2])
{
    int good = 0;

    if (map[value[0]][value[1]] == 'X' && map_o[value[0]][value[1]] != 'O') {
        good += up_left(map, value);
        good += left_down(map, value, vals);
        good += down_right(map, value, vals);
        good += right_up(map, value, vals);
        good += up_map(map, value, vals);
        good += down_map(map, value, vals);
        good += left_map(map, value, vals);
        good += right_map(map, value, vals);
    }
    if (good != 0) {
        return 1;
    }
    return 0;
}

static int check_all(char **map, char **map_o, int vals[2], int nb_boxes)
{
    int bad = 0;
    int value[2];

    bad += check_corner(map, map_o, vals);
    for (int i = 0; i < vals[0]; i++) {
        for (int j = 0; j < vals[1]; j++) {
            value[0] = i;
            value[1] = j;
            bad += check_every_direction(map, map_o, vals, value);
        }
    }
    if (bad >= nb_boxes) {
        return 1;
    }
    return 0;
}

int nb_box(char *path)
{
    int file = open(path, O_RDONLY);
    int nb_box = 0;
    char c;

    if (file == -1) {
        exit(84);
    }
    while (read(file, &c, 1) > 0) {
        if (c == 'X') {
            nb_box++;
        }
    }
    return nb_box;
}

int check_lose(char **map, char **map_o, int vals[2], char *path)
{
    int nb_boxes = nb_box(path);

    return check_all(map, map_o, vals, nb_boxes);
}
