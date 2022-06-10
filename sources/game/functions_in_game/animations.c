/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** animations
*/

#include "game.h"

void animate_enemies(pokemons_t *pokemons, int i, sfRenderWindow *window)
{
    pokemons->enemies[i]->rect.left =
    pokemons->movements->anim_pattern[pokemons->movements->pos_in_anim];
    sfSprite_setTextureRect(pokemons->enemies[i]->sprite,
    pokemons->enemies[i]->rect);
    sfRenderWindow_drawSprite(window, pokemons->enemies[i]->sprite, NULL);

}

void animate_defenders(pokemons_t *pokemons, sfRenderWindow *window)
{
    for (int i = 0; i < pokemons->nb_of_defenders; i++) {
        pokemons->placed_defenders[i]->rect.left =
        pokemons->movements->anim_pattern[pokemons->movements->pos_in_anim];
        sfSprite_setTextureRect(pokemons->placed_defenders[i]->sprite,
        pokemons->placed_defenders[i]->rect);
        sfRenderWindow_drawSprite(window,
        pokemons->placed_defenders[i]->sprite, NULL);
    }
}

void animate_pokemons(pokemons_t *pokemons, sfRenderWindow *window)
{
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (pokemons->enemies[i]->is_on_map == true) {
            animate_enemies(pokemons, i, window);
        }
    }
    for (int i = 0; i < 7; i++) {
        pokemons->defenders[i]->rect.left =
        pokemons->movements->anim_pattern[pokemons->movements->pos_in_anim];
        sfSprite_setTextureRect(pokemons->defenders[i]->sprite,
        pokemons->defenders[i]->rect);
        if (is_an_evolved(i) == false)
            sfRenderWindow_drawSprite(window,
            pokemons->defenders[i]->sprite, NULL);
    }
    animate_defenders(pokemons, window);
    pokemons->movements->pos_in_anim++;
    if (pokemons->movements->pos_in_anim == 6)
        pokemons->movements->pos_in_anim = 0;
}