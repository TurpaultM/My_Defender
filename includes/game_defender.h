/*
** EPITECH PROJECT, 2021
** defender
** File description:
** game
*/

#pragma once
#include "my.h"
#include "game.h"
typedef struct button_s {
    sfSprite *button_sprite;
    sfTexture *button_texture;
    sfVector2f pos;
    sfVector2f size;
} button_t;

typedef struct poke_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
} poke_t;
button_t **init_butt(button_t **button);
void button_clic(global_t *glob);
void jigglypuff_movement(rdd_t *jigglypuff);
void jigglypuff_movement_down(rdd_t *jigglypuff);
void jigglypuff_movement_up(rdd_t *jigglypuff);
void how_to_play(global_t *glob);
void init_pok(poke_t **pok, global_t *glob);
void jigglypuff_movement_rigth(rdd_t *jigglypuff);
void jigglypuff_movement_left(rdd_t *jigglypuff);
void jiggly_collide(global_t *glob, rdd_t *jigg);
bool which_poke(global_t *glob, int i);
void anim_jiggly_rigth(rdd_t *jiggly);
void anim_jiggly_left(rdd_t *jiggly);
void anim_jiggly_down(rdd_t *jiggly);
void anim_jiggly_up(rdd_t *jiggly);
void scroll_down(global_t *glob, poke_t **pok);
void scroll_up(global_t *glob, poke_t **pok);
void pokedex(global_t*);
void init_end_condition(global_t *glob);
bool all_pokemons_are_destroyed(pokemons_t *pokemons);