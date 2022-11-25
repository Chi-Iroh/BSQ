/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** ->   calloc allocates a string and fills it with '\0's
*/

#include <stddef.h>
#include <stdlib.h>

char *my_calloc(size_t length)
{
    char *str = malloc(sizeof(char) * length);

    for (size_t i = 0; i < length; i++) {
        str[i] = '\0';
    }
    return str;
}
