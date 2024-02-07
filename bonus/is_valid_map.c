/*
** EPITECH PROJECT, 2023
** is_valid_map
** File description:
** is_valid_map
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static int different_case(int *nb_player, int *nb_box,
    int *nb_placement, char c, int *nb_tp, int *nb_tp_box)
{
    switch (c) {
        case 'P':
            (*nb_player)++;
            break;
        case 'X':
            (*nb_box)++;
            break;
        case 'O':
            (*nb_placement)++;
            break;
        case '#':
            break;
        case ' ':
            break;
        case '\n':
            break;
        case 'T':
            (*nb_tp)++;
            break;
        case 't':
            (*nb_tp_box)++;
            break;
        case 'p':
            break;
        default:
            return 84;
    }
    return 0;
}

int is_valid_map(char *path)
{
    int file = open(path, O_RDONLY);
    int nb_player = 0;
    int nb_box = 0;
    int nb_placement = 0;
    int nb_tp = 0;
    int nb_tp_box = 0;
    char c = 0;

    if (file == -1) {
        return 84;
    }
    while (read(file, &c, 1) > 0) {
        if (different_case(&nb_player, &nb_box, &nb_placement, c, &nb_tp, &nb_tp_box) == 84) {
            return 84;
        }
    }
    if (nb_player != 1 || nb_placement != nb_box || nb_box == 0 || (nb_tp != 0 && nb_tp != 2) || (nb_tp_box != 0 && nb_tp_box != 2)) {
        close(file);
        return 84;
    }
    return close(file);
}
