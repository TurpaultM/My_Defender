/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** tests
*/

#include "../includes/game_defender.h"
#include <criterion/criterion.h>

Test(button_way_1, easy)
{
    char *got = button_way_menu(0);
    cr_assert_str_eq(got, "image/menu/START_BUTTON.png");
}

Test(button_way_2, easy)
{
    char *got = button_way_menu(1);
    cr_assert_str_eq(got, "image/menu/OPTION_BUTTON.png");
}

Test(button_way_3, easy)
{
    char *got = button_way_menu(2);
    cr_assert_str_eq(got, "image/menu/EXIT_BUTTON.png");
}

Test(button_way_4, easy)
{
    char *got = button_way_menu(3);
    cr_assert_str_eq(got, "void");
}
