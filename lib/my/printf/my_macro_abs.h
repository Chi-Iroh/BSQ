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
