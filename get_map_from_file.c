/*
** EPITECH PROJECT, 2022
** read_map_from_file.c
** File description:
** -> reads the map from file given as param
*/

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

static char *read_line(int fd)
{
    char *buffer = NULL;
    char c = '\0';
    int is_ok = 1;

    while (1) {
        is_ok |= read(fd, &c, 1) == 1;
        if (!is_ok || c == '\n') {
            break;
        }
        buffer = str_append(buffer, c);
    }
    if (!is_ok && buffer) {
        free(buffer);
        buffer = NULL;
    }
    return buffer;
}

static int is_map_valid(char **map, size_t dimensions)
{
    int is_ok = map != NULL;
    const size_t str_length = map ? my_strlen(map[0]) : 0;

    for (size_t i = 0; i < dimensions; i++) {
        is_ok &= map[i] != NULL;
        for (size_t j = 0; map[i][j] && !is_ok; j++) {
            is_ok &= map[i][j] != 'o' && map[i][j] != '.';
        }
        if (!is_ok) {
            break;
        }
        is_ok &= my_strlen(map[i]) == str_length;
    }
    return is_ok ? 0 : 84;
}

int check_map(char **map, size_t dimensions)
{
    if (is_map_valid(map, dimensions) == 0) {
        return 0;
    }
    for (size_t i = 0; map && i < dimensions; i++) {
        if (map[i]) {
            free(map[i]);
        }
    }
    if (map) {
        free(map);
    }
    return 84;
}

char **read_from_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    size_t dimensions = get_map_dimensions_from_file(fd);
    char **file_buffer = NULL;

    if (fd == -1 || errno != 0) {
        return NULL;
    }
    for (size_t i = 0; i < dimensions; i++) {
        file_buffer = str_array_append(file_buffer, read_line(fd));
    }
    return check_map(file_buffer, dimensions) == 84 ? NULL : file_buffer;
}
