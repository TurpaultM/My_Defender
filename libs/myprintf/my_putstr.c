/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** my_putstr
*/

#include "../my.h"

void my_putstr(char const *str)
{
    int size = 0;

    size = my_strlen(str);
    write(1, str, size);
}
