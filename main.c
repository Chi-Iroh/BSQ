/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** -> main
*/

#include "bsq.h"
#include <my.h>

int main(int argc, char *argv[])
{
    char **map = get_map(argc, argv);
    const size_t map_size = str_array_length(map);

    if (check_map(map, map_size) == 84) {
        return 84;
    }
    bsq(map);
    return 0;
}
