/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** place_defenders_in_squares
*/

#include "game.h"

bool is_occuped(pokemons_t *pokemons, int i)
{
    for (int j = 0; j < pokemons->nb_of_defenders; j++) {
        if (pokemons->placed_defenders[j]->which_square == i)
            return (true);
    }
    return (false);
}

bool is_on_square(pokemons_t *pokemons, sfVector2i position, int i)
{
    if (position.x >= pokemons->defenders[i]->position.x - 20 &&
    position.x <= pokemons->defenders[i]->position.x + 90 &&
    position.y >= pokemons->defenders[i]->position.y - 20 &&
    position.y <= pokemons->defenders[i]->position.y + 90 &&
    is_occuped(pokemons, i) == false) {
        return (true);
    }
    return (false);
}

void put_defender_in_square(pokemons_t *pokemons,
int i, global_t *glob, int which_one)
{
    sfSound_setVolume(pokemons->defenders
    [pokemons->defenders[1]->old_def]->sound, glob->music.pow_sound);
    sfSound_play(pokemons->defenders[pokemons->defenders[1]->old_def]->sound);
    sfVector2f locked_position;
    locked_position.x = pokemons->defenders[i]->position.x - 10;
    locked_position.y = pokemons->defenders[i]->position.y;
    sfSprite *sprite =
    pokemons->defenders[pokemons->defenders[1]->old_def]->sprite;
    sfSprite_setPosition(sprite, locked_position);
    pokemons->defenders[pokemons->defenders[1]->old_def]->which_square
    = i;
    pokemons->placed_defenders[which_one] =
    defcpy(pokemons->defenders[pokemons->defenders[1]->old_def]);
    pokemons->nb_of_defenders++;
    glob->coins->nb_of_coins -=
    pokemons->defenders[pokemons->defenders[1]->old_def]->cost;
}

void check_squares(pokemons_t *pokemons, sfVector2i position, global_t *glob)
{
    pokemons->defenders[pokemons->defenders[1]->old_def]->which_square =
    -1;
    for (int i = 0; i < 16; i++) {
        if (is_on_square(pokemons, position, i) == true) {
            put_defender_in_square(pokemons, i,
            glob, pokemons->nb_of_defenders);
        }
    }
}
