/*
** EPITECH PROJECT, 2021
** char to int
** File description:
** char to int
*/

#include "../my.h"

int char_to_int(char *nb)
{
    int res = 0;
    int pow = 0;

    for (int i = 0; i != my_strlen(nb); i++) {
        res = res + (nb[i] - '0');
        pow++;
        if (nb[i + 1] != '\0')
            res *= 10;
    }
    return (res);
}
