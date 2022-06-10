/*
** EPITECH PROJECT, 2021
** project is bsq
** File description:
** find bigger square
*/

#include "../my.h"

int nb_wrd(char* buff, char lim)
{
    int len = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == lim)
            len++;
    }
    return (len + 1);
}

char **my_strtok(char *str, char lim)
{
    char **array = malloc(sizeof(char*) * (nb_wrd(str, lim) + 1));
    int y = 0;
    int w = 0;

    for (int nb = 0; nb < nb_wrd(str, lim); nb++)
        array[nb] = malloc(sizeof(char) * 10);
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == lim) {
            array[y][w] = '\0';
            y++;
            w = 0;
        }
        if (str[x] != lim) {
            array[y][w] = str[x];
            w++;
        }
    }
    array[nb_wrd(str, lim)] = NULL;
    return (array);
}
