/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** -> protos
*/

#pragma once

#include <stddef.h>

#define LINE_END ((unsigned)-1)

unsigned **read_from_file(char *file_path);

unsigned**get_map(int argc, char *argv[]);

int check_map(unsigned **map, size_t dimensions);

void bsq(unsigned **map);

typedef struct {
    unsigned max_square;
    unsigned i;
    unsigned j;
} square_t;

typedef struct {
    unsigned i;
    unsigned j;
} coords_t;

typedef struct {
    unsigned *line;
    size_t length;
} line_t;
