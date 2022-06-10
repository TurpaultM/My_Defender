/*
** EPITECH PROJECT, 2021
** display stdarg
** File description:
** strarg
*/

#include <stdio.h>
#include <stdarg.h>
#include "../my.h"

int error_sh(int nb)
{
    if (nb > 32767 || nb < -32767)
        return (84);
    return (0);
}

int my_put_nbr_sh(short int nb)
{
    int modulo;
    int verif = error_sh(nb);

    if (verif != 0)
        return (nb);
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

int my_put_nbr_plus(int nb)
{
    int modulo;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    } else
        my_putchar('+');
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

int my_put_nbr_space(int nb)
{
    int modulo;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    } else
        my_putchar(' ');
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