/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** emacs
*/

#include "../my.h"

void my_put_nbrf(double nb, int pow)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    pow--;
    int virgule = my_compute_power_rec(10, pow);
    int avv = nb;
    my_put_nbr(avv);
    my_putchar('.');
    avv = avv * virgule;
    nb = nb * virgule;
    nb = nb - avv;
    my_put_nbr(nb);
}