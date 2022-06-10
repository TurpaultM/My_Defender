/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** return a number
*/

#include "../my.h"

int def_sign(char const *str, int i, int k)
{
    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45)
            k = k * -1;
        i++;
    }
    return (k);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long j = 0;
    int k = 1;
    k = def_sign(str, i, k);
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            j = j * 10 + str[i] - 48;
        } else if (j != 0)
            return (j);
        i++;
    }
    if (j > 2147483647)
        return (0);
    return (j * k);
}
