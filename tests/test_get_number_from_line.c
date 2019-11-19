/*
** EPITECH PROJECT, 2019
** test_get_number_from_line.c
** File description:
** Tests for function get_number_from_line.
*/

#include <criterion/criterion.h>
#include "../include/map_initializing.h"

Test(get_number_from_line, zero_case)
{
    int file_descr = 0;
    int nbr = 0;

    file_descr = open("tests/zero_line_file.txt", O_RDONLY);
    cr_expect_eq(get_number_from_line(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 0, "actual = %i", nbr);
    close(file_descr);
}

Test(get_number_from_line, one_case)
{
    int file_descr = 0;
    int nbr = 0;

    file_descr = open("tests/single_line_file.txt", O_RDONLY);
    cr_expect_eq(get_number_from_line(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 1, "actual = %i", nbr);
    close(file_descr);
}

Test(get_number_from_line, small_map_case)
{
    int file_descr = 0;
    int nbr = 0;

    file_descr = open("tests/small_map_file.txt", O_RDONLY);
    cr_expect_eq(get_number_from_line(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 3, "actual = %i", nbr);
    close(file_descr);
}

Test(get_number_from_line, big_map_case)
{
    int file_descr = 0;
    int nbr = 0;

    file_descr = open("tests/big_map_file.txt", O_RDONLY);
    cr_expect_eq(get_number_from_line(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 15, "actual = %i", nbr);
    close(file_descr);
}