/*
** EPITECH PROJECT, 2019
** test_copy_file_in_map.c
** File description:
** Tests for function copy_file_in_map.
*/

#include <criterion/criterion.h>
#include "../include/map_initializing.h"

Test(copy_file_in_map, single_character_in_map)
{
    char expected[1][1];
    int file_descr = 0;
    char buffer[2] = {0};
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    file_descr = open("tests/single_character_file.txt", O_RDONLY);
    map->rows = 1;
    map->cols = 1;
    expected[0][0] = '.';
    map->array = malloc(sizeof(char *));
    (map->array)[0] = malloc(sizeof(char));
    cr_expect_eq(copy_file_in_map(file_descr, map), 0);
    cr_expect_arr_eq((map->array)[0], expected[0], 1);
    close(file_descr);
    free_map(map);
}

Test(copy_file_in_map, single_line_in_map)
{
    char expected[1][5];
    int file_descr = 0;
    char buffer[2] = {0};
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    file_descr = open("tests/single_line_file.txt", O_RDONLY);
    for (int i = 0; i < 5; i++)
        expected[0][i] = '.';
    map->rows = 1;
    map->cols = 5;
    map->array = malloc(sizeof(char *));
    (map->array)[0] = malloc(sizeof(char) * 5);
    cr_expect_eq(copy_file_in_map(file_descr, map), 0);
    cr_expect_arr_eq((map->array)[0], expected[0], 5);
    close(file_descr);
    free_map(map);
}

Test(copy_file_in_map, single_column_in_map)
{
    char expected[5][1];
    int file_descr = 0;
    char buffer[2] = {0};
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    file_descr = open("tests/single_column_file.txt", O_RDONLY);
    map->rows = 5;
    map->cols = 1;
    map->array = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++) {
        (map->array)[i] = malloc(sizeof(char));
        expected[i][0] = '.';
    }
    cr_expect_eq(copy_file_in_map(file_descr, map), 0);
    for (int i = 0; i < 5; i++)
        cr_expect_arr_eq((map->array)[i], expected[i], 1);
    close(file_descr);
    free_map(map);
}

/*Test(copy_file_in_map, small_map)
{
    char expected[3][3];
    int file_descr = 0;
    char buffer[2] = {0};
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    file_descr = open("tests/small_map_file.txt", O_RDONLY);
    map->rows = 3;
    map->cols = 3;
    map->array = malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++) {
        (map->array)[i] = malloc(sizeof(char) * 3);
    }
    for (int i = 0; i < 3; i++) {
        (expected[0])[i] = '.';
    }
    for (int i = 0; i < 3; i++) {
        (expected[1])[i] = '.';
    }
    for (int i = 0; i < 3; i++) {
        (expected[2])[i] = '.';
    }
    cr_expect_eq(copy_file_in_map(file_descr, map), 0);
    for (int i = 0; i < 3; i++)
        cr_expect_arr_eq((map->array)[i], expected[i], 3);
    close(file_descr);
    free_map(map);
}*/