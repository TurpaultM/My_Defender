/*
** EPITECH PROJECT, 2021
** compute power rec
** File description:
** pow nb
*/

#include "../my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    p = p - 1;
    return (nb * my_compute_power_rec(nb, p));
}
