/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** attacks
*/

#include "game.h"

void umbreon_attack(defenders_t *defender, sfVector2f pos, enemies_t *enemy)
{
    sfVector2f to_move;
    sfVector2f position = sfSprite_getPosition(defender->attack_sprite);
    to_move.x = (((pos.x + 35) - position.x) / 3);
    to_move.y = (((pos.y + 35) - position.y) / 3);
    sfSprite_move(defender->attack_sprite, to_move);
    position = sfSprite_getPosition(defender->attack_sprite);
    pos.x += 35;
    pos.y += 35;
    if (position.x >= pos.x - enemy->speed * 2 &&
    position.x <= pos.x + enemy->speed * 2 &&
    position.y >= pos.y - enemy->speed * 2 &&
    position.y <= pos.y + enemy->speed * 2) {
        enemy->hp -= defender->damages;
        sfSprite_setPosition(defender->attack_sprite,
        defender->initial_attack_pos);
        defender->is_restarting = true;
    } else
        defender->is_restarting = false;
}

void kabuto_attack(defenders_t *defender, sfVector2f pos,
sfVector2f position, enemies_t *enemy)
{
    sfVector2f to_move;
    if (position.x != defender->initial_pos.x &&
    position.y != defender->initial_pos.y) {
        enemy->hp -= defender->damages;
        sfSprite_setPosition(defender->sprite, defender->initial_pos);
        defender->is_restarting = true;
    } else {
        to_move.x = (pos.x - position.x) / 5;
        to_move.y = (pos.y - position.y) / 5;
        sfSprite_move(defender->sprite, to_move);
        defender->is_restarting = false;
    }
}

void gyarados_attack(defenders_t *defender, sfVector2f pos,
sfVector2f position, enemies_t *enemy)
{
    float to_rotate;
    float x;
    float y;
    x = ((pos.x + 35) - position.x);
    y = ((pos.y + 35) - position.y);
    to_rotate = calculate_to_rotate(x, y);
    sfSprite_setRotation(defender->attack_sprite, to_rotate);
    if (defender->make_damages == 20) {
        enemy->hp -= defender->damages;
        defender->make_damages = 0;
    } else
        defender->make_damages++;
}
