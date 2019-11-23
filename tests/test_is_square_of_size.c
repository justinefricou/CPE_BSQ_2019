/*
** EPITECH PROJECT, 2019
** test_is_square_of_size.c
** File description:
** Tests for function is_square_of_size.
*/

#include <criterion/criterion.h>
#include "../include/find_biggest_square.h"

Test(is_square_of_size, normal_case)
{
    map_t map;

    map.rows = 5;
    map.cols = 7;
    map.array = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++) {
        (map.array)[i] = malloc(sizeof(char) * 7);
        for (int j = 0; j < 7; j++)
            (map.array)[i][j] = '.';
    }
    (map.array)[3][2] = 'o';
    cr_expect_eq(is_square_of_size(&map, 0, 0, 1), 1);
    cr_expect_eq(is_square_of_size(&map, 0, 0, 3), 1);
    cr_expect_eq(is_square_of_size(&map, 0, 0, 4), 0);
    cr_expect_eq(is_square_of_size(&map, 3, 2, 1), 0);
    cr_expect_eq(is_square_of_size(&map, 3, 3, 2), 1);
    cr_expect_eq(is_square_of_size(&map, 3, 3, 3), 0);
    for (int i = 0; i < 5; i++)
        free((map.array)[i]);
    free(map.array);
}

Test(is_square_of_size, single_character_in_map)
{
    map_t map;

    map.rows = 1;
    map.cols = 1;
    map.array = malloc(sizeof(char *));
    (map.array)[0] = malloc(sizeof(char));
    (map.array)[0][0] = '.';
    cr_expect_eq(is_square_of_size(&map, 0, 0, 1), 1);
    cr_expect_eq(is_square_of_size(&map, 0, 0, 3), 0);
    (map.array)[0][0] = 'o';
    cr_expect_eq(is_square_of_size(&map, 0, 0, 1), 0);
    cr_expect_eq(is_square_of_size(&map, 0, 0, 3), 0);
    free((map.array)[0]);
    free(map.array);
}

Test(is_square_of_size, single_column_in_map)
{

}

Test(is_square_of_size, single_line_in_map)
{

}