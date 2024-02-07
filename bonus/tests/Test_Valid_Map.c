/*
** EPITECH PROJECT, 2023
** tests
** File description:
** tests
*/
#include <criterion/criterion.h>
#include "sokoban.h"

Test(sokoban, check_valid_Invalid)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid"), 84);
}

Test(sokoban, check_valid_Invalid2)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid2"), 84);
}

Test(sokoban, check_valid_Invalid3)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid3"), 84);
}

Test(sokoban, check_valid_Invalid4)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid4"), 84);
}

Test(sokoban, check_valid_Invalid5)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid5"), 84);
}

Test(sokoban, check_valid_Invalid6)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid6"), 84);
}

Test(sokoban, check_valid_Invalid7)
{
    cr_assert_eq(is_valid_map("tests/maps/Invalid7"), 84);
}

Test(sokoban, check_valid_Map_1)
{
    cr_assert_eq(is_valid_map("tests/maps/Map_1"), 0);
}

Test(sokoban, check_valid_Map_2)
{
    cr_assert_eq(is_valid_map("tests/maps/Map_2"), 0);
}

Test(sokoban, Wrong_file)
{
    cr_assert_eq(is_valid_map("tests/maps/Map_"), 84);
}
