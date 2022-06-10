/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** struct_copy
*/

#include "game.h"

enemies_t *my_structcpy(enemies_t *old_struct, int i)
{
    enemies_t *new_struct = malloc(sizeof(enemies_t));
    new_struct->coins = old_struct->coins;
    new_struct->damages = old_struct->damages;
    new_struct->hp = old_struct->hp;
    new_struct->is_on_map = old_struct->is_on_map;
    new_struct->name = old_struct->name;
    new_struct->position = old_struct->position;
    new_struct->rect = old_struct->rect;
    new_struct->speed = old_struct->speed;
    new_struct->sprite = sfSprite_copy(old_struct->sprite);
    new_struct->texture = sfTexture_copy(old_struct->texture);
    new_struct->time_to_wait = old_struct->time_to_wait;
    new_struct->which_pokemon = i;
    new_struct->shiny = old_struct->shiny;
    return (new_struct);
}

void create_new_struct_clock(defenders_t* new_struct)
{
    new_struct->attack_clock = malloc(sizeof(my_clock_t));
    new_struct->attack_clock->clock = sfClock_create();
    new_struct->attack_clock->elapsedTime = 0;
    new_struct->is_restarting = false;
}

void create_textures_and_names(defenders_t *new_struct,
defenders_t *old_struct)
{
    new_struct->name = malloc(sizeof(char) * my_strlen(old_struct->name));
    new_struct->texture_name =
    malloc(sizeof(char) * my_strlen(old_struct->texture_name));
    new_struct->texture_mirror_name =
    malloc(sizeof(char) * my_strlen(old_struct->texture_mirror_name));
    if (old_struct->can_attack == true)
        new_struct->attack_texture_name =
        malloc(sizeof(char) * my_strlen(old_struct->attack_texture_name));
    new_struct->name = my_strdup(old_struct->name);
    new_struct->texture_name = my_strdup(old_struct->texture_name);
    new_struct->texture_mirror_name =
    my_strdup(old_struct->texture_mirror_name);
}

void create_new_struct_evolve_button(defenders_t *new_struct)
{
    new_struct->evolve_button = sfSprite_create();
    new_struct->texture_evolve_button =
    sfTexture_createFromFile("image/evolution.png", NULL);
    sfSprite_setTexture(new_struct->evolve_button,
    new_struct->texture_evolve_button, sfFalse);
    sfVector2f position = new_struct->initial_pos;
    position.x += 100;
    position.y += 10;
    sfSprite_setPosition(new_struct->evolve_button, position);
}

defenders_t *defcpy(defenders_t *old_struct)
{
    defenders_t *new_struct = malloc(sizeof(defenders_t));
    create_textures_and_names(new_struct, old_struct);
    new_struct->cost = old_struct->cost;
    new_struct->damages = old_struct->damages;
    new_struct->range = old_struct->range;
    new_struct->attack_speed = old_struct->attack_speed;
    new_struct->position = old_struct->position;
    new_struct->initial_pos = sfSprite_getPosition(old_struct->sprite);
    new_struct->square = sfRectangleShape_copy(old_struct->square);
    new_struct->rect = old_struct->rect;
    new_struct->which_square = old_struct->which_square;
    old_struct->which_square = -1;
    create_new_struct_texture(new_struct, old_struct);
    create_new_struct_clock(new_struct);
    if (my_strcmp("majikarp", old_struct->name) == 0 ||
    my_strcmp("numel", old_struct->name) == 0 ||
    my_strcmp("kabuto", old_struct->name) == 0)
        create_new_struct_evolve_button(new_struct);
    return (new_struct);
}
