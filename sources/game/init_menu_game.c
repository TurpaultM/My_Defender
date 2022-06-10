/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"

void init_jiggly_clock(rdd_t *jigglypuff)
{
    jigglypuff->up = sfClock_create();
    jigglypuff->down = sfClock_create();
    jigglypuff->left = sfClock_create();
    jigglypuff->rigth = sfClock_create();
    jigglypuff->up_anim = sfClock_create();
    jigglypuff->down_anim = sfClock_create();
    jigglypuff->left_anim = sfClock_create();
    jigglypuff->rigth_anim = sfClock_create();
}

void init_jiggly(global_t *glob)
{
    glob->rdd = malloc(sizeof(rdd_t));
    glob->rdd->Jigglypuff_s = sfSprite_create();
    glob->rdd->Jigglypuff_t =
    sfTexture_createFromFile("image/Rondoudou.png", NULL);
    sfSprite_setTexture(glob->rdd->Jigglypuff_s,
    glob->rdd->Jigglypuff_t, sfFalse);
    glob->rdd->movement.x = 1000;
    glob->rdd->movement.y = 540;
    glob->rdd->size.x = 1.5;
    glob->rdd->size.y = 1.5;
    glob->rdd->sec = 0;
    glob->rdd->sec_anim = 0;
    glob->rdd->anim.left = 0;
    glob->rdd->anim.top = 0;
    glob->rdd->anim.height = 30;
    glob->rdd->anim.width = 32;
    init_jiggly_clock(glob->rdd);
}

static char *button_way(int i)
{
    switch (i) {
        case 1:
            return ("image/map/pokedex.png");
        case 2:
            return ("image/map/option_but.png");
        case 3:
            return ("image/map/fleche.png");
        case 0:
            return ("image/map/how_play.png");
        default:
            break;
    }
    return ("void");
}

static void vector_set_pos(button_t **button, int i)
{
    static int posy = 610;
    static int posx = 1740;

    button[i]->size.x = 2;
    button[i]->size.y = 2;
    button[i]->pos.x = posx;
    button[i]->pos.y = posy;
    posy = posy + 100;
    sfSprite_setScale(button[i]->button_sprite, button[i]->size);
    sfSprite_setPosition(button[i]->button_sprite, button[i]->pos);
    if (i == 3)
        posy = 610;
}

button_t **init_butt(button_t **button)
{
    for (int i = 0; i < 4; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->button_sprite = sfSprite_create();
        button[i]->button_texture =
        sfTexture_createFromFile(button_way(i), NULL);
        sfSprite_setTexture(button[i]->button_sprite,
        button[i]->button_texture, sfFalse);
        vector_set_pos(button, i);
    }
    return (button);
}
