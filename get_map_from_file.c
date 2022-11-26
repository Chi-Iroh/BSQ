/*
** EPITECH PROJECT, 2022
** read_map_from_file.c
** File description:
** -> reads the map from file given as param
*/

#include "bsq.h"
#include <my.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

static size_t get_map_dimensions_from_file(int fd)
{
    size_t n = 0;
    char c = '\0';

    while (1) {
        if (read(fd, &c, 1) != 1 || c == '\n') {
            break;
        }
        n = 10 * n + (c - '0');
    }
    return n;
}

static line_t make_line(size_t length, unsigned *line)
{
    return (line_t) {
        .length = length,
        .line = line
    };
}

static line_t read_line(int fd)
{
    unsigned *buffer = malloc(sizeof(unsigned) * 10001);
    unsigned *const buffer_start = buffer;
    int is_ok = 1;
    char c = '\0';
    size_t length = 0;

    do {
        is_ok |= read(fd, &c, 1) == 1;
        if (!is_ok || c == '\n') {
            break;
        }
        *buffer++ = c;
    } while (++length);
    *buffer = LINE_END;
    if (!is_ok && buffer_start) {
        free(buffer_start);
        return make_line(0, NULL);
    }
    return make_line(length, buffer_start);
}

static int add_line(unsigned **file_buffer, line_t line, size_t i)
{
    static size_t first_length = 0;

    if (i == 0) {
        first_length = line.length;
    }
    if (i > 0 && line.length != first_length) {
        return 0;
    }
    for (size_t i = 0; line.line[i] != LINE_END; i++) {
        if (line.line[i] != '.' && line.line[i] != 'o') {
            return 0;
        }
    }
    file_buffer[i] = line.line;
    return 1;
}

unsigned **read_from_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    size_t dimensions = get_map_dimensions_from_file(fd);
    unsigned **file_buffer = NULL;

    if (fd == -1 || errno != 0) {
        return NULL;
    }
    file_buffer = malloc(sizeof(unsigned *) * (dimensions + 1));
    file_buffer[dimensions] = NULL;
    for (size_t i = 0; i < dimensions; i++) {
        if (!add_line(file_buffer, read_line(fd), i)) {
            FREE_ARRAY_SIZE(file_buffer, dimensions);
            return NULL;
        }
    }
    return file_buffer;
}
