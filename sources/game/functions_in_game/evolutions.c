/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** evolutions
*/

#include "game.h"

void evolve(pokemons_t *pokemons, int i, int which_one, global_t *glob)
{
    sfVector2f position = pokemons->defenders[which_one]->position;
    int which_square = pokemons->placed_defenders[i]->which_square;
    int old_def = pokemons->defenders[1]->old_def;
    pokemons->defenders[1]->old_def = which_one;
    pokemons->defenders[which_one]->position =
    sfSprite_getPosition(pokemons->placed_defenders[i]->sprite);
    destroy_defender(pokemons->placed_defenders[i]);
    pokemons->nb_of_defenders--;
    put_defender_in_square(pokemons, which_one, glob, i);
    pokemons->placed_defenders[i]->which_square = which_square;
    pokemons->defenders[which_one]->which_square = -1;
    pokemons->defenders[which_one]->position = position;
    pokemons->defenders[1]->old_def = old_def;
}

int find_which_one(pokemons_t *pokemons, int i)
{
    if (my_strcmp("majikarp", pokemons->placed_defenders[i]->name) == 0)
        return (2);
    if (my_strcmp("numel", pokemons->placed_defenders[i]->name) == 0)
        return (4);
    return (6);
}

void check_evolve(pokemons_t *pokemon, global_t *glob, sfVector2i mouse_pos)
{
    sfVector2f sprite_pos = {0, 0};
    int which_one;
    for (int i = 0; i < pokemon->nb_of_defenders; i++) {
        if (my_strcmp("majikarp", pokemon->placed_defenders[i]->name) == 0 ||
        my_strcmp("numel", pokemon->placed_defenders[i]->name) == 0 ||
        my_strcmp("kabuto", pokemon->placed_defenders[i]->name) == 0)
            sprite_pos =
            sfSprite_getPosition(pokemon->placed_defenders[i]->evolve_button);
        else {
            sprite_pos.x = -200;
            sprite_pos.y = -200;
        }
        which_one = find_which_one(pokemon, i);
        if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= sprite_pos.x + 50 &&
        mouse_pos.y >= sprite_pos.y && mouse_pos.y <= sprite_pos.y + 50 &&
        glob->coins->nb_of_coins >=
        pokemon->defenders[which_one]->cost)
            evolve(pokemon, i, which_one, glob);
    }
}

void check_evolution(pokemons_t *pokemon, global_t *glob)
{
    sfVector2i mouse_pos = {0, 0};
    if (glob->event.type == sfEvtMouseButtonReleased) {
        mouse_pos = sfMouse_getPositionRenderWindow(glob->window);
    }
    check_evolve(pokemon, glob, mouse_pos);
}
