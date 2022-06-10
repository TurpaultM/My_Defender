/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** create_defenders
*/

#include "game.h"

void initialize_initial_pos(defenders_t **defenders, int i)
{
    char *pos_x[7] = {"650", "850", "850", "1050", "1050", "1250", "1250"};
    char *pos_y[7] = {"870", "870", "930", "870", "930", "870", "930"};
    defenders[i]->initial_pos.x = my_getnbr(pos_x[i]);
    defenders[i]->initial_pos.y = my_getnbr(pos_y[i]);
}

void create_sounds(defenders_t **defenders, int i)
{
    char *soundbuffers[7] = {"music_sound/pokemons_sounds/umbreon.ogg",
    "music_sound/pokemons_sounds/majikarp.ogg",
    "music_sound/pokemons_sounds/gyarados.ogg",
    "music_sound/pokemons_sounds/numel.ogg",
    "music_sound/pokemons_sounds/camerupth.ogg",
    "music_sound/pokemons_sounds/kabuto.ogg",
    "music_sound/pokemons_sounds/kabutops.ogg"};
    defenders[i]->sound = sfSound_create();
    defenders[i]->soundbuffer = sfSoundBuffer_createFromFile(soundbuffers[i]);
    sfSound_setBuffer(defenders[i]->sound, defenders[i]->soundbuffer);
}

void create_coins_text(defenders_t *defender, sfFont *font, sfSprite *coin)
{
    sfVector2f position = defender->initial_pos;
    position.y += 80;
    defender->string_coins = NULL;
    defender->string_coins = malloc(sizeof(char) * 4);
    defender->string_coins[0] = '\0';
    put_in_str(defender->cost, defender->string_coins);
    defender->text_coins = sfText_create();
    sfText_setFont(defender->text_coins, font);
    sfText_setString(defender->text_coins, defender->string_coins);
    sfText_setPosition(defender->text_coins, position);
    sfText_setColor(defender->text_coins, sfYellow);
    defender->coins = sfSprite_copy(coin);
    position.x += 60;
    sfSprite_setScale(defender->coins, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(defender->coins, position);
}

void initialize_defenders(defenders_t **defenders,
sfIntRect rect, sfSprite *coin)
{
    char *def_names[7] = {"umbreon", "majikarp", "gyarados", "numel",
    "camerupth", "kabuto", "kabutops"};
    char *attack_speed[7] = {"6", "1", "7", "9", "7", "9", "9"};
    char *cost[7] = {"225", "100", "600", "2", "250", "120", "240"};
    char *def_damages[7] = {"270", "0", "550", "800", "800", "20", "50"};
    char *range[7] = {"170", "3000", "200", "700", "600", "120", "120"};
    sfFont *font = sfFont_createFromFile("Police/pokemon.ttf");
    for (int i = 0; i < 7; i++) {
        defenders[i]->name = my_strdup(def_names[i]);
        defenders[i]->attack_speed = my_getnbr(attack_speed[i]);
        defenders[i]->cost = my_getnbr(cost[i]);
        defenders[i]->damages = my_getnbr(def_damages[i]);
        defenders[i]->range = my_getnbr(range[i]);
        defenders[i]->rect = rect;
        defenders[i]->which_square = -1;
        initialize_initial_pos(defenders, i);
        create_sprites_and_textures_defenders(defenders, i);
        create_sounds(defenders, i);
        create_coins_text(defenders[i], font, coin);
    }
}
