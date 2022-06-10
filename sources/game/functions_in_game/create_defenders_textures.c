/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** create_defenders_textures
*/

#include "game.h"

char **create_def_mirror_textures(void)
{
    char **def_textures_mirror = malloc(sizeof(char *) * 7);
    for (int i = 0; i < 7; i++)
        def_textures_mirror[i] = malloc(sizeof(char) * 36);
    def_textures_mirror[0] = "image/pokemons/umbreon_mirror.png";
    def_textures_mirror[1] = "image/pokemons/majikarp_mirror.png";
    def_textures_mirror[2] = "image/pokemons/gyarados_mirror.png";
    def_textures_mirror[3] = "image/pokemons/numel_mirror.png";
    def_textures_mirror[4] = "image/pokemons/camerupth_mirror.png";
    def_textures_mirror[5] = "image/pokemons/kabuto_mirror.png";
    def_textures_mirror[6] = "image/pokemons/kabutops_mirror.png";
    return (def_textures_mirror);
}

char **create_def_textures(void)
{
    char **def_textures = malloc(sizeof(char *) * 7);
    for (int i = 0; i < 7; i++)
        def_textures[i] = malloc(sizeof(char) * 29);
    def_textures[0] = "image/pokemons/umbreon.png";
    def_textures[1] = "image/pokemons/majikarp.png";
    def_textures[2] = "image/pokemons/gyarados.png";
    def_textures[3] = "image/pokemons/numel.png";
    def_textures[4] = "image/pokemons/camerupth.png";
    def_textures[5] = "image/pokemons/kabuto.png";
    def_textures[6] = "image/pokemons/kabutops.png";
    return (def_textures);
}

char **create_def_attack_textures(void)
{
    char **attack_textures = malloc(sizeof(char *) * 7);
    for (int i = 0; i < 7; i++)
        attack_textures[i] = malloc(sizeof(char) * 54);
    attack_textures[0] = "image/pokemons/attacks/umbreon_attack.png";
    attack_textures[1] = NULL;
    attack_textures[2] = "image/pokemons/attacks/gyarados_attack.png";
    attack_textures[3] =
    "image/pokemons/attacks/numel_and_camerupth_attack.png";
    attack_textures[4] =
    "image/pokemons/attacks/numel_and_camerupth_attack.png";
    attack_textures[5] = NULL;
    attack_textures[6] = NULL;
    return (attack_textures);
}

void create_attacks(defenders_t **defenders,
char **def_attack_textures, int i)
{
    defenders[i]->can_attack = true;
    defenders[i]->attack_sprite = sfSprite_create();
    defenders[i]->attack_texture =
    sfTexture_createFromFile(def_attack_textures[i], NULL);
    sfSprite_setTexture(defenders[i]->attack_sprite,
    defenders[i]->texture, sfFalse);
    defenders[i]->attack_texture_name = my_strdup(def_attack_textures[i]);
}

void create_sprites_and_textures_defenders(defenders_t **defenders, int i)
{
    char **def_textures = create_def_textures();
    char **def_textures_mirror = create_def_mirror_textures();
    char **def_attack_textures = create_def_attack_textures();
    defenders[i]->sprite = sfSprite_create();
    defenders[i]->texture = sfTexture_createFromFile(def_textures[i], NULL);
    defenders[i]->can_attack = false;
    if (def_attack_textures[i] != NULL) {
        create_attacks(defenders, def_attack_textures, i);
    }
    defenders[i]->is_attacking = false;
    defenders[i]->texture_name = my_strdup(def_textures[i]);
    defenders[i]->texture_mirror_name = my_strdup(def_textures_mirror[i]);
    sfSprite_setTexture(defenders[i]->sprite, defenders[i]->texture, sfFalse);
    sfSprite_setTextureRect(defenders[i]->sprite, defenders[i]->rect);
    sfSprite_setPosition(defenders[i]->sprite, defenders[i]->initial_pos);
}
