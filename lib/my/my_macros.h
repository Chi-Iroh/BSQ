/*
** EPITECH PROJECT, 2022
** my_macro_abs.h
** File description:
** ->   macro for absolute value
*/

#pragma once

#ifdef ABS
    #undef ABS
#endif
#define ABS(value) ((value) < 0 ? -(value) : (value))

#ifdef UNSIGNED_ABS
    #undef UNSIGNED_ABS
#endif
#define UNSIGNED_ABS(n1, n2) (MAX(n1, n2) - MIN(n1, n2))

#ifdef MIN
    #undef MIN
#endif
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#ifdef MAX
    #undef MAX
#endif
#define MAX(a, b) ((a) > (b) ? (a) : (b))
