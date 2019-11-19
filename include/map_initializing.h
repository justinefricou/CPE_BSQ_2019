/*
** EPITECH PROJECT, 2019
** map_initializing.h
** File description:
** Functions to initialize a map's array, width and height. (header)
*/

#ifndef DEF_MAP_INITIALIZING
#define DEF_MAP_INITIALIZING

#include <unistd.h>
#include <fcntl.h>
#include "map.h"

int set_map_dimensions(char *filepath, map_t *map);
int get_number_from_line(int file_descr, int *nbr);
int get_columns_nb_from_file(int file_descr, int *nbr);
int copy_file_in_map(int file_descr, map_t map);
int copy_line_in_arr(int file_descr, map_t map, char *line, int *size_read);

#endif // DEF_MAP_INITIALIZING