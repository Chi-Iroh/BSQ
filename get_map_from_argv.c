/*
** EPITECH PROJECT, 2022
** get_map_from_argv.c
** File description:
** -> Generates a map according to a pattern and a size (from argv)
*/

#include <my.h>
#include "bsq.h"
#include <stdlib.h>

static char **split_map(char *const map, size_t dimensions)
{
    char **map_buffer = str_array_init(dimensions + 1);
    char *map_iter = map;

    for (size_t i = 0; i < dimensions; i++) {
        map_buffer[i] = my_calloc(dimensions + 1);
        my_strncpy(map_buffer[i], map_iter, dimensions);
        map_iter += dimensions;
    }
    free(map);
    return map_buffer;
}

static char **generator(size_t dimensions, char *const pattern)
{
    size_t pattern_index = 0;
    const size_t pattern_length = my_strlen(pattern);
    char *buffer = my_calloc(dimensions * dimensions + 1);
    char *const buffer_start = buffer;

    for (size_t i = 0; i < dimensions; i++) {
        for (size_t j = 0; j < dimensions; j++) {
            *buffer++ = pattern[pattern_index];
            pattern_index = (pattern_index + 1) % pattern_length;
        }
    }
    return split_map(buffer_start, dimensions);
}

char **get_map(int argc, char *argv[])
{
    if (argc == 2) {
        return read_from_file(argv[1]);
    }
    if (argc == 3) {
        return generator(my_getnbr(argv[1]), argv[2]);
    }
    return NULL;
}
