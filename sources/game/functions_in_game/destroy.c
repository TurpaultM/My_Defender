/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** destroy_defenders
*/

#include "game.h"

void destroy_defender(defenders_t* defender)
{
    free(defender->name);
    free(defender->texture_name);
    free(defender->texture_mirror_name);
    sfRectangleShape_destroy(defender->square);
    sfTexture_destroy(defender->texture);
    sfSprite_destroy(defender->sprite);
    if (defender->which_square != -1) {
        sfSprite_destroy(defender->attack_sprite);
        sfCircleShape_destroy(defender->rangecircle);
        sfClock_destroy(defender->attack_clock->clock);
        free(defender->attack_clock);
    }
}

void destroy_enemy(enemies_t *enemy)
{
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
}

void destroy_movements(pokemons_t *pokemons)
{
    free(pokemons->movements->pos_pattern);
    free(pokemons->movements->direction);
    free(pokemons->movements->movements);
    free(pokemons->movements->travelled_distance);
    free(pokemons->movements);
}

void destroy_pokemons_variables(pokemons_t *pokemons)
{
    sfClock_destroy(pokemons->time->clock);
    sfClock_destroy(pokemons->time->clock_animations);
    free(pokemons->time);
    sfText_destroy(pokemons->text_total_life);
    sfSprite_destroy(pokemons->heart);
    sfTexture_destroy(pokemons->texture_heart);
}

void destroy_all_pokemons(pokemons_t *pokemons)
{
    for (int i = 0; i < 7; i++) {
        destroy_defender(pokemons->defenders[i]);
    }
    for (int i = 0; i < pokemons->nb_of_defenders; i++)
        destroy_defender(pokemons->placed_defenders[i]);
    for (int i = 0; i < pokemons->nb_total; i++) {
        if (pokemons->enemies[i]->is_on_map == true)
            destroy_enemy(pokemons->enemies[i]);
    }
    destroy_movements(pokemons);
}