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
#include <unistd.h>

static void
replace_val(unsigned **map, square_t *max, coords_t coords)
{
    unsigned *val = &map[coords.i][coords.j];

    if (*val == 'o') {
        *val = 0;
    } else if (coords.i == 0 || coords.j == 0) {
        *val = 1;
    } else {
        *val = map[coords.i][coords.j - 1];
        *val = MIN(*val, map[coords.i - 1][coords.j - 1]);
        *val = MIN(*val, map[coords.i - 1][coords.j]) + 1;
    }
    if (max->max_square < *val) {
        max->i = coords.i;
        max->j = coords.j;
        max->max_square = *val;
    }
}

static square_t get_max_square(unsigned **map)
{
    square_t max_square = {0, 0, 0};

    for (size_t i = 0; map[i]; i++) {
        for (size_t j = 0; map[i][j] != LINE_END; j++) {
            replace_val(map, &max_square, (coords_t){i, j});
        }
    }
    return max_square;
}

static void insert_square(unsigned **map, const square_t *const square)
{
    const size_t start_i = square->i - (square->max_square - 1);
    const size_t start_j = square->j - (square->max_square - 1);

    for (size_t i = start_i; i <= square->i; i++) {
        for (size_t j = start_j; j <= square->j; j++) {
            map[i][j] = 'x';
        }
    }
}

static void display_and_free(unsigned **map)
{
    char *buffer = malloc(sizeof(char) * 10000 * 10001);
    size_t index = 0;
    size_t i = 0;
    size_t max_j = 0;
    size_t j = 0;
    char c = '\0';

    for (; map[i]; i++) {
        for (j = 0; map[i][j] != LINE_END; j++) {
            c = map[i][j];
            buffer[index++] = ((c == 0) ? 'o' : ((c == 'x') ? 'x' : '.'));
        }
        max_j = j + 1;
        buffer[index++] = '\n';
    }
    write(STDOUT_FILENO, buffer, i * max_j);
    free(buffer);
    FREE_ARRAY(map);
}

void bsq(unsigned **map)
{
    const square_t max_square = get_max_square(map);

    insert_square(map, &max_square);
    display_and_free(map);
}
