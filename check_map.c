/*
** EPITECH PROJECT, 2023
** check_map.c
** File description:
** check_map.c
*/

int up_map(char **map, int value[2], int vals[2])
{
    if (value[0] == 0 && value[1] > 0) {
        if (map[0][value[1] - 1] == '#' ||
        map[0][value[1] - 1] == 'X') {
            return 1;
        }
    }
    if (value[0] == 0 && value[1] < vals[0]) {
        if (map[0][value[1] + 1] == '#' ||
        map[0][value[1] + 1] == 'X') {
            return 1;
        }
    }
    return 0;
}

int left_map(char **map, int value[2], int vals[2])
{
    if (value[0] > vals[1] && value[1] == 0) {
        if (map[value[0] - 1][0] == '#' ||
        map[value[0] - 1][0] == 'X') {
            return 1;
        }
    }
    if (value[0] < vals[1] && value[1] == 0) {
        if (map[value[0] + 1][0] == '#' ||
        map[value[0] + 1][0] == 'X') {
            return 1;
        }
    }
    return 0;
}

int right_map(char **map, int value[2], int vals[2])
{
    if (value[0] > vals[1] && value[1] == vals[1] - 1) {
        if (map[value[0] - 1][vals[1] - 1] == '#' ||
        map[value[0] - 1][vals[1] - 1] == '#' ) {
            return 1;
        }
    }
    if (value[0] < vals[1] && value[1] == vals[1] - 1) {
        if (map[value[0] + 1][vals[1] - 1] == '#' ||
        map[value[0] + 1][vals[1] - 1] == 'X') {
            return 1;
        }
    }
    return 0;
}

int down_map(char **map, int value[2], int vals[2])
{
    if (value[0] == vals[0] - 1 && value[1] > 0) {
        if (map[vals[0] - 1][value[1] - 1] == '#' ||
        map[vals[0] - 1][value[1] - 1] == 'X') {
            return 1;
        }
    }
    if (value[0] == vals[0] - 1 && value[1] < vals[0]) {
        if (map[vals[0] - 1][value[1] + 1] == '#' ||
        map[vals[0] - 1][value[1] + 1] == 'X') {
            return 1;
        }
    }
    return 0;
}
