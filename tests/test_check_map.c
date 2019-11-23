/*
** EPITECH PROJECT, 2019
** test_check_map.c
** File description:
** Tests for function check_map.
*/

#include <criterion/criterion.h>
#include "../include/error_detection.h"

Test(check_map, normal_case)
{
    int file_descr = 0;
    char buffer[2] = {0};
    file_descr = open("tests/small_map_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 0);
    close(file_descr);
    buffer[0] = 0;
    file_descr = open("tests/single_character_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 0);
    close(file_descr);
    buffer[0] = 0;
    file_descr = open("tests/single_column_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 0);
    close(file_descr);
    buffer[0] = 0;
}

Test(check_map, not_a_rectangle)
{
    int file_descr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/error_not_a_rectangle.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 84);
    close(file_descr);
}

Test(check_map, wrong_character)
{
    int file_descr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/error_wrong_character.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 84);
    close(file_descr);
}

Test(check_map, no_map)
{
    int file_descr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/error_no_map.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 84);
    close(file_descr);
}

Test(check_map, no_backslash_n)
{
    int file_descr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/error_no_backslash_n_after_map.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(check_map(file_descr), 84);
    close(file_descr);
}