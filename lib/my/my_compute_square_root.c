/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** ->   computes square root of parameter
*/

int my_compute_square_root(int nb)
{
    for (int i = 0;; i++) {
        const int power = i * i;
        if (power == nb) {
            return i;
        }
        if (power > nb) {
            return 0;
        }
    }
}
