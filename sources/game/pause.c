/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** game pause
*/

#include "game.h"

void init_valid(validation_t *val)
{
    val->pause_sprt = sfSprite_create();
    val->pause_txtr =
    sfTexture_createFromFile("image/option/PAUSE_MENU.jpg", NULL);
    val->size.x = 1.5;
    val->size.y = 1.5;
    sfSprite_setTexture(val->pause_sprt, val->pause_txtr, sfFalse);
    sfSprite_setPosition(val->pause_sprt, val->pos);
    sfSprite_setScale(val->pause_sprt, val->size);
}

void press_butt(global_t *glob, pokemons_t *pok)
{
    if (glob->event.mouseButton.x >= 840 && glob->event.mouseButton.x <= 1160
    && glob->event.mouseButton.y >= 415 && glob->event.mouseButton.y <= 472
    && pok->time->pause == true)
        pok->time->pause = false;
    if (glob->event.mouseButton.x >= 840 && glob->event.mouseButton.x <= 1160
    && glob->event.mouseButton.y >= 570 && glob->event.mouseButton.y <= 635
    && pok->time->pause == true) {
        destroy_all_pokemons(pok);
        menu_game(glob);
    }
}

void print_menu(sfRenderWindow *window, validation_t *val, bool pause)
{
    if (pause == true) {
        val->pos.x = 555;
        val->pos.y = 310;
        sfSprite_setPosition(val->pause_sprt, val->pos);
    } else {
        val->pos.x = -1000;
        val->pos.y = 0;
        sfSprite_setPosition(val->pause_sprt, val->pos);
    }
    sfRenderWindow_drawSprite(window, val->pause_sprt, NULL);
}
