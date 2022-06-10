/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen
*/

#include "../my.h"

int my_len(int *str)
{
    int length = 0;

    for (int i = 0; str[i]; i++) {
        length++;
    }
    return length;
}
