/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** display
*/

#include "game.h"

void display_evolve_button(global_t *glob, pokemons_t *pokemons, int i)
{
    sfVector2f position =
    sfSprite_getPosition(pokemons->placed_defenders[i]->evolve_button);
    char *string = malloc(sizeof(char) * 3);
    int which_one = find_which_one(pokemons, i);
    string = inttochar(pokemons->defenders[which_one]->cost);
    sfText *text = sfText_create();
    sfText_setFont(text, glob->coins->font);
    sfText_setString(text, string);
    sfText_setColor(text, sfYellow);
    sfText_setPosition(text, position);
    sfRenderWindow_drawSprite(glob->window,
    pokemons->placed_defenders[i]->evolve_button, NULL);
    sfRenderWindow_drawText(glob->window, text, NULL);
}

void display_defenders(pokemons_t *pokemons, global_t *glob)
{
    for (int i = 0; i < pokemons->nb_of_defenders; i++) {
        sfRenderWindow_drawSprite(glob->window,
        pokemons->placed_defenders[i]->sprite, NULL);
        if (my_strcmp("majikarp", pokemons->placed_defenders[i]->name) == 0 ||
        my_strcmp("numel", pokemons->placed_defenders[i]->name) == 0 ||
        my_strcmp("kabuto", pokemons->placed_defenders[i]->name) == 0) {
            display_evolve_button(glob, pokemons, i);
        }
        if (pokemons->display_circles == true)
            sfRenderWindow_drawCircleShape(glob->window,
            pokemons->placed_defenders[i]->rangecircle, NULL);
        if (pokemons->placed_defenders[i]->is_attacking == true) {
            sfRenderWindow_drawSprite(glob->window,
            pokemons->placed_defenders[i]->attack_sprite, NULL);
        }
    }
}

void display_defenders_and_enemies(pokemons_t *pokemons,
global_t *glob)
{
    display_defenders(pokemons, glob);
    for (int i = 0; i < pokemons->nb_of_pokemons &&
    pokemons->nb_of_pokemons != 1; i++) {
        if (pokemons->enemies[i]->is_on_map == true) {
            check_if_pokemon_is_shiny(pokemons, i);
            sfRenderWindow_drawSprite(glob->window,
            pokemons->enemies[i]->sprite, NULL);
        }
    }
}

void draw_enemy_zero(global_t *glob, pokemons_t *pokemons)
{
    if (pokemons->enemies[0]->is_on_map == true) {
        check_if_pokemon_is_shiny(pokemons, 0);
        sfRenderWindow_drawSprite(glob->window,
        pokemons->enemies[0]->sprite, NULL);
    }
}

void display_sprites(global_t *glob, sfSprite *map,
pokemons_t *pokemons)
{
    sfRenderWindow_drawSprite(glob->window, map, NULL);
    display_total_life(glob->window, pokemons, glob->coins->font);
    sfRenderWindow_drawSprite(glob->window, glob->coins->sprite, NULL);
    draw_enemy_zero(glob, pokemons);
    for (int i = 0; i < 16; i++) {
        sfRenderWindow_drawRectangleShape(glob->window,
        pokemons->defenders[i]->square, NULL);
        if (i < 7 && is_an_evolved(i) == false) {
            sfRenderWindow_drawSprite(glob->window,
            pokemons->defenders[i]->sprite, NULL);
            sfRenderWindow_drawText(glob->window,
            pokemons->defenders[i]->text_coins, NULL);
            sfRenderWindow_drawSprite(glob->window,
            pokemons->defenders[i]->coins, NULL);
        }
    }
    display_defenders_and_enemies(pokemons, glob);
    display_coins(glob->window, glob->coins);
}
