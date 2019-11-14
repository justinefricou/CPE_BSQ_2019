/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Functions to work with maps.
*/

#include "include/map.h"

void free_map(map_t map)
{
    for (int i = 0; i < map.cols; i++)
        free(map.array[i]);
    free(map.array);
}