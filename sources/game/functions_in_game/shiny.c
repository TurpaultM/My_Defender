/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** shiny
*/

#include "game.h"

void random_shiny(enemies_t *enemy)
{
    int random = rand() % 100;
    if (random == 0) {
        enemy->shiny = true;
    }
}

void check_if_pokemon_is_shiny(pokemons_t *pokemons, int i)
{
    if (pokemons->enemies[i]->shiny == false) {
        shiny(7, pokemons->enemies[i]->which_pokemon,
        pokemons->enemies[i]->sprite);
    }
}

void shiny(int def_or_ennemi, int i, sfSprite *sprite)
{
    sfColor *colors = malloc(sizeof(sfColor) * 16);
    colors[0] = sfColor_fromRGB((sfInt8)102, (sfInt8)178, (sfInt8)255);
    colors[1] = sfColor_fromRGB((sfInt8)204, (sfInt8)204, (sfInt8)0);
    colors[2] = sfColor_fromRGB((sfInt8)255, (sfInt8)102, (sfInt8)102);
    colors[3] = sfColor_fromRGB((sfInt8)102, (sfInt8)255, (sfInt8)255);
    colors[4] = sfColor_fromRGB((sfInt8)153, (sfInt8)153, (sfInt8)255);
    colors[5] = sfColor_fromRGB((sfInt8)51, (sfInt8)255, (sfInt8)51);
    colors[6] = sfColor_fromRGB((sfInt8)51, (sfInt8)255, (sfInt8)51);
    colors[7] = sfColor_fromRGB((sfInt8)255, (sfInt8)153, (sfInt8)51);
    colors[8] = sfColor_fromRGB((sfInt8)255, (sfInt8)153, (sfInt8)51);
    colors[9] = sfColor_fromRGB((sfInt8)102, (sfInt8)255, (sfInt8)102);
    colors[10] = sfColor_fromRGB((sfInt8)255, (sfInt8)255, (sfInt8)0);
    colors[11] = sfColor_fromRGB((sfInt8)102, (sfInt8)255, (sfInt8)255);
    colors[12] = sfColor_fromRGB((sfInt8)102, (sfInt8)255, (sfInt8)255);
    colors[13] = sfColor_fromRGB((sfInt8)255, (sfInt8)153, (sfInt8)51);
    colors[14] = sfColor_fromRGB((sfInt8)153, (sfInt8)255, (sfInt8)255);
    colors[15] = sfColor_fromRGB((sfInt8)204, (sfInt8)153, (sfInt8)255);
    sfSprite_setColor(sprite, colors[i + def_or_ennemi]);
}