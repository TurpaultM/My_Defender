/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen
*/

#include "../my.h"

int my_arrlen(char **arr)
{
    int a = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        a++;
    }
    return (a);
}
