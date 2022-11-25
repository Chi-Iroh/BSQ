/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** ->   cduplicates a string
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
    unsigned const length = my_strlen((char *)src);
    char *copy = malloc(sizeof(char) * (length + 1));

    if (!src) {
        copy[0] = '\0';
        return copy;
    }
    for (unsigned i = 0; i <= length; i++) {
        *(copy + i) = *(src + i);
    }
    return copy;
}
