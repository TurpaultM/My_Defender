/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen
*/

#include "../my.h"

int my_strlen(char const *str)
{
    int a = 0;

    for (int i = 0; str[i]; i ++) {
        a += 1;
    }
    return (a);
}
