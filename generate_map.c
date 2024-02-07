/*
** EPITECH PROJECT, 2023
** generate_map
** File description:
** generate_map
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

static void check_max(int *len, int *len_max)
{
    if (*len > *len_max) {
        *len_max = *len;
    }
    *len = 0;
}

static int get_max_line(char *path)
{
    int len_max = 0;
    int file = open(path, O_RDONLY);
    char c;
    int len = 0;
    int read_value = -1;

    if (file == -1) {
        return -1;
    }
    while (read_value != 0) {
        read_value = read(file, &c, 1);
        if (c == '\n') {
            check_max(&len, &len_max);
        } else {
            len += read_value;
        }
    }
    return len_max;
}

static int get_nb_line(char *path)
{
    int nb_lines = 0;
    int file = open(path, O_RDONLY);
    char c;
    int read_value = -1;

    if (file == -1) {
        return -1;
    }
    read_value = read(file, &c, 1);
    while (read_value > 0) {
        if (c == '\n') {
            nb_lines++;
        }
        read_value = read(file, &c, 1);
    }
    return nb_lines + 1;
}

static char **malloc_map(int nb_lines, int len_max)
{
    char **map;

    map = malloc(sizeof(char *) * nb_lines + 1);
    if (map == NULL) {
        exit(84);
    }
    for (int i = 0; i < nb_lines + 1; i++) {
        map[i] = malloc(sizeof(char) * len_max + 1);
        if (map[i] == NULL) {
            exit(84);
        }
    }
    return map;
}

static void fill_map(char **map, char *path)
{
    int file = open(path, O_RDONLY);
    int i = 0;
    int j = 0;
    char c = '\0';

    if (file == - 1) {
        exit(84);
    }
    while (read(file, &c, 1) > 0) {
        if (c == '\n') {
            j += 1;
            i = 0;
        } else {
            map[j][i] = c;
            i++;
        }
    }
}

char **generate_map(char *path, int *lines, int *columns)
{
    char **map = NULL;

    *lines = get_nb_line(path);
    *columns = get_max_line(path);
    if (*columns == -1 || *lines == -1) {
        return NULL;
    }
    map = malloc_map(*lines, *columns);
    fill_map(map, path);
    return map;
}
