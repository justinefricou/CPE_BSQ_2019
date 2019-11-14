/*
** EPITECH PROJECT, 2019
** load_2d_array_from_file.c
** File description:
** Loads the rectangle in the file (param) in a 2d-array.
*/

#include <stddef.h>
#include "include/map.h"
#include "include/mem_alloc_arrays.h"

int load_map_from_file(char *filepath, map_t map)
{
    int file_descr = 0;

    map.array = NULL;
    if (set_map_dimensions(filepath, map) == 84)
        return (84);
    if (mem_alloc_2d_array(map.array, map.rows, map.cols) == 84)
        return (84);
    file_descr = open(filepath, O_RDONLY);
    if (file_descr == -1)
        return (84);
    if (copy_file_in_map(file_descr, map) == 84) {
        close(file_descr);
        free_map(map);
        return (84);
    }
    return (0);
}