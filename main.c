/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/
#include "sokoban.h"
#include "my.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

static void print_map_message(int lines, int columns,
    char **map, char **map_o)
{
    if (LINES < lines || COLS < columns) {
        mvprintw((LINES / 2), (COLS / 2) -
            (my_strlen("Please enlarge the console")
            / 2), "Please enlarge the console");
    } else {
        print_map(map, map_o, lines, columns);
    }
}

static void initialise(char **map, char **map_o, int lines, int columns)
{
    replace_map(map, lines, columns);
    replace_map_o(map_o, lines, columns);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

static int return_exit(char **map, char **map_o, int lines, int columns)
{
    clear();
    echo();
    keypad(stdscr, FALSE);
    endwin();
    if (check_win(map, map_o, lines, columns) == 1) {
        return 0;
    } else {
        return 1;
    }
}

static void test_restart(char ***map, char ***map_o, int *lines[2], char *path)
{
    int key = getch();

    if (key == ' ') {
        *map = generate_map(path, lines[0], lines[1]);
        *map_o = generate_map(path, lines[0], lines[1]);
        initialise(*map, *map_o, *lines[0], *lines[1]);
    }
    input_player(key, *map, lines[0], lines[1]);
}

static int *vals_initialise(char **map, char **map_o, int lines, int columns)
{
    int *vals = NULL;

    vals = malloc(sizeof(int) * 2);
    if (vals == NULL) {
        exit(84);
    }
    initialise(map, map_o, lines, columns);
    vals[0] = lines;
    vals[1] = columns;
    return vals;
}

static int start_game(char *path)
{
    char **map;
    char **map_o;
    int lines = 0;
    int columns = 0;
    int *vals;
    int *ptr_vals[2] = {&lines, &columns};

    map = generate_map(path, &lines, &columns);
    map_o = generate_map(path, &lines, &columns);
    vals = vals_initialise(map, map_o, lines, columns);
    while (check_win(map, map_o, lines, columns) != 1 &&
        check_lose(map, map_o, vals, path) != 1) {
        print_map_message(lines, columns, map, map_o);
        test_restart(&map, &map_o, ptr_vals, path);
    }
    print_map_message(lines, columns, map, map_o);
    usleep(10000);
    return return_exit(map, map_o, lines, columns);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }
    if (is_valid_map(argv[1]) != 0) {
        return 84;
    }
    return start_game(argv[1]);
}
