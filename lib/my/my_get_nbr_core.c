/*
** EPITECH PROJECT, 2022
** my_getnbr_core.c
** File description:
** ->   core functions for get_nbr.c
** ->   allowed function : my_putchar
*/

#include <limits.h>

int is_char_valid_in_nbr(char c)
{
    return (c >= '0' && c <= '9') || (c == '-' || c == '+');
}

int my_nbr_strlen(const char *str)
{
    int length = 0;
    while (str && is_char_valid_in_nbr(*str)) {
        length++;
        str++;
    }
    return length;
}

int max_power_before_long_long_overflow(void)
{
    long long n = 1;
    int power = 0;
    while (n < LLONG_MAX / 10) {
        n *= 10;
        power++;
    }
    return power;
}

long long my_pow10(int n)
{
    if (n > max_power_before_long_long_overflow()) {
        return -1;
    }
    long long pow = 1;
    while (n--) {
        pow *= 10;
    }
    return pow;
}
