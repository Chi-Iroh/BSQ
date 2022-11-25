/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** ->   recursive function to compute nb raised to power p
*/

#include <limits.h>
#include "my.h"
#include "my_macros.h"

int my_compute_power_rec(int nb, int p)
{
    if (p <= 0) {
        return p == 0;
    }
    if (nb == 0) {
        return 0;
    }
    const int previous_power = my_compute_power_rec(nb, p - 1);
    if (previous_power < 0 && previous_power < INT_MIN / ABS(nb)) {
        return 0;
    }
    if (previous_power > 0 && previous_power > INT_MAX / ABS(nb)) {
        return 0;
    }
    return nb * previous_power;
}
