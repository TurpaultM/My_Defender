/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** numel_attack
*/

#include "game.h"

void zone_damages(pokemons_t *pokemons, defenders_t *defender)
{
    sfVector2f pokemon_pos = {0, 0};
    sfVector2f pos =
    sfSprite_getPosition(pokemons->enemies[defender->target]->sprite);
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (pokemons->enemies[i]->is_on_map == true) {
            pokemon_pos = sfSprite_getPosition(pokemons->enemies[i]->sprite);
        }
        if (pos.x - 100 <= pokemon_pos.x && pos.x + 100 >= pokemon_pos.x &&
        pos.y - 100 <= pokemon_pos.y && pos.y + 100 >= pokemon_pos.y) {
            pokemons->enemies[i]->hp -= defender->damages;
        }
    }
}

void numel_fireball_fall(sfVector2f pos, sfVector2f attack_pos,
pokemons_t *pokemons, defenders_t *defender)
{
    sfVector2f to_move;
    if (defender->had_reached_max == true) {
        to_move.x = (pos.x - attack_pos.x) / 5;
        to_move.y = (pos.y - attack_pos.y) / 5;
        sfSprite_move(defender->attack_sprite, to_move);
    }
    if (attack_pos.x >= pos.x - 30 && attack_pos.x <= pos.x + 30 &&
    attack_pos.y >= pos.y - 30 && attack_pos.y <= pos.y + 30 &&
    defender->had_reached_max == true) {
        zone_damages(pokemons, defender);
        defender->had_reached_max = false;
        sfSprite_setPosition(defender->attack_sprite,
        defender->initial_attack_pos);
        defender->is_restarting = true;
    } else
        defender->is_restarting = false;
}

void numel_attack(defenders_t *defender, sfVector2f pos,
sfVector2f position, pokemons_t *pokemons)
{
    sfVector2f pos_max;
    sfVector2f to_move;
    pos_max.x = (position.x + pos.x) / 2;
    int calc_y = pos.y - position.y;
    if (calc_y < 0)
        calc_y = -calc_y;
    pos_max.y = position.y - ((calc_y) * 2) - 300;
    sfVector2f attack_pos = sfSprite_getPosition(defender->attack_sprite);
    if (attack_pos.y > pos_max.y && defender->had_reached_max == false) {
        to_move.x = (pos_max.x - attack_pos.x) / 40;
        to_move.y = -30;
        sfSprite_move(defender->attack_sprite, to_move);
    } else {
        defender->had_reached_max = true;
    }
    numel_fireball_fall(pos, attack_pos, pokemons, defender);
}
