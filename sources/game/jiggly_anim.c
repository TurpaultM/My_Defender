/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"

void anim_jiggly_up(rdd_t *jiggly)
{
    jiggly->anim.top = 101.5;
    jiggly->anim.left += 32;
    if (jiggly->anim.left > 64) {
        jiggly->anim.left = 0;
    }
}

void anim_jiggly_down(rdd_t *jiggly)
{
    jiggly->anim.top = 7;
    jiggly->anim.left += 32;
    if (jiggly->anim.left > 64) {
        jiggly->anim.left = 0;
    }
}

void anim_jiggly_left(rdd_t *jiggly)
{
    jiggly->anim.top = 38.5;
    jiggly->anim.left += 32;
    if (jiggly->anim.left > 64) {
        jiggly->anim.left = 0;
    }
}

void anim_jiggly_rigth(rdd_t *jiggly)
{
    jiggly->anim.top = 70;
    jiggly->anim.left += 32;
    if (jiggly->anim.left > 64) {
        jiggly->anim.left = 0;
    }
}
