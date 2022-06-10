/*
** EPITECH PROJECT, 2017
** strcat
** File description:
** strcat
*/

#include "../my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    res[(my_strlen(dest) + my_strlen(src))] = '\0';
    for (; dest[i] != '\0'; i++) {
        res[i] = dest[i];
    }
    for (; src[j] != '\0'; j++) {
        res[i + j] = src[j];
    }
    free(dest);
    return (res);
}
