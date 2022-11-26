/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** -> main
*/

#include "bsq.h"
#include <my.h>

int main(int argc, char *argv[])
{
    unsigned **map = get_map(argc, argv);

    if (!map) {
        return 84;
    }
    bsq(map);
    return 0;
}
