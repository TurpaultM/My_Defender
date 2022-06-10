/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** create_pokemons
*/

#include "game.h"

void create_time_structure(pokemons_t *pokemons)
{
    pokemons->time = malloc(sizeof(my_clock_t));
    pokemons->time->clock = sfClock_create();
    pokemons->time->clock_animations = sfClock_create();
    pokemons->time->elapsedTime = 0;
    pokemons->time->elapsedTime_animations = 0;
    pokemons->time->total_time = 0;
    pokemons->time->pause = false;
}

void create_movements_structure(pokemons_t *pokemons)
{
    pokemons->movements = malloc(sizeof(movements_t));
    pokemons->movements->anim_pattern[0] = 0;
    pokemons->movements->anim_pattern[1] = 100;
    pokemons->movements->anim_pattern[2] = 200;
    pokemons->movements->anim_pattern[3] = 300;
    pokemons->movements->anim_pattern[4] = 200;
    pokemons->movements->anim_pattern[5] = 100;
    pokemons->movements->pos_in_anim = 0;
    pokemons->movements->pos_pattern = malloc(sizeof(int) * 379);
    pokemons->movements->direction = malloc(sizeof(char) * 379);
    pokemons->movements->movements = malloc(sizeof(int) * 379);
    pokemons->movements->travelled_distance = malloc(sizeof(int) * 379);
    for (int i = 0; i < 379; i++) {
        pokemons->movements->pos_pattern[i] = 0;
        pokemons->movements->travelled_distance[i] = 0;
        pokemons->movements->movements[i] = 0;
    }
}

void create_heart(pokemons_t *pokemons)
{
    pokemons->heart = sfSprite_create();
    pokemons->texture_heart =
    sfTexture_createFromFile("image/heart.png", NULL);
    sfSprite_setTexture(pokemons->heart, pokemons->texture_heart, sfFalse);
    sfSprite_setPosition(pokemons->heart, (sfVector2f){1850, 490});
    sfSprite_setScale(pokemons->heart, (sfVector2f){0.1, 0.1});
}

pokemons_t *create_pokemons_structure(char *enemies, sfSprite *coin)
{
    pokemons_t* creation_of_pokemons = malloc(sizeof(pokemons_t));
    pokemons_t* pokemons = malloc(sizeof(pokemons_t));
    create_pokemons(creation_of_pokemons, pokemons, coin);
    choose_pokemons(creation_of_pokemons, pokemons, enemies);
    create_time_structure(pokemons);
    create_movements_structure(pokemons);
    create_heart(pokemons);
    return (pokemons);
}
