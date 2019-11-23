/*
** EPITECH PROJECT, 2019
** test_display_character.c
** File description:
** Tests for function display_character.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/display_result.h"

Test(display_character, without_obstacles, .init = cr_redirect_stdout)
{
    map_t map;
    square biggest_square = {0, 0, 1};

    map.rows = 1;
    map.cols = 1;
    (map.array) = malloc(sizeof(char *));
    (map.array)[0] = malloc(sizeof(char));
    (map.array)[0][0] = '.';
    display_character(&map, 0, 0, &biggest_square);
    biggest_square.x = 2;
    biggest_square.y = 3;
    display_character(&map, 0, 0, &biggest_square);
    free((map.array)[0]);
    free(map.array);
    cr_expect_stdout_eq_str("X.");
}

Test(display_character, with_obstacles, .init = cr_redirect_stdout)
{
    map_t map;
    square biggest_square = {0, 0, 1};

    map.rows = 1;
    map.cols = 1;
    (map.array) = malloc(sizeof(char *));
    (map.array)[0] = malloc(sizeof(char));
    (map.array)[0][0] = 'o';
    biggest_square.x = 2;
    biggest_square.y = 3;
    display_character(&map, 0, 0, &biggest_square);
    free((map.array)[0]);
    free(map.array);
    cr_expect_stdout_eq_str("o");
}