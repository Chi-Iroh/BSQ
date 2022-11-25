/*
** EPITECH PROJECT, 2022
** my_string_insert.c
** File description:
** ->   function for inserting a char into a string
*/

#include "my.h"
#include "printf/my_printf.h"
#include <stdlib.h>

char *str_back(char *str)
{
    return str + my_strlen(str) - 1;
}

char *cstr_padding(char *str, int length, int left_padding, char c)
{
    const int str_length = my_strlen(str);
    for (int i = 0; i < length - str_length; i++) {
        str = left_padding ? str_prepend(str, c) : str_append(str, c);
    }
    return str;
}
