/*
** EPITECH PROJECT, 2023
** print_help
** File description:
** print_help
*/
#include "my.h"

void print_help(void)
{
    mini_printf("USAGE\n");
    mini_printf("    ./my_sokoban map\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("    map file representing the warehouse");
    mini_printf("map, containing '#' for walls,\n");
    mini_printf("        'P' for the player, 'X' for ");
    mini_printf("boxes and 'O' for storage locations.\n");
}
