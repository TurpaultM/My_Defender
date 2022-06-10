/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** emacs
*/

#include "../my.h"

void my_put_nbr_octal(int nb)
{
    char *res = malloc(sizeof(res) * 5000);
    int i = 0;
    int x = 0;

    for (; nb != 0; x++) {
        i = nb % 8;
        nb = nb / 8;
        res[x] = i + '0';
    }
    res[x] = '\0';
    my_revstr(res);
    my_putstr(res);
    free(res);
}
