/*
** EPITECH PROJECT, 2021
** project is bsq
** File description:
** find bigger square
*/

#include "../my.h"

int nb_word(char* str, char lim)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == lim || str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            continue;
        len++;
        for (; str[i + 1] != lim && str[i + 1] != ' ' &&
        str[i + 1] != '\t' && str[i + 1] != '\0' && str[i + 1] != '\n'; i++);
    }
    if (len == 0) {
        return (1);
    } else {
        return (len);
    }
}

int *nb_mlc(char *str, char lim)
{
    int *nb = malloc(sizeof(int) * nb_word(str, lim) + 1);
    int x = 0;

    for (int i = 0; i != nb_word(str, lim) ; i++)
        nb[i] = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == lim || str[i] == ' ' ||
        str[i] == '\t' || str[i] == '\n')
            continue;
        nb[x] += 1;
        if (str[i + 1] == lim || str[i + 1] == ' ' ||
        str[i + 1] == '\t' || str[i + 1] == '\n') {
            nb[x]++;
            x++;
        }
    }
    return (nb);
}

int space(char *str, int x, char lim)
{
    for (; str[x] == '\t' || str[x] == ' ' ||
    str[x] == '\n' || str[x] == lim; x++);
    return (x);
}

char *insert(char *str, char lim, char *arr, int nb)
{
    static int x = 0;
    int i = 0;

    x = space(str, x, lim);
    if (nb == 0) {
        x = 0;
        return (NULL);
    }
    for (; str[x] != lim && str[x] != ' ' && str[x] != '\t'
    && str[x] != '\n' && str[x] != '\0'; i++, x++) {
        arr[i] = str[x];
    }
    arr[i] = '\0';
    return (arr);
}

char **my_str_word_array(char *str, char lim)
{
    char **array = malloc(sizeof(char*) * (nb_word(str, lim) + 1));
    int *nb = nb_mlc(str, lim);

    for (int x = 0; x != nb_word(str, lim); x++) {
        array[x] = malloc(sizeof(char) * nb[x]);
        array[x] = insert(str, lim, array[x], 1);
    }
    array[nb_word(str, lim)] = NULL;
    insert("e", 'x', "i", 0);
    return (array);
}
