/*
** EPITECH PROJECT, 2019
** test_load_map_from_file.c
** File description:
** Tests for function load_map_from_file.
*/

#include <criterion/criterion.h>
#include "../include/load_map_from_file.h"
#include "../include/map.h"

Test(test_load_map_from_file, single_character_in_file)
{
    map_t *map;
    char str[1][1];

    map = malloc(sizeof(map_t));
    str[0][0] = '.';
    cr_expect_eq(load_map_from_file("tests/single_character_file.txt", map), 0);
    cr_expect_arr_eq((map->array)[0], str[0], 1, "actual : %s",(map->array)[0]);
    free_map(map);
}

Test(test_load_map_from_file, single_column_in_file)
{
    map_t *map;
    char str[5][1];

    map = malloc(sizeof(map_t));
    for (int i = 0; i < 5; i++)
        str[i][0] = '.';
    cr_expect_eq(load_map_from_file("tests/single_column_file.txt", map), 0);
    for (int i = 0; i < 5; i++)
        cr_expect_arr_eq((map->array)[i], str[i], 1);
    free_map(map);
}

Test(test_load_map_from_file, single_line_in_file)
{
    map_t *map;
    char str[1][5];

    map = malloc(sizeof(map_t));
    for (int i = 0; i < 5; i++)
        str[0][i] = '.';
    cr_expect_eq(load_map_from_file("tests/single_line_file.txt", map), 0);
    cr_expect_arr_eq((map->array)[0], str[0], 5);
    free_map(map);
}

Test(test_load_map_from_file, small_map)
{
    map_t *map;
    char str[3][3];

    map = malloc(sizeof(map_t));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            str[i][j] = '.';
    }
    cr_expect_eq(load_map_from_file("tests/small_map_file.txt", map), 0);
    for (int i = 0; i < 3; i++)
        cr_expect_arr_eq((map->array)[i], str[i], 3);
    free_map(map);
}

Test(test_load_map_from_file, big_map)
{
    map_t *map;
    char str[15][20];

    map = malloc(sizeof(map_t));
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++)
            str[i][j] = '.';
    }
    cr_expect_eq(load_map_from_file("tests/big_map_file.txt", map), 0);
    for (int i = 0; i < 15; i++)
        cr_expect_arr_eq((map->array)[i], str[i], 20);
    free_map(map);
}