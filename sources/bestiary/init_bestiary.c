/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"

static char *hide(int i)
{
    switch (i) {
        case 8:
            return ("image/pokedex/cofargrigus_h.png");
        case 0:
            return ("image/pokedex/combee_h.png");
        case 1:
            return ("image/pokedex/vespiqueen_h.png");
        case 4:
            return ("image/pokedex/litwitch_h.png");
        case 5:
            return ("image/pokedex/lampent_h.png");
        case 6:
            return ("image/pokedex/chandelure_h.png");
        case 2:
            return ("image/pokedex/ekans_h.png");
        case 3:
            return ("image/pokedex/Arbok_h.png");
        default: return ("void");
    }
}

static char *appear(int i)
{
    switch (i) {
        case 8:
            return ("image/pokedex/cofargrigus.png");
        case 0:
            return ("image/pokedex/combee.png");
        case 1:
            return ("image/pokedex/vespiqueen.png");
        case 4:
            return ("image/pokedex/litwitch.png");
        case 5:
            return ("image/pokedex/lampent.png");
        case 6:
            return ("image/pokedex/chandelure.png");
        case 2:
            return ("image/pokedex/ekans.png");
        case 3:
            return ("image/pokedex/arbok.png");
        default: return ("void");
    }
}

static char *hide_or_not(int i, global_t *glob)
{
    if (which_poke(glob, i) == false) {
        if (i == 7)
            return ("image/pokedex/yamask_h.png");
        return (hide(i));
    } else {
        if (i == 7)
            return ("image/pokedex/yamask.png");
        return (appear(i));
    }

}

static char *set_txtr(int i, global_t *glob)
{
    switch (i) {
        case 9:
            return ("image/pokedex/majikarp.png");
        case 10:
            return ("image/pokedex/gyarados.png");
        case 11:
            return ("image/pokedex/numel.png");
        case 12:
            return ("image/pokedex/camerupth.png");
        case 13:
            return ("image/pokedex/umbreon.png");
        case 14:
            return ("image/pokedex/kabuto.png");
        case 15:
            return ("image/pokedex/kabutops.png");
        default:
            break;
    }
    return (hide_or_not(i, glob));
}

void init_pok(poke_t **pok, global_t *glob)
{
    int posy = -75;

    for (int i = 0; i < 16; i++) {
        pok[i] = malloc(sizeof(poke_t));
        pok[i]->sprite = sfSprite_create();
        pok[i]->texture = sfTexture_createFromFile(set_txtr(i, glob), NULL);
        sfSprite_setTexture(pok[i]->sprite, pok[i]->texture, sfTrue);
        pok[i]->pos.y = posy;
        pok[i]->pos.x = 200;
        sfSprite_setPosition(pok[i]->sprite, pok[i]->pos);
        posy += 300;
        pok[i]->size.x = 0.6;
        pok[i]->size.y = 0.6;
        sfSprite_setScale(pok[i]->sprite, pok[i]->size);
    }
}