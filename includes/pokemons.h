/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** pokemons
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "my.h"
#include <stdbool.h>
#include <math.h>

typedef struct time_s {
    sfClock *clock;
    sfClock *clock_animations;
    int elapsedTime;
    int elapsedTime_animations;
    int total_time;
    bool pause;
} my_clock_t;

typedef struct enemies_s {
    sfTexture *texture;
    sfSprite *sprite;
    int coins;
    int damages;
    int speed;
    int hp;
    sfVector2f position;
    sfIntRect rect;
    bool is_on_map;
    char *name;
    int time_to_wait;
    bool shiny;
    int which_pokemon;
}enemies_t;

typedef struct defenders_s {
    char *name;
    char *texture_name;
    char *texture_mirror_name;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    int cost;
    int damages;
    int range;
    int attack_speed;
    sfVector2f position;
    sfVector2f square_pos;
    sfVector2f initial_pos;
    sfRectangleShape *square;
    sfCircleShape *rangecircle;
    int which_square;
    int old_def;
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
    sfSprite *attack_sprite;
    sfTexture *attack_texture;
    bool is_attacking;
    bool can_attack;
    char *attack_texture_name;
    int target;
    int change_target;
    sfVector2f initial_attack_pos;
    my_clock_t *attack_clock;
    bool is_restarting;
    int rotation;
    int make_damages;
    bool had_reached_max;
    char *string_coins;
    sfText *text_coins;
    sfSprite *coins;
    sfSprite *evolve_button;
    sfTexture *texture_evolve_button;
}defenders_t;

typedef struct movements_s {
    sfVector2f *pos;
    int *pos_pattern;
    int *movements;
    char *direction;
    int *travelled_distance;
    int anim_pattern[6];
    int pos_in_anim;
} movements_t;

typedef struct validation_s {
    sfSprite *sprite;
    sfSprite *pause_sprt;
    sfTexture *texture;
    sfTexture *pause_txtr;
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *rectangle_yes;
    sfRectangleShape *rectangle_no;
    sfText *text;
    char *text_string;
} validation_t;

typedef struct pokemons_s {
    enemies_t **enemies;
    defenders_t **defenders;
    defenders_t **placed_defenders;
    movements_t *movements;
    validation_t validation;
    int nb_of_pokemons;
    int nb_of_defenders;
    int nb_total;
    bool display_circles;
    my_clock_t *time;
    bool placing_pokemon;
    int total_life;
    sfText *text_total_life;
    sfSprite *heart;
    sfTexture *texture_heart;
    int increase_coins;
} pokemons_t;