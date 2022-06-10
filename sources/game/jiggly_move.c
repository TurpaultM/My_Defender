/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"

void jigglypuff_movement_left(rdd_t *jiggly)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        jiggly->time = sfClock_getElapsedTime(jiggly->left);
        jiggly->sec = jiggly->time.microseconds / 22000;
        if (jiggly->sec > 1) {
            jiggly->movement.x -= 5.3;
            sfSprite_setPosition(jiggly->Jigglypuff_s, jiggly->movement);
            sfClock_restart(jiggly->left);
        }
        jiggly->time = sfClock_getElapsedTime(jiggly->left_anim);
        jiggly->sec_anim = jiggly->time.microseconds / 60000;
        if (jiggly->sec_anim > 1) {
            anim_jiggly_left(jiggly);
            sfClock_restart(jiggly->left_anim);
        }
    }
}

void jigglypuff_movement_rigth(rdd_t *jiggly)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        jiggly->time = sfClock_getElapsedTime(jiggly->rigth);
        jiggly->sec = jiggly->time.microseconds / 22000;
        if (jiggly->sec > 1) {
            jiggly->movement.x += 5.3;
            sfSprite_setPosition(jiggly->Jigglypuff_s, jiggly->movement);
            sfClock_restart(jiggly->rigth);
        }
        jiggly->time = sfClock_getElapsedTime(jiggly->rigth_anim);
        jiggly->sec_anim = jiggly->time.microseconds / 60000;
        if (jiggly->sec_anim > 1) {
            anim_jiggly_rigth(jiggly);
            sfClock_restart(jiggly->rigth_anim);
        }
    }
}

void jigglypuff_movement_up(rdd_t *jiggly)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        jiggly->time = sfClock_getElapsedTime(jiggly->up);
        jiggly->sec = jiggly->time.microseconds / 22000;
        if (jiggly->sec > 1) {
            jiggly->movement.y -= 5.3;
            sfSprite_setPosition(jiggly->Jigglypuff_s, jiggly->movement);
            sfClock_restart(jiggly->up);
        }
        jiggly->time = sfClock_getElapsedTime(jiggly->up_anim);
        jiggly->sec_anim = jiggly->time.microseconds / 60000;
        if (jiggly->sec_anim > 1) {
            anim_jiggly_up(jiggly);
            sfClock_restart(jiggly->up_anim);
        }
    }
}

void jigglypuff_movement_down(rdd_t *jiggly)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        jiggly->time = sfClock_getElapsedTime(jiggly->down);
        jiggly->sec = jiggly->time.microseconds / 22000;
        if (jiggly->sec > 1) {
            jiggly->movement.y += 5.3;
            sfSprite_setPosition(jiggly->Jigglypuff_s, jiggly->movement);
            sfClock_restart(jiggly->down);
        }
        jiggly->time = sfClock_getElapsedTime(jiggly->down_anim);
        jiggly->sec_anim = jiggly->time.microseconds / 60000;
        if (jiggly->sec_anim > 1) {
            anim_jiggly_down(jiggly);
            sfClock_restart(jiggly->down_anim);
        }
    }
}

void jigglypuff_movement(rdd_t *jiggly)
{
    jigglypuff_movement_down(jiggly);
    jigglypuff_movement_up(jiggly);
    jigglypuff_movement_left(jiggly);
    jigglypuff_movement_rigth(jiggly);
    if (jiggly->movement.x < (-41))
        jiggly->movement.x = 1922;
    if (jiggly->movement.x > (1930))
        jiggly->movement.x = -40;
    if (jiggly->movement.y < (-41))
        jiggly->movement.y = 1080;
    if (jiggly->movement.y > (1081))
        jiggly->movement.y = -40;
}
