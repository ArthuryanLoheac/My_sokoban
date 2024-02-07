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
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"


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

static char **recv_map(char **map, int *lines, int *columns, int socket_client)
{
    map = malloc(sizeof(char *) * (*lines + 1));
    for (int i = 0; i < *lines; i++) {
        map[i] = malloc(*columns);
    }
    for (int i = 0; i < *lines; i ++) {
        recv(socket_client, map[i], *columns, 0);
    }
    return map;
}

static char **set_map_o(char **map_o, int *lines, int *columns, int socket_client)
{
    map_o = malloc(sizeof(char *) * (*lines + 1));
    for (int i = 0; i < *lines; i++) {
        map_o[i] = malloc(*columns);
    }
    for (int i = 0; i < *lines; i ++) {
        recv(socket_client, map_o[i], *columns, 0);
    }
    return map_o;
}

int player_two(int socket_client)
{
    char **map = NULL;
    char **map_o = NULL;
    int lines = 0;
    int columns = 0;
    int len = 0;
    int *vals;
    int received = 1;
    char *path;

    recv(socket_client, &lines, sizeof(int), 0);
    recv(socket_client, &columns, sizeof(int), 0);
    recv(socket_client, &len, sizeof(int), 0);
    path = malloc(len);
    recv(socket_client, path, sizeof(char) * len, 0);

    map = recv_map(map, &lines, &columns, socket_client);
    map_o = set_map_o(map_o, &lines, &columns, socket_client);
    vals = vals_initialise(map, map_o, lines, columns);

    while(check_win(map, map_o, lines, columns) != 1 &&
        check_lose(map, map_o, vals, path) != 1) {
        print_map_message(lines, columns, map, map_o);
        map = recv_map(map, &lines, &columns, socket_client);
        send(socket_client, &received, sizeof(int), 0);
        print_map_message(lines, columns, map, map_o);
        map = recv_map(map, &lines, &columns, socket_client);
        send(socket_client, &received, sizeof(int), 0);
    }
    return return_exit(map, map_o, lines, columns);
}
