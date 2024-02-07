/*
** EPITECH PROJECT, 2023
** Test_generate
** File description:
** test_generate
*/
#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"

Test(sokoban, generate_Map_1)
{
    char map[11][13] = { "############",
                    "#        O #",
                    "# P     ####",
                    "#          #",
                    "#######    #",
                    "# O  ##    #",
                    "#    ##    #",
                    "#          #",
                    "#       XX #",
                    "#       #  #",
                    "############"};
    int lines = 0;
    int columns = 0;
    char **map2 = generate_map("tests/maps/Map_1", &lines, &columns);
    for (int i = 0; i < 11; i++) {
        cr_assert_eq(my_strcmp(map[i], map2[i]), 0);
    }
}

Test(sokoban, generate_Map_2)
{
    char map[12][20] = { "############",
                    "#        O #",
                    "# P     ####",
                    "#          #",
                    "#######    #  #####",
                    "# O  ##    ####   #",
                    "#    ##         X #",
                    "#          #####  #",
                    "#       XX #   ####",
                    "#  O    #  #",
                    "############",
                    "",};
    int lines = 0;
    int columns = 0;
    char **map2 = generate_map("tests/maps/Map_2", &lines, &columns);

    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map[i], map2[i]), 0);
    }
}

Test(sokoban, Invalid)
{
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Inval", &lines, &columns);
    cr_assert_null(map);
}

Test(sokoban, player_x_pos)
{
    int lines = 11;
    int columns = 13;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    cr_assert(player_x(map, lines, columns) == 2);
}

Test(sokoban, player_y_pos)
{
    int lines = 11;
    int columns = 13;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    cr_assert(player_y(map, lines, columns) == 2);
}
