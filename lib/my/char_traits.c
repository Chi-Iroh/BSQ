/*
** EPITECH PROJECT, 2022
** char_traits.c
** File description:
** -> functions to check a char's traits, such as if it's a letter
*/

int is_letter(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
