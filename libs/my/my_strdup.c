/*
** EPITECH PROJECT, 2017
** strdup
** File description:
** duplicate str
*/

#include "../my.h"

char *my_strdup(char *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}
