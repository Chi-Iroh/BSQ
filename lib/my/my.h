/*
** EPITECH PROJECT, 2022
** header.h
** File description:
** ->   protos
*/

#pragma once

#include <stddef.h>
#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>

#define FREE_ARRAY(array) {                                 \
        for (size_t i = 0; (array) && (array)[i]; i++) {    \
        free((array)[i]);                                   \
        }                                                   \
        if ((array)) {                                      \
            free((array));                                  \
        }                                                   \
    }

#define FREE_ARRAY_SIZE(array, size) {                      \
        for (size_t i = 0; (array) && i < (size); i++) {    \
            if ((array)[i]) {                               \
                free((array)[i]);                           \
            }                                               \
        }                                                   \
        if ((array)) {                                      \
            free((array));                                  \
        }                                                   \
    }

char *my_calloc(size_t length);

int my_abs(int n);

int my_is_prime(int n);

int my_pow10(int n);

int my_log10(int n);

void my_putchar(char c);

void my_puts(const char *str);

void my_putstr(const char *str);

char *my_evil_str(char *str);

int is_char_valid_in_nbr(char c);

int my_nbr_strlen(const char *str);

long long my_pow10l(int n);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, size_t n);

int my_strcmp(const char *s1, const char *s2);

char my_toupper(char c);

char my_tolower(char c);

char *my_revstr(char *str);

void my_putchar(char c);

char *my_strchr(char *str, char c);

char *my_strstr(char *str, const char *to_find);

char **my_str_to_word_array(const char *str);

int my_put_nbr(int nb);

char *my_itoa_base(intmax_t n, const char *base);

char *my_utoa_base(uintmax_t n, const char *base);

char *my_itoa(intmax_t n);

char *my_utoa(uintmax_t n);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_isneg(int n);

char *my_strcapitalize(char *str);

int my_str_isalpha(const char *str);

char *my_strlowcase(char *str);

int my_strncmp(const char *s1, const char *s2, size_t n);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

int my_getnbr(char const *str);

char *my_strdup(const char *src);

char my_toupper(char c);

char my_tolower(char c);

int my_isalpha(char c);

int my_printf(const char *restrict format, ...);

int my_wprintf(const wchar_t *restrict format, ...);

int my_vprintf(const char *restrict format, va_list args);

int my_wvprintf(const wchar_t *restrict format, va_list args);

char *my_calloc(size_t length);

wchar_t *my_wcalloc(size_t length);

int my_wgetnbr(const wchar_t *str);

void my_wputchar(wchar_t c);

int my_wputstr(const wchar_t *str);

int my_wstrcmp(const wchar_t *s1, const wchar_t *s2);

wchar_t *my_wstrndup(const wchar_t *src, size_t n);

wchar_t *my_wstrdup(const wchar_t *src);

size_t my_strlen(const char *str);

size_t my_wstrlen(const wchar_t *str);

const wchar_t *my_wstrstr(const wchar_t *str, const wchar_t *to_find);

char *str_append_cstr(char *str, char *to_add);

char *str_substr(char *str, size_t start, size_t count);

char *str_insert(char *str, int index, char c);

char *str_pop(char *str, size_t index);

char *cstr_append_cstr(char *str, char *to_add);

char *cstr_append_str(char *str, char *to_add);

char *str_append_cstr(char *str, char *to_add);

char *str_append_str(char *str, char *to_add);

char *cstr_padding(char *str, int length, int left_padding, char c);

char *str_back(char *str);

char *cstr_prepend(char *str, char c);

char *str_prepend(char *str, char c);

char *cstr_append(char *str, char c);

char *str_append(char *str, char c);

size_t str_array_length(char **const array);

char **str_array_append(char **array, char *str);

char **make_str_array(char *str);

char **str_array_extend(char **array, char **add);

char **str_array_init(size_t n_strings);

void str_array_free(char **array, size_t length);

// not implemented

void my_sort_int_array(int *tab, int size);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);
