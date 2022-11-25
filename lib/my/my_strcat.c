/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** ->   concats two strings
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    const unsigned dest_size = my_strlen(dest);
    for (unsigned i = 0; src; i++) {
        if (!*(src + i)) {
            *(dest + dest_size + ++i) = '\0';
            break;
        }
        *(dest + dest_size + i) = *(src + i);
    }
    return dest;
}
