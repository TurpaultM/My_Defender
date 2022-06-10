/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** emacs
*/

#include "../my.h"

long my_put_nbr(long nb)
{
    long modulo;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            modulo = (nb % 10);
            nb = (nb - modulo) / 10;
            my_put_nbr(nb);
            my_putchar('0' + modulo);
        } else
            my_putchar('0' + nb % 10);
    }
    return (nb);
}

int error(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (1);
    }
    if (nb > 2147483647 || nb < -2147483647)
        return (84);
    return (0);
}

int my_put_nbri(int nb)
{
    int modulo;
    int verif = error(nb);

    if (verif != 0) {
        return (nb);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            modulo = (nb % 10);
            nb = (nb - modulo) / 10;
            my_put_nbri(nb);
            my_putchar('0' + modulo);
        } else
            my_putchar('0' + nb % 10);
    }
    return (nb);
}

int my_put_nbrus(int nb)
{
    int modulo;

    if (nb < 0)
        nb = nb * (-1);
    if (nb >= 0) {
        if (nb >= 10) {
            modulo = (nb % 10);
            nb = (nb - modulo) / 10;
            my_put_nbr(nb);
            my_putchar('0' + modulo);
        } else
            my_putchar('0' + nb % 10);
    }
    return (nb);
}

char *int_to_bin(int bin)
{
    char *res = malloc(sizeof(res) * 5000);
    int i = 0;

    for (int x = 0; bin; x++) {
        i = bin % 2;
        bin = bin / 2;
        res[x] = i + '0';
    }
    my_revstr(res);
    my_putstr(res);
    free(res);
    return (res);
}
