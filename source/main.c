/*
** EPITECH PROJECT, 2019
** BSQ : main.c
** File description:
** main function : find the largest square on a map while avoiding obstacles.
*/

#include "main.h"

int main(int ac, char **av)
{
    map_t *map = NULL;
    square biggest_square = {-1, -1, 0};

    if (ac != 2 || detect_error_in_file(av[1]) == 84)
        return (84);
    map = malloc(sizeof(map_t));
    if (map == NULL)
        return (84);
    else if (load_map_from_file(av[1], map) == 84) {
        free(map);
        return (84);
    }
    if (find_biggest_square_in_map(map, &biggest_square) == 84) {
        free_map(map);
        return (84);
    }
    display_result(map, &biggest_square);
    free_map(map);
    return (0);
}