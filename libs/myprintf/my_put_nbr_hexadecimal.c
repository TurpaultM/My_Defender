/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** emacs
*/

#include "../my.h"

void my_put_nbr_hexadecimal(unsigned long nb)
{
    char *res = malloc(sizeof(res) * 5000);
    int result = 0;
    long quotient = 0;
    int str_valur = 0;

    for (; nb; str_valur++) {
        quotient = nb / 16;
        result = nb - (quotient * 16);
        nb = nb / 16;
        if (result >= 10)
            result = result + 39;
        res[str_valur] = result + '0';
    }
    res[str_valur] = '\0';
    my_revstr(res);
    my_putstr(res);
    free(res);
}

void my_put_nbr_hexadecimal_maj(unsigned long nb)
{
    char *res = malloc(sizeof(res) * 5000);
    int i = 0;
    long quo = 0;
    int x = 0;

    for (; nb != 0; x++) {
        quo = nb / 16;
        i = nb - (quo * 16);
        nb = nb / 16;
        if (i >= 10)
            i = i + 7;
        res[x] = i + '0';
    }
    res[x] = '\0';
    my_revstr(res);
    my_putstr(res);
    free(res);
}

void my_put_nbr_pointeur(unsigned long nb)
{
    my_putstr("0x");
    my_put_nbr_hexadecimal(nb);
}