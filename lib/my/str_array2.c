/*
** EPITECH PROJECT, 2022
** str_array2.c
** File description:
** -> functions to work with arrays of strings
*/

#include <stddef.h>
#include <stdlib.h>

void str_array_free(char **array, size_t length)
{
    for (size_t i = 0; i < length; i++) {
        if (array && array[i]) {
            free(array[i]);
        }
    }
    if (array) {
        free(array);
    }
}
