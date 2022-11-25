/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** -> bsq algorithm
*/

#include <my.h>
#include "bsq.h"
#include <my_macros.h>
#include <stdlib.h>

static unsigned **convert_map(char **const map, size_t line_size)
{
    unsigned **uint_map = malloc(sizeof(unsigned *) * str_array_length(map));

    for (size_t i = 0; map[i]; i++) {
        uint_map[i] = malloc(sizeof(unsigned) * line_size);
        for (size_t j = 0; j < line_size; j++) {
            uint_map[i][j] = 0;
        }
    }
    return uint_map;

}

static void
replace_val(char **map, unsigned **uint_map, square_t *max, coords_t coords)
{
    unsigned *val = &uint_map[coords.i][coords.j];

    if (map[coords.i][coords.j] == 'o') {
        *val = 0;
    } else if (coords.i == 0 || coords.j == 0) {
        *val = 1;
    } else {
        *val = uint_map[coords.i][coords.j - 1];
        *val = MIN(*val, uint_map[coords.i - 1][coords.j - 1]);
        *val = MIN(*val, uint_map[coords.i - 1][coords.j]) + 1;
    }
    if (max->max_square < *val) {
        max->i = coords.i;
        max->j = coords.j;
        max->max_square = *val;
    }
}

static square_t get_max_square(char **map)
{
    const size_t line_size = my_strlen(map[0]);
    unsigned **uint_map = convert_map(map, line_size);
    square_t max_square = {0, 0, 0};

    for (size_t i = 0; map[i]; i++) {
        for (size_t j = 0; map[i][j]; j++) {
            replace_val(map, uint_map, &max_square, (coords_t){i, j});
        }
    }
    for (size_t i = 0; map[i]; i++) {
        free(uint_map[i]);
    }
    free(uint_map);
    return max_square;
}

static void insert_square(char **map)
{
    const char c = map[coords.i][coords.j];
    int is_in_square = 0;

    if (c == 'o') {
        return c;
    }
    is_in_square = square->i - coords.i < square->max_square;
    is_in_square &= square->j - coords.j < square->max_square;
    return is_in_square ? 'x' : '.';
}

void bsq(char **map)
{
    const square_t max_square = get_max_square(map);
    insert_square(map);

    for (size_t i = 0; map[i]; i++) {
        for (size_t j = 0; map[i][j]; j++) {
            my_putchar(map[i][j]);
        }
        free(map[i]);
        my_putchar('\n');
    }
    free(map);
}
