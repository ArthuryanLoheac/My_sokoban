/*
** EPITECH PROJECT, 2023
** print help test
** File description:
** print help test
*/
#include <criterion/criterion.h>
#include "sokoban.h"
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, ZNP, .init = redirect_all_std)
{
    print_help();
    cr_assert_stdout_eq_str("USAGE\n    ./my_sokoban map\nDESCRIPTION\n    map file representing the warehousemap, containing '#' for walls,\n        'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
}

