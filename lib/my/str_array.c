/*
** EPITECH PROJECT, 2022
** str_array.c
** File description:
** -> functions to work with arrays of strings
*/

/*
** EPITECH PROJECT, 2022
** string_array.c
** File description:
** -> functions for manipulating arrays of strings
*/

#include "my.h"
#include <stdlib.h>

size_t str_array_length(char **const array)
{
    size_t length = 0;

    while (array && array[length]) {
        length++;
    }
    return length;
}

char **str_array_append(char **array, char *str)
{
    char **new_array = malloc((str_array_length(array) + 2) * sizeof(char *));
    size_t i = 0;

    while (array && array[i]) {
        new_array[i] = array[i];
        i++;
    }
    new_array[i++] = str;
    new_array[i] = NULL;
    if (array) {
        free(array);
    }
    return new_array;
}

char **make_str_array(char *str)
{
    char **array = malloc(2 * sizeof(char *));

    array[0] = str;
    array[1] = NULL;
    return array;
}

char **str_array_extend(char **array, char **add)
{
    const size_t total_size = str_array_length(array) + str_array_length(add);
    char **new_array = malloc((total_size + 1) * sizeof(char *));
    size_t array_index = 0;

    for (size_t i = 0; array && array[i]; i++) {
        new_array[array_index++] = array[i];
    }
    for (size_t i = 0; add && add[i]; i++) {
        new_array[array_index++] = add[i];
    }
    new_array[array_index] = NULL;
    if (array) {
        free(array);
    }
    if (add) {
        free(add);
    }
    return new_array;
}

char **str_array_init(size_t n_strings)
{
    char **array = malloc(sizeof(char *) * n_strings);

    for (size_t i = 0; i < n_strings; i++) {
        array[i] = NULL;
    }
    return array;
}
