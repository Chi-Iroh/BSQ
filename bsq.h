/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** -> protos
*/

#pragma once

#include <stddef.h>

char **read_from_file(char *file_path);

char **get_map(int argc, char *argv[]);

int check_map(char **map, size_t dimensions);

void bsq(char **map);

typedef struct {
    unsigned max_square;
    unsigned i;
    unsigned j;
} square_t;

typedef struct {
    unsigned i;
    unsigned j;
} coords_t;
