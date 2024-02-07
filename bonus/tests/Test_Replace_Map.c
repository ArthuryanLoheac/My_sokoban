/*
** EPITECH PROJECT, 2023
** Test_Replace_Map
** File description:
** Test_Replace_Map
*/
#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"
#include <ncurses.h>

Test(sokoban, Replace_Map_2)
{
    char map2[12][20] = { "############",
                        "#          #",
                        "# P     ####",
                        "#          #",
                        "#######    #  #####",
                        "#    ##    ####   #",
                        "#    ##         X #",
                        "#          #####  #",
                        "#       XX #   ####",
                        "#       #  #",
                        "############",
                        "",};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_2", &lines, &columns);
    replace_map(map, lines, columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, Replace_Map_1)
{
    char map2[11][13] = { "############",
                        "#          #",
                        "# P     ####",
                        "#          #",
                        "#######    #",
                        "#    ##    #",
                        "#    ##    #",
                        "#          #",
                        "#       XX #",
                        "#       #  #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, Replace_Map_o_2)
{
    char map2[12][20] = { "            ",
                        "         O  ",
                        "            ",
                        "            ",
                        "                   ",
                        "  O                ",
                        "                   ",
                        "                   ",
                        "                   ",
                        "            ",
                        "   O        ",
                        "",};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_2", &lines, &columns);
    replace_map_o(map, lines, columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, Replace_Map_o_1)
{
    char map2[11][13] = {"            ",
                        "         O  ",
                        "            ",
                        "            ",
                        "            ",
                        "  O         ",
                        "            ",
                        "            ",
                        "            ",
                        "            ",
                        "            "};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map_o(map, lines, columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, loose)
{
    int lines = 0;
    int columns = 0;
    int vals[2];
    char **map = generate_map("tests/maps/map_loose", &lines, &columns);
    char **map_o = generate_map("tests/maps/map_loose", &lines, &columns);
    replace_map(map, lines, columns);
    replace_map_o(map_o, lines, columns);
    vals[0] = lines;
    vals[1] = columns;
    cr_assert(check_lose(map, map_o, vals, "tests/maps/map_loose") == 1);
}

Test(sokoban, not_loose)
{
    int lines = 0;
    int columns = 0;
    int vals[2];
    char **map = generate_map("tests/maps/map_not_loose", &lines, &columns);
    char **map_o = generate_map("tests/maps/map_not_loose", &lines, &columns);
    replace_map(map, lines, columns);
    replace_map_o(map_o, lines, columns);
    vals[0] = lines;
    vals[1] = columns;
    cr_assert(check_lose(map, map_o, vals, "tests/maps/map_not_loose") == 0);
}

Test(sokoban, up_key)
{
    char map2[11][13] = { "############",
                        "# P        #",
                        "#       ####",
                        "#          #",
                        "#######    #",
                        "#    ##    #",
                        "#    ##    #",
                        "#          #",
                        "#       XX #",
                        "#       #  #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    input_player(KEY_UP, map, &lines, &columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, down_key)
{
    char map2[11][13] = { "############",
                        "#          #",
                        "#       ####",
                        "# P        #",
                        "#######    #",
                        "#    ##    #",
                        "#    ##    #",
                        "#          #",
                        "#       XX #",
                        "#       #  #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, left_key)
{
    char map2[11][13] = { "############",
                        "#          #",
                        "#P      ####",
                        "#          #",
                        "#######    #",
                        "#    ##    #",
                        "#    ##    #",
                        "#          #",
                        "#       XX #",
                        "#       #  #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, right_key)
{
    char map2[11][13] = { "############",
                        "#          #",
                        "#  P    ####",
                        "#          #",
                        "#######    #",
                        "#    ##    #",
                        "#    ##    #",
                        "#          #",
                        "#       XX #",
                        "#       #  #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map2[i], map2[i]), 0);
    }
}

Test(sokoban, move2)
{
    char map2[11][13] = { "############",
                        "#          #",
                        "#       ####",
                        "#          #",
                        "#######    #",
                        "#    ##    #",
                        "#    ##    #",
                        "#          #",
                        "#        PX#",
                        "#       #X #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map[i], map2[i]), 0);
    }
}

Test(sokoban, move_box)
{
    char map2[11][13] = { "############",
                        "#          #",
                        "#       ####",
                        "#          #",
                        "#######    #",
                        "#    ##    #",
                        "#X   ##    #",
                        "#P         #",
                        "#          #",
                        "#       #X #",
                        "############"};
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/Map_1", &lines, &columns);
    replace_map(map, lines, columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_DOWN, map, &lines, &columns);
    input_player(KEY_LEFT, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    input_player(KEY_UP, map, &lines, &columns);
    for (int i = 0; i < 12; i++) {
        cr_assert_eq(my_strcmp(map[i], map2[i]), 0);
    }
}

Test(sokoban, win_condition_false)
{
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/test_win", &lines, &columns);
    char **map_o = generate_map("tests/maps/test_win", &lines, &columns);
    replace_map(map, lines, columns);
    replace_map_o(map_o, lines, columns);
    cr_assert(check_win(map, map_o, lines, columns) == 0);
}

Test(sokoban, win_condition_true)
{
    int lines = 0;
    int columns = 0;
    char **map = generate_map("tests/maps/test_win", &lines, &columns);
    char **map_o = generate_map("tests/maps/test_win", &lines, &columns);
    replace_map(map, lines, columns);
    replace_map_o(map_o, lines, columns);
    input_player(KEY_RIGHT, map, &lines, &columns);
    cr_assert(check_win(map, map_o, lines, columns) == 1);
}
