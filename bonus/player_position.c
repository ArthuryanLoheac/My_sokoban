/*
** EPITECH PROJECT, 2023
** player_position
** File description:
** player_position
*/

static int y_is_player(int i, int j, char **map, int pos)
{
    if (map[i][j] == 'P') {
        return i;
    }
    return pos;
}

static int x_is_player(int i, int j, char **map, int pos)
{
    if (map[i][j] == 'P') {
        return j;
    }
    return pos;
}

static int y_is_player_two(int i, int j, char **map, int pos)
{
    if (map[i][j] == 'p') {
        return i;
    }
    return pos;
}

static int x_is_player_two(int i, int j, char **map, int pos)
{
    if (map[i][j] == 'p') {
        return j;
    }
    return pos;
}

static int x_is_tp(int i, int j, char **map, int pos)
{
    if (map[i][j] == 'T') {
        return j;
    }
    return pos;
}

static int y_is_tp(int i, int j, char **map, int pos)
{
    if (map[i][j] == 'T') {
        return i;
    }
    return pos;
}

static int x_is_tp_l(int i, int j, char **map, int pos)
{
    if (map[i][j] == 't') {
        return j;
    }
    return pos;
}

static int y_is_tp_l(int i, int j, char **map, int pos)
{
    if (map[i][j] == 't') {
        return i;
    }
    return pos;
}

int player_y(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = y_is_player(i, j, map, pos);
        }
    }
    return pos;
}

int player_x(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = x_is_player(i, j, map, pos);
        }
    }
    return pos;
}

int player_y_two(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = y_is_player_two(i, j, map, pos);
        }
    }
    return pos;
}

int player_x_two(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = x_is_player_two(i, j, map, pos);
        }
    }
    return pos;
}

int get_x_tp(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = x_is_tp(i, j, map, pos);
        }
    }
    return pos;
}

int get_y_tp(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = y_is_tp(i, j, map, pos);
        }
    }
    return pos;
}

int get_x_tp_two(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (x_is_tp(i, j, map, pos) != pos) {
                return x_is_tp(i, j, map, pos);
            }
        }
    }
    return pos;
}

int get_y_tp_two(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (y_is_tp(i, j, map, pos) != pos) {
                return y_is_tp(i, j, map, pos);
            }
        }
    }
    return pos;
}

int get_x_tp_l(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = x_is_tp_l(i, j, map, pos);
        }
    }
    return pos;
}

int get_y_tp_l(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            pos = y_is_tp_l(i, j, map, pos);
        }
    }
    return pos;
}

int get_x_tp_two_l(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (x_is_tp_l(i, j, map, pos) != pos) {
                return x_is_tp_l(i, j, map, pos);
            }
        }
    }
    return pos;
}

int get_y_tp_two_l(char **map, int lines, int columns)
{
    int pos = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (y_is_tp_l(i, j, map, pos) != pos) {
                return y_is_tp_l(i, j, map, pos);
            }
        }
    }
    return pos;
}
