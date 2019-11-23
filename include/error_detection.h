/*
** EPITECH PROJECT, 2019
** BSQ : error_detection.h
** File description:
** Functions used to detect errors in the file. (header)
*/

#ifndef DEF_ERROR_DETECTION
#define DEF_ERROR_DETECTION

#include <unistd.h>
#include <fcntl.h>

int detect_error_in_file(char *filepath);
int check_first_line(int file_descr);
int check_map(int file_descr);
int is_digit(char c);
int handle_lines_sizes(int *size_curr_line, int *size_last_line, char buffer);

#endif // DEF_ERROR_DETECTION