/*
** EPITECH PROJECT, 2022
** get_map_from_argv.c
** File description:
** -> Generates a map according to a pattern and a size (from argv)
*/

#include <my.h>
#include "bsq.h"
#include <stdlib.h>

static unsigned **split_map(unsigned *const map, size_t dimensions)
{
    unsigned **map_buffer = malloc(sizeof(unsigned *) * (dimensions + 1));
    unsigned *map_iter = map;

    map_buffer[dimensions] = NULL;
    for (size_t i = 0; i < dimensions; i++) {
        map_buffer[i] = malloc(sizeof(unsigned) * (dimensions + 1));
        for (size_t j = 0; j < dimensions; j++) {
            map_buffer[i][j] = *map_iter++;
        }
        map_buffer[i][dimensions] = LINE_END;
    }
    free(map);
    return map_buffer;
}

static unsigned **generator(size_t dimensions, char *const pattern)
{
    size_t pattern_index = 0;
    const size_t pattern_length = my_strlen(pattern);
    unsigned *buffer = malloc(sizeof(unsigned) * (dimensions * dimensions + 1));
    unsigned *const buffer_start = buffer;

    for (size_t i = 0; i < dimensions; i++) {
        for (size_t j = 0; j < dimensions; j++) {
            *buffer++ = pattern[pattern_index];
            pattern_index = (pattern_index + 1) % pattern_length;
        }
    }
    *buffer = LINE_END;
    return split_map(buffer_start, dimensions);
}

unsigned **get_map(int argc, char *argv[])
{
    if (argc == 2) {
        return read_from_file(argv[1]);
    }
    if (argc == 3) {
        return generator(my_getnbr(argv[1]), argv[2]);
    }
    return NULL;
}
