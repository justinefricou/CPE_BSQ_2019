/*
** EPITECH PROJECT, 2019
** test_set_map_dimensions.c
** File description:
** Tests for function set_map_dimensions.
*/

#include <criterion/criterion.h>
#include "../include/load_map_from_file.h"

Test(set_map_dimensions, empty_map)
{
    map_t map;
    int actual_return = 0;

    actual_return = set_map_dimensions("tests/zero_line_file.txt", &map);
    cr_expect_eq(actual_return, 84);
    cr_expect_eq(map.rows, 0);
    cr_expect_eq(map.cols, 0);
}

Test(set_map_dimensions, single_character_in_map)
{
    map_t map;
    int actual_return = 0;

    actual_return = set_map_dimensions("tests/single_character_file.txt", &map);
    cr_expect_eq(actual_return, 0);
    cr_expect_eq(map.rows, 1);
    cr_expect_eq(map.cols, 1);
}

Test(set_map_dimensions, single_column_in_map)
{
    map_t map;
    int actual_return = 0;

    actual_return = set_map_dimensions("tests/single_column_file.txt", &map);
    cr_expect_eq(actual_return, 0);
    cr_expect_eq(map.rows, 5);
    cr_expect_eq(map.cols, 1);
}

Test(set_map_dimensions, single_line_in_map)
{
    map_t map;
    int actual_return = 0;

    actual_return = set_map_dimensions("tests/single_line_file.txt", &map);
    cr_expect_eq(actual_return, 0);
    cr_expect_eq(map.rows, 1);
    cr_expect_eq(map.cols, 5);
}

Test(set_map_dimensions, normal_maps)
{
    map_t small_map;
    map_t big_map;
    int actual_return1 = 0;
    int actual_return2 = 0;

    actual_return1 = set_map_dimensions("tests/small_map_file.txt", &small_map);
    actual_return2 = set_map_dimensions("tests/big_map_file.txt", &big_map);
    cr_expect_eq(actual_return1, 0);
    cr_expect_eq(actual_return2, 0);
    cr_expect_eq(small_map.rows, 3);
    cr_expect_eq(small_map.cols, 3);
    cr_expect_eq(big_map.rows, 15);
    cr_expect_eq(big_map.cols, 20);
}