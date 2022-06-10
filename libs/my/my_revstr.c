/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse string
*/

#include "../my.h"

char *my_revstr(char *str)
{
    int tall = 0;
    int N = my_strlen(str) - 1;
    char rvs;

    while (tall < N) {
        rvs = str[tall];
        str[tall] = str[N];
        str[N] = rvs;
        tall++;
        N--;
    }
    return (str);
}
