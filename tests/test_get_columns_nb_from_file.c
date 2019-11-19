/*
** EPITECH PROJECT, 2019
** test_get_columns_nb_from_file.c
** File description:
** Tests for function get_columns_nb_from_file.
*/

#include <criterion/criterion.h>
#include "../include/map_initializing.h"

Test(get_columns_nb_from_file, zero_case)
{
    int file_descr = 0;
    int nbr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/zero_line_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(get_columns_nb_from_file(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 0, "actual = %i", nbr);
    close(file_descr);
}

Test(get_columns_nb_from_file, one_character_case)
{
    int file_descr = 0;
    int nbr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/single_character_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(get_columns_nb_from_file(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 1, "actual = %i", nbr);
    close(file_descr);
}

Test(get_columns_nb_from_file, one_line_case)
{
    int file_descr = 0;
    int nbr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/single_line_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(get_columns_nb_from_file(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 5, "actual = %i", nbr);
    close(file_descr);
}

Test(get_columns_nb_from_file, one_column_case)
{
    int file_descr = 0;
    int nbr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/single_column_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(get_columns_nb_from_file(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 1, "actual = %i", nbr);
    close(file_descr);
}

Test(get_columns_nb_from_file, big_map_case)
{
    int file_descr = 0;
    int nbr = 0;
    char buffer[2] = {0};

    file_descr = open("tests/small_map_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; )
        read(file_descr, buffer, 1);
    cr_expect_eq(get_columns_nb_from_file(file_descr, &nbr), 0);
    cr_expect_eq(nbr, 3, "actual = %i", nbr);
    close(file_descr);
}