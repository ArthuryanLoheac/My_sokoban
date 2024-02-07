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
