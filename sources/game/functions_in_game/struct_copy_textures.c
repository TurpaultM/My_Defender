/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** struct_copy_textures
*/

#include "game.h"

void create_rangecircle(defenders_t *defender)
{
    defender->rangecircle = sfCircleShape_create();
    sfVector2f position = sfSprite_getPosition(defender->sprite);
    if (my_strcmp(defender->name, "gyarados") == 0) {
        position.x -= defender->range - 55;
        position.y -= defender->range - 55;
    } else {
        position.x -= defender->range - 40;
        position.y -= defender->range - 40;
    }
    sfCircleShape_setPosition(defender->rangecircle, position);
    sfCircleShape_setRadius(defender->rangecircle, defender->range);
    sfCircleShape_setOutlineColor(defender->rangecircle, sfWhite);
    sfCircleShape_setFillColor(defender->rangecircle, sfTransparent);
    sfCircleShape_setOutlineThickness(defender->rangecircle, 1);
}

sfVector2f create_textures(int square, defenders_t *new_struct,
defenders_t *old_struct, sfVector2f attack_position)
{
    if (square == 1 || square == 3 || square == 6 || square == 7 ||
    square == 10 || square == 12 || square == 15) {
        new_struct->texture =
        sfTexture_createFromFile(new_struct->texture_mirror_name, NULL);
        attack_position.x += 80;
        attack_position.y += 20;
        if (my_strcmp(old_struct->name, "gyarados") == 0)
            attack_position.y += 50;
    } else {
        new_struct->texture =
        sfTexture_createFromFile(new_struct->texture_name, NULL);
        attack_position.x -= 10;
        attack_position.y += 20;
        if (my_strcmp(old_struct->name, "gyarados") == 0) {
            attack_position.x += 40;
            attack_position.y += 50;
        }
    }
    return (attack_position);
}

void can_attack(defenders_t *new_struct,
defenders_t *old_struct, sfVector2f attack_position)
{
    new_struct->attack_sprite = sfSprite_create();
    new_struct->attack_texture =
    sfTexture_createFromFile(old_struct->attack_texture_name, NULL);
    sfSprite_setTexture(new_struct->attack_sprite,
    new_struct->attack_texture, sfFalse);
    sfSprite_setPosition(new_struct->attack_sprite, attack_position);
    if (my_strcmp(old_struct->name, "gyarados") == 0)
        sfSprite_setOrigin(new_struct->attack_sprite,
        (sfVector2f){30, 40});
    new_struct->make_damages = 0;
    new_struct->initial_attack_pos = attack_position;
    new_struct->rotation = 0;
    new_struct->had_reached_max = false;
}

void create_new_struct_texture(defenders_t *new_struct,
defenders_t *old_struct)
{
    int square = new_struct->which_square;
    sfVector2f position = sfSprite_getPosition(old_struct->sprite);
    sfVector2f attack_position = sfSprite_getPosition(old_struct->sprite);
    attack_position =
    create_textures(square, new_struct, old_struct, attack_position);
    new_struct->sprite = sfSprite_create();
    new_struct->attack_sprite = sfSprite_create();
    sfSprite_setTexture(new_struct->sprite, new_struct->texture, sfFalse);
    sfSprite_setTextureRect(new_struct->sprite, new_struct->rect);
    sfSprite_setPosition(new_struct->sprite, position);
    sfSprite_setPosition(old_struct->sprite, old_struct->initial_pos);
    new_struct->target = -1;
    new_struct->change_target = 0;
    new_struct->is_attacking = false;
    if (old_struct->can_attack == true) {
        can_attack(new_struct, old_struct, attack_position);
    }
    create_rangecircle(new_struct);
}
