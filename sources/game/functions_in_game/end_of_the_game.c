/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** end_of_the_game
*/

#include "game.h"

bool all_pokemons_are_destroyed(pokemons_t *pokemons)
{
    if (pokemons->nb_of_pokemons < pokemons->nb_total - 2)
        return (false);
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (pokemons->enemies[i]->is_on_map == true)
            return (false);
    }
    return (true);
}

void check_if_pokemon_is_on_map(pokemons_t *pokemons, int i, global_t *global)
{
    if (pokemons->enemies[i]->is_on_map == true) {
        global->coins->nb_of_coins += pokemons->enemies[i]->coins;
        pokemons->enemies[i]->is_on_map = false;
        destroy_enemy(pokemons->enemies[i]);
    }
}

void check_pokemons_hp(pokemons_t *pokemons, global_t *global)
{
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (pokemons->enemies[i]->hp <= 0) {
            check_if_pokemon_is_on_map(pokemons, i, global);
        }
    }
}

void check_end_of_game(pokemons_t *pokemons, global_t *global)
{
    check_pokemons_hp(pokemons, global);

    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (pokemons->enemies[i]->is_on_map == true &&
        sfSprite_getPosition(pokemons->enemies[i]->sprite).x > 1920) {
            pokemons->total_life -= pokemons->enemies[i]->damages;
            destroy_enemy(pokemons->enemies[i]);
            pokemons->enemies[i]->is_on_map = false;
        }
    }
}
