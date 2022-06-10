/*
** EPITECH PROJECT, 2021
** int to char
** File description:
** transform int in char*
*/

#include "../my.h"

char *inttochar(int nb)
{
    int i = 0;
    char *fin = 0;
    char *res = malloc(sizeof(res) * 20);
    if (nb == 0)
        return ("0");
    for (int x = 0; nb != 0; x++) {
        i = nb % 10;
        nb = nb / 10;
        res[x] = i + '0';
        res[x + 1] = 0;
    }
    my_revstr(res);
    fin = res;
    return fin;
    free(res);
}
