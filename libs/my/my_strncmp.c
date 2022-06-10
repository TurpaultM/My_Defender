/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** comparaison entre 2 dtr
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int cmp = 0;

    while (cmp != n) {
        if (s1[cmp] != s2[cmp])
            return (s1[cmp] - s2[cmp]);
        cmp++;
    }
    return (0);
}
