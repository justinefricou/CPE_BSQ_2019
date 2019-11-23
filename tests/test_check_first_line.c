/*
** EPITECH PROJECT, 2019
** test_check_first_line.c
** File description:
** Tests for function check_first_line.
*/

#include <criterion/criterion.h>
#include "../include/error_detection.h"

Test(check_first_line, normal_case)
{
    int file_descr = 0;

    file_descr = open("tests/small_map_file.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 0);
    close(file_descr);
    file_descr = open("tests/big_map_file.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 0);
    close(file_descr);
    file_descr = open("tests/single_line_file.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 0);
    close(file_descr);
    file_descr = open("tests/single_column_file.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 0);
    close(file_descr);
    file_descr = open("tests/single_character_file.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 0);
    close(file_descr);
}

Test(check_first_line, no_backslash_n)
{
    int file_descr = 0;

    file_descr = open("tests/error_no_backslash_n_before_map.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 84);
    close(file_descr);
}

Test(check_first_line, not_a_number)
{
    int file_descr = 0;

    file_descr = open("tests/error_wrong_first_line.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 84);
    close(file_descr);
}

Test(check_first_line, negative_number)
{
    int file_descr = 0;

    file_descr = open("tests/error_negative_number.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 84);
    close(file_descr);
}

Test(check_first_line, empty_file_or_empty_first_line)
{
    int file_descr = 0;

    file_descr = open("tests/error_empty_file.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 84);
    close(file_descr);
    file_descr = open("tests/error_only_backslash_n.txt", O_RDONLY);
    cr_expect_eq(check_first_line(file_descr), 84);
    close(file_descr);
}