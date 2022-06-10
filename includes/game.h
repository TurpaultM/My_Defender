/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** game
*/

#pragma once
#include "pokemons.h"

void game(global_t *global, char *enemies);

void go_right(enemies_t **enemies, movements_t *movements, int i);

void go_top(enemies_t **enemies, movements_t *movements, int i);

void go_down(enemies_t **enemies, movements_t *movements, int i);

void move_pokemons_each_second(pokemons_t *pokemons, char **patterns);

void animate_pokemons(pokemons_t *pokemons, sfRenderWindow *window);

void press_butt(global_t *glob, pokemons_t *pok);

void handle_defenders(pokemons_t *pokemons, global_t *glob);

char **define_patterns(void);

void check_end_of_game(pokemons_t *pokemons, global_t *global);

void display_sprites(global_t *glob, sfSprite *map,
pokemons_t *pokemons);

void print_menu(sfRenderWindow *window, validation_t *val, bool pause);

pokemons_t *create_pokemons_structure(char *enemies, sfSprite *coin);

void init_valid(validation_t *val);

void check_if_defenders_detect_enemies(pokemons_t *pokemons, int i);

void umbreon_attack(defenders_t *defender, sfVector2f pos, enemies_t *enemy);

void kabuto_attack(defenders_t *defender, sfVector2f pos,
sfVector2f position, enemies_t *enemy);

void gyarados_attack(defenders_t *defender, sfVector2f pos,
sfVector2f position, enemies_t *enemy);

void numel_attack(defenders_t *defender, sfVector2f pos,
sfVector2f position, pokemons_t *pokemons);

float calculate_to_rotate(float x, float y);

float deg(float rad);

bool is_an_evolved(int i);

void create_sprites_and_textures_defenders(defenders_t **defenders, int i);

void create_pokemons(pokemons_t *creation_of_pokemons, pokemons_t *pokemons,
sfSprite *coin);

void choose_pokemons(pokemons_t *creation_of_pokemons,
pokemons_t *pokemons, char *which_one);

void initialize_pokemons(enemies_t **enemies, defenders_t **defenders,
sfSprite *coin);

void initialize_defenders(defenders_t **defenders, sfIntRect rect,
sfSprite *coin);

defenders_t *defcpy(defenders_t *old_struct);

void create_new_struct_texture(defenders_t *new_struct,
defenders_t *old_struct);

void check_squares(pokemons_t *pokemons, sfVector2i position, global_t *glob);

enemies_t *my_structcpy(enemies_t *old_struct, int i);

void create_coins_structure(global_t *glob);

void display_coins(sfRenderWindow *window, coins_t *coins);

char *put_in_str(int nb, char *str);

char *my_str_char_cat(char *str, char c);

void display_total_life(sfRenderWindow *window, pokemons_t *pokemons,
sfFont *font);

void init_jiggly(global_t *glob);

void check_evolution(pokemons_t *pokemons, global_t *glob);

void put_defender_in_square(pokemons_t *pokemons, int i, global_t *glob,
int which_one);

void destroy_defender(defenders_t* defender);

void leave_button_for_win_and_lose(pokemons_t *pok, global_t *glob);

void check_end_condition(pokemons_t *pokemons, global_t *glob);

bool all_pokemons_are_destroyed(pokemons_t *pokemons);

void init_end_condition(global_t *glob);

int find_which_one(pokemons_t *pokemons, int i);

char *button_way_menu(int i);

void shiny(int def_or_ennemi, int i, sfSprite *sprite);

void is_shiny(defenders_t *old_struct, defenders_t *new_struct);

void random_shiny(enemies_t *enemy);

void check_if_pokemon_is_shiny(pokemons_t *pokemons, int i);

void destroy_enemy(enemies_t *enemy);

void destroy_all_pokemons(pokemons_t *pokemons);

void check_end_of_deplacement(pokemons_t *pokemons, char **patterns);

bool is_occuped(pokemons_t *pokemons, int i);

bool is_on_square(pokemons_t *pokemons, sfVector2i position, int i);

int change_old_def(int i, int def);