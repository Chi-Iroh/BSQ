/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** ->   displays a string
** ->   allowed function : my_putchar
*/

#include "my.h"

void my_puts(const char *str)
{
    while (str && *str) {
        my_putchar(*str++);
    }
    my_putchar('\n');
}

void my_putstr(const char *str)
{
    while (str && *str) {
        my_putchar(*str++);
    }
}
