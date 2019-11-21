/*
** EPITECH PROJECT, 2019
** load_map_from_file.h
** File description:
** Functions to initialize a map's array, width and height. (header)
*/

#ifndef DEF_LOAD_MAP_FROM_FILE
#define DEF_LOAD_MAP_FROM_FILE

#include <stddef.h>
#include <fcntl.h>
#include "map.h"
#include "map_initializing.h"
#include "mem_alloc_arrays.h"

int load_map_from_file(char *filepath, map_t *map);

#endif // DEF_LOAD_MAP_FROM_FILE