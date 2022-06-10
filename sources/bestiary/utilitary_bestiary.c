/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"

bool find_str(char *str, char find)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == find)
            return (true);
    }
    return (false);
}

bool which_poke(global_t *glob, int i)
{
    if (find_str(glob->pokedex_access, (i + 48)) == true)
        return (true);
    return (false);
}

void scroll_down(global_t *glob, poke_t **pok)
{
    if (glob->event.mouseWheelScroll.delta < 0) {
        for (int i = 0; i < 16; i++) {
            pok[i]->pos.y -= 100;
            sfSprite_setPosition(pok[i]->sprite, pok[i]->pos);
        }
    }
    if (pok[15]->pos.y < 520) {
        for (int i = 0; i < 16; i++) {
            pok[i]->pos.y += 100;
            sfSprite_setPosition(pok[i]->sprite, pok[i]->pos);
        }
    }
}

void scroll_up(global_t *glob, poke_t **pok)
{
    if (glob->event.mouseWheelScroll.delta > 0) {
        for (int i = 0; i < 16; i++) {
            pok[i]->pos.y += 100;
            sfSprite_setPosition(pok[i]->sprite, pok[i]->pos);
        }
    }
    if (pok[0]->pos.y > -75) {
        for (int i = 0; i < 16; i++) {
            pok[i]->pos.y -= 100;
            sfSprite_setPosition(pok[i]->sprite, pok[i]->pos);
        }
    }
}
