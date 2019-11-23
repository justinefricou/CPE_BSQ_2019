/*
** EPITECH PROJECT, 2019
** test_is_line.c
** File description:
** Tests for function is_line.
*/

#include <criterion/criterion.h>
#include "../include/find_biggest_square.h"

Test(is_line, size_too_big)
{
    char line1[7];
    char line2[1];

    for (int i = 0; i < 7; i++)
        line1[i] = '.';
    line2[0] = '.';
    cr_expect_eq(is_line(8, line1, 7), 0);
    cr_expect_eq(is_line(10, line1, 7), 0);
    cr_expect_eq(is_line(7, &(line1[1]), 6), 0);
    cr_expect_eq(is_line(2, line2, 1), 0);
    cr_expect_eq(is_line(5, line2, 1), 0);
}

Test(is_line, o_in_line)
{
    char line[10];

    for (int i = 0; i < 10; i++)
        line[i] = '.';
    line[3] = 'o';
    cr_expect_eq(is_line(10, line, 10), 0);
    cr_expect_eq(is_line(3, line, 10), 1);
    cr_expect_eq(is_line(4, line, 10), 0);
    cr_expect_eq(is_line(6, &(line[4]), 6), 1);
    cr_expect_eq(is_line(3, &(line[4]), 6), 1);
    cr_expect_eq(is_line(1, &(line[9]), 1), 1);
    cr_expect_eq(is_line(8, &(line[1]), 9), 0);
}

Test(is_line, o_at_end_of_line)
{
    char line[5];

    for (int i = 0; i < 5; i++)
        line[i] = '.';
    line[4] = 'o';

    cr_expect_eq(is_line(5, line, 5), 0);
    cr_expect_eq(is_line(4, line, 5), 1);
    cr_expect_eq(is_line(1, line, 5), 1);
    cr_expect_eq(is_line(4, &(line[1]), 4), 0);
    cr_expect_eq(is_line(3, &(line[1]), 4), 1);
    cr_expect_eq(is_line(1, &(line[3]), 2), 1);
    cr_expect_eq(is_line(1, &(line[4]), 1), 0);
}