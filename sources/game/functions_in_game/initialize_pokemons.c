/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** initialize_pokemons
*/

#include "game.h"

bool is_an_evolved(int i)
{
    if (i == 2 || i == 4 || i == 6 || i == 8)
        return (true);
    return (false);
}

void create_sprites_pokemons(enemies_t **enemies,
int i, sfIntRect rect)
{
    char *textures[9] = {"image/pokemons/combee.png",
    "image/pokemons/vespiquen.png", "image/pokemons/ekans.png",
    "image/pokemons/arbok.png", "image/pokemons/litwich.png",
    "image/pokemons/lampent.png", "image/pokemons/chandelure.png",
    "image/pokemons/yamask.png", "image/pokemons/cofagrigus.png"};
    enemies[i]->sprite = sfSprite_create();
    enemies[i]->texture = sfTexture_createFromFile(textures[i], NULL);
    enemies[i]->rect = rect;
    sfSprite_setTexture(enemies[i]->sprite, enemies[i]->texture, sfFalse);
    sfSprite_setTextureRect(enemies[i]->sprite, enemies[i]->rect);
    sfSprite_setPosition(enemies[i]->sprite, enemies[i]->position);
    enemies[i]->shiny = false;
}

void initialize_pokemons(enemies_t **enemies, defenders_t **defenders,
sfSprite *coin)
{
    char *names[9] = {"combee", "vespiquen", "ekans", "arbok",
    "litwich", "lampent", "chandelure", "yamask", "cofagrigus"};
    char *coins[9] = {"5", "9", "7", "8", "5", "7", "8", "6", "11"};
    char *damages[9] = {"1", "5", "2", "5", "2", "5", "8", "5", "10"};
    char *speed[9] = {"8", "7", "5", "6", "5", "6", "6", "2", "3"};
    char *hp[9] = {"350", "1200", "500", "1000",
    "450", "900", "1400", "700", "2500"};
    for (int i = 0; i < 9; i++) {
        enemies[i]->name = names[i];
        enemies[i]->coins = my_getnbr(coins[i]);
        enemies[i]->damages = my_getnbr(damages[i]);
        enemies[i]->hp = my_getnbr(hp[i]);
        enemies[i]->position.x = 200;
        enemies[i]->position.y = 450;
        enemies[i]->speed = my_getnbr(speed[i]);
        enemies[i]->is_on_map = true;
        enemies[i]->time_to_wait = 10;
        create_sprites_pokemons(enemies, i, (sfIntRect){0, 0, 100, 80});
    }
    initialize_defenders(defenders, (sfIntRect){0, 0, 100, 80}, coin);
}