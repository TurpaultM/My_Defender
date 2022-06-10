/*
** EPITECH PROJECT, 2021
** file for my_printf
** File description:
** functions for my_printf
*/

#ifndef _PRINT_
    #define _PRINT_
void my_putsterr(char const *str);
int my_put_nbri(int nb);
char *inttochar(int nb);
long my_put_nbr(long nb);
int my_put_nbrus(int nb);
int my_getnbr(char const *str);
char *int_to_bin(int bin);
char *my_revstr(char *str);
int my_put_nbr_plus(int nb);
void my_putchar(char const);
void my_printf(char *, ...);
int my_put_nbr_space(int nb);
void my_put_nbr_octal(int nb);
int my_strlen(char const *str);
int my_put_nbr_sh(short int nb);
void my_putstr(char const *str);
void my_put_nbrf(double nb, int);
int my_compute_power_rec(int nb, int p);
void my_put_nbr_pointeur(unsigned long nb);
void my_put_nbr_hexadecimal(unsigned long nb);
void my_put_nbr_hexadecimal_maj(unsigned long nb);
#endif
