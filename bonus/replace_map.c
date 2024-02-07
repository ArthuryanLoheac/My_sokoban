/*
** EPITECH PROJECT, 2023
** replace_map
** File description:
** replace_map
*/
static void replace_chars(char **map, int i, int j)
{
    if (map[i][j] == 'O') {
        map[i][j] = ' ';
    }
    if (map[i][j] == 'T') {
        map[i][j] = ' ';
    }
    if (map[i][j] == 't') {
        map[i][j] = ' ';
    }
}

static void replace_chars_o(char **map, int i, int j)
{
    if (map[i][j] == '#' || map[i][j] == 'P' || map[i][j] == 'X') {
        map[i][j] = ' ';
    }
}

void replace_map(char **map, int lines, int columns)
{
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            replace_chars(map, i, j);
        }
    }
}

void replace_map_o(char **map, int lines, int columns)
{
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            replace_chars_o(map, i, j);
        }
    }
}
