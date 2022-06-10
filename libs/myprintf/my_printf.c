/*
** EPITECH PROJECT, 2021
** display stdarg
** File description:
** strarg
*/

#include <stdio.h>
#include <stdarg.h>
#include "../my.h"

int char_to_int(char nb)
{
    int res = 0;

    res = res + (nb - '0');
    return (res);
}

int print_float(char *s, va_list ap, int i)
{
    int pow = 0;

    if (s[i + 1] == '.' && (s[i + 2] >= '0' &&
    s[i + 2] <= '9') && s[i + 3] == 'f') {
        pow = char_to_int(s[i + 2]);
        my_put_nbrf(va_arg(ap, double), pow);
        i = i + 3;
    }
    if (s[i + 1] == 'f') {
        my_put_nbrf(va_arg(ap, double), 6);
        i = i + 1;
    }
    return i;
}

void my_printf(char *str, ...)
{
    va_list ap;
    int j = 0;
    va_start(ap, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '%') {
            my_putchar('%');
            i++;
            continue;
        }
        if (str[i] == '%') {
            j = i;
            i = print_float(str, ap, i);
            i = print_arg(str, ap, i);
            j == i ? my_putchar(str[i]) : 0;
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(ap);
}
