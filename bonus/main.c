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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"

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

static void send_map(int socket_client, char **map, int lines, int columns)
{
    for (int i = 0; i < lines; i ++) {
        send(socket_client, map[i], columns, 0);
    }
}

static int start_game(char *path, int socket_client)
{
    char **map;
    char **map_o;
    int lines = 0;
    int columns = 0;
    int *vals;
    int len = strlen(path);
    int *ptr_vals[2] = {&lines, &columns};

    map = generate_map(path, &lines, &columns);
    map_o = generate_map(path, &lines, &columns);
    vals = vals_initialise(map, map_o, lines, columns);

    send(socket_client, &lines, sizeof(int), 0);
    send(socket_client, &columns, sizeof(int), 0);
    send(socket_client, &len, sizeof(int), 0);
    send(socket_client, path, sizeof(char) * len, 0);

    send_map(socket_client, map, lines, columns);
    for (int i = 0; i < lines; i ++) {
        send(socket_client, map_o[i], columns, 0);
    }

    while (check_win(map, map_o, lines, columns) != 1 &&
        check_lose(map, map_o, vals, path) != 1) {

        print_map_message(lines, columns, map, map_o);
        send_map(socket_client, map, lines, columns);
        recv(socket_client, NULL, sizeof(int), 0);
        test_restart(&map, &map_o, ptr_vals, path);
        send_map(socket_client, map, lines, columns);
        recv(socket_client, NULL, sizeof(int), 0);
    }
    print_map_message(lines, columns, map, map_o);
    return return_exit(map, map_o, lines, columns);
}

int first_player(int argc, char **argv, int socket_client)
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
    return start_game(argv[1], socket_client);
}
