/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** detect_enemies
*/

#include "game.h"

void move_attack(defenders_t *defender, sfVector2f pos, enemies_t **enemies,
pokemons_t *pokemons)
{
    sfVector2f position = sfSprite_getPosition(defender->sprite);
    if (my_strcmp(defender->name, "umbreon") == 0) {
        umbreon_attack(defender, pos, enemies[defender->target]);
    } else if (my_strcmp(defender->name, "kabuto") == 0
    || my_strcmp(defender->name, "kabutops") == 0) {
        kabuto_attack(defender, pos, position, enemies[defender->target]);
    }
    if (my_strcmp(defender->name, "gyarados") == 0) {
        gyarados_attack(defender, pos, position, enemies[defender->target]);
    } else if (my_strcmp(defender->name, "numel") == 0
    || my_strcmp(defender->name, "camerupth") == 0) {
        numel_attack(defender, pos, position, pokemons);
    }
    if (my_strcmp(defender->name, "majikarp") == 0)
        pokemons->increase_coins++;
}

void enemy_is_on_map(pokemons_t *pokemons,
sfVector2f position, defenders_t *defender, int i)
{
    sfVector2f pos = sfSprite_getPosition(pokemons->enemies[i]->sprite);
    float cx = position.x + defender->range;
    float cy = position.y + defender->range;
    float dx = pos.x + 35;
    float dy = pos.y + 35;
    float cr = defender->range;
    float res = (cx - dx);
    if ((res * res + (cy - dy) * (cy - dy)) <= (cr + 5) * (cr + 5)
    && (defender->target == -1 || i == defender->target)) {
        defender->target = i;
        defender->is_attacking = true;
        move_attack(defender, pos, pokemons->enemies, pokemons);
    } else if (i == defender->target) {
        defender->change_target++;
        defender->change_target >= 5 ? defender->is_attacking = false,
        defender->target = -1, defender->change_target = 0 : 0;
    }
}

void check_defenders_range(pokemons_t *pokemons, defenders_t *defender)
{
    sfVector2f position = sfCircleShape_getPosition(defender->rangecircle);
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (defender->target == -1) {
            sfSprite_setPosition(defender->attack_sprite,
            defender->initial_attack_pos);
            defender->is_attacking = false;
            defender->had_reached_max = false;
        }
        if (pokemons->enemies[i]->is_on_map == true) {
            enemy_is_on_map(pokemons, position, defender, i);
        } else if (i == defender->target &&
        pokemons->enemies[i]->is_on_map == false) {
            defender->target = -1;
            defender->change_target = 0;
        }
    }
}

void substract_time(pokemons_t *pokemons, int i, int attack_seconds)
{
    if (pokemons->placed_defenders[i]->is_restarting == true) {
        if (my_strcmp("numel", pokemons->placed_defenders[i]->name) != 0 &&
        my_strcmp("camerupth", pokemons->placed_defenders[i]->name) != 0)
            pokemons->placed_defenders[i]->attack_clock->elapsedTime -=
            (attack_seconds * 5);
        else
            pokemons->placed_defenders[i]->attack_clock->elapsedTime -=
            (attack_seconds * 50);
    } else
        pokemons->placed_defenders[i]->attack_clock->elapsedTime -=
        attack_seconds;
}

void check_if_defenders_detect_enemies(pokemons_t *pokemons, int i)
{
    sfTime currElapsedTime =
    sfClock_restart(pokemons->placed_defenders[i]->attack_clock->clock);
    pokemons->placed_defenders[i]->attack_clock->elapsedTime +=
    currElapsedTime.microseconds;
    int attack_seconds =
    (10 - pokemons->placed_defenders[i]->attack_speed) * 10000;
    while (pokemons->placed_defenders[i]->attack_clock->elapsedTime >=
    attack_seconds) {
        check_defenders_range(pokemons, pokemons->placed_defenders[i]);
        substract_time(pokemons, i, attack_seconds);
    }
}
