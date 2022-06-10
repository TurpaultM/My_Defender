/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** my_putstr
*/

#include "../my.h"

void my_putsterr(char const *str)
{
    int size = 0;

    size = my_strlen(str);
    write(2, str, size);
}
