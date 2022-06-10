/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** get the following line
*/

#include "../my.h"

char *concat_n_string(char *dest, char *src, int n)
{
    int i = my_strlen(dest) + 1;
    char *res = malloc(sizeof(char) * (i + n));

    if (!(res))
        return (NULL);
    for (i = 0; dest[i]; i++)
        res[i] = dest[i];
    for (int j = 0; n != 0 && j < n; j++)
        res[i + j] = src[j];
    res[i + n] = '\0';
    return (res);
}
