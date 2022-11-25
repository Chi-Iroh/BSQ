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
    char **map = get_map(argc, argv);

    if (!map) {
        return 84;
    }
    bsq(map, my_strlen(map[0]));
    return 0;
}
