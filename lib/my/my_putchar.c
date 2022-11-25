/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** ->   puts a single char in stdout stream
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}
