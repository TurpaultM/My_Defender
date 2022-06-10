/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** initialize_pokemons
*/

#include "game.h"

void create_square(defenders_t **defenders, int i)
{
    defenders[i]->square = sfRectangleShape_create();
    char *pos_x[16] = {"440", "660", "440", "660", "840", "840", "1250",
    "1250", "1050", "1430", "1650", "950", "1150", "660", "1430", "1730"};
    char *pos_y[16] = {"460", "460", "580", "580", "430", "510", "430",
    "510", "470", "580", "580", "670", "670", "290", "370", "400"};
    defenders[i]->position.x = my_getnbr(pos_x[i]);
    defenders[i]->position.y = my_getnbr(pos_y[i]);
    defenders[i]->square_pos.x = my_getnbr(pos_x[i]);
    defenders[i]->square_pos.y = my_getnbr(pos_y[i]);
    sfVector2f size;
    size.x = 70;
    size.y = 70;
    sfRectangleShape_setPosition(defenders[i]->square,
    defenders[i]->square_pos);
    sfRectangleShape_setSize(defenders[i]->square, size);
    sfRectangleShape_setOutlineColor(defenders[i]->square, sfRed);
    sfRectangleShape_setFillColor(defenders[i]->square, sfTransparent);
    sfRectangleShape_setOutlineThickness(defenders[i]->square, 1);
}

void create_coins_structure(global_t *glob)
{
    glob->coins = malloc(sizeof(coins_t));
    glob->coins->string = malloc(sizeof(char) * 6);
    glob->coins->string[0] = '\0';
    glob->coins->nb_of_coins = 250;
    glob->coins->font = sfFont_createFromFile("Police/pokemon.ttf");
    glob->coins->position.x = 1680;
    glob->coins->position.y = 0;
    glob->coins->text = sfText_create();
    glob->coins->sprite = sfSprite_create();
    glob->coins->texture =
    sfTexture_createFromFile("image/coin.png", NULL);
    sfSprite_setTexture(glob->coins->sprite,
    glob->coins->texture, sfFalse);
    sfSprite_setPosition(glob->coins->sprite, (sfVector2f){1850, 0});
}

void create_little_variables(pokemons_t *pokemons)
{
    pokemons->nb_of_defenders = 0;
    pokemons->display_circles = true;
    pokemons->placing_pokemon = false;
    pokemons->defenders[0]->old_def = -1;
    pokemons->defenders[1]->old_def = -1;
    pokemons->total_life = 20;
    pokemons->increase_coins = 0;
    pokemons->nb_of_pokemons = 1;
}

void create_pokemons(pokemons_t *creation_of_pokemons, pokemons_t *pokemons,
sfSprite *coin)
{
    creation_of_pokemons->enemies = malloc(sizeof(enemies_t *) * 379);
    pokemons->enemies = malloc(sizeof(enemies_t *) * 379);
    pokemons->defenders = malloc(sizeof(defenders_t *) * 16);
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 16);
    for (int i = 0; i < 379; i++) {
        creation_of_pokemons->enemies[i] = malloc(sizeof(enemies_t));
        pokemons->enemies[i] = malloc(sizeof(enemies_t));
    }
    for (int i = 0; i < 16; i++) {
        pokemons->defenders[i] = malloc(sizeof(defenders_t));
        create_square(pokemons->defenders, i);
    }
    initialize_pokemons(creation_of_pokemons->enemies, pokemons->defenders,
    coin);
    create_little_variables(pokemons);
}

void choose_pokemons(pokemons_t *creation_of_pokemons,
pokemons_t *pokemons, char *which_one)
{
    int j = 0;
    int time_to_wait = 0;
    for (int i = 0; i < my_strlen(which_one); i++) {
        while (which_one[i] >= 57 && which_one[i] != ' ') {
            my_putstr("t'as mis un 9 débile ");
            i++;
        }
        if (which_one[i] == ' ')
            time_to_wait += 10;
        else {
            pokemons->enemies[j] =
            my_structcpy(creation_of_pokemons->enemies[which_one[i] - 48],
            which_one[i] - 48);
            pokemons->enemies[j]->time_to_wait += time_to_wait;
            time_to_wait = 0;
            j++;
        }
        random_shiny(pokemons->enemies[j]);
    }
    pokemons->nb_total = j;
}
