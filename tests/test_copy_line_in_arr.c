/*
** EPITECH PROJECT, 2019
** test_copy_line_in_arr.c
** File description:
** Tests for function copy_line_in_arr.
*/

#include <criterion/criterion.h>
#include "../include/map_initializing.h"

Test(copy_line_in_arr, single_character_in_line)
{
    int file_descr = 0;
    char expected_str[1] = {'.'};
    char actual_str[1] = {0};
    char buffer[2] = {0};
    int size_read = 1;

    file_descr = open("tests/single_column_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; ) {
        read(file_descr, buffer, 1);
    }
    cr_expect_eq(copy_line_in_arr(file_descr, 1, actual_str, &size_read), 0);
    cr_expect_arr_eq(actual_str, expected_str, 1);
    close(file_descr);
}

Test(copy_line_in_arr, several_characters_in_line)
{
    int file_descr = 0;
    char expected_str[20];
    char actual_str[20] = {0};
    char buffer[2] = {0};
    int size_read = 1;

    for (int i = 0; i < 20; i++)
        expected_str[i] = '.';
    file_descr = open("tests/big_map_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; ) {
        read(file_descr, buffer, 1);
    }
    cr_expect_eq(copy_line_in_arr(file_descr, 20, actual_str, &size_read), 0);
    cr_expect_arr_eq(actual_str, expected_str, 20);
    close(file_descr);
}

Test(copy_line_in_arr, failed_read)
{
    int file_descr = 0;
    char expected_str[20];
    char actual_str[20] = {0};
    char buffer[2] = {0};
    int size_read = 0;

    for (int i = 0; i < 20; i++)
        expected_str[i] = '.';
    file_descr = open("tests/big_map_file.txt", O_RDONLY);
    for ( ; buffer[0] != '\n'; ) {
        read(file_descr, buffer, 1);
    }
    cr_expect_eq(copy_line_in_arr(file_descr, 20, actual_str, &size_read), 0);
    close(file_descr);
}