/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** place_defenders
*/

#include "game.h"

int change_old_def(int i, int def)
{
    if (i < def)
        return (def);
    return (i);
}

int click_on_a_defender(global_t *glob, pokemons_t *pokemons)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(glob->window);
    sfVector2f pos_mouse;
    pos_mouse.x = pos.x;
    pos_mouse.y = pos.y;
    sfVector2f pos_pokemon;
    for (int i = 0; i < 7; i++) {
        pos_pokemon = sfSprite_getPosition(pokemons->defenders[i]->sprite);
        if (pos.x >= pos_pokemon.x - 20 && pos.x <= pos_pokemon.x + 120
        && pos.y >= pos_pokemon.y - 20 && pos.y <= pos_pokemon.y + 100
        && glob->coins->nb_of_coins >= pokemons->defenders[i]->cost &&
        is_an_evolved(i) == false) {
            pos_mouse.x -= 50;
            pos_mouse.y -= 40;
            i = change_old_def(i, pokemons->defenders[0]->old_def);
            sfSprite_setPosition(pokemons->defenders[i]->sprite, pos_mouse);
            return (i);
        }
    }
    return (-1);
}

void handle_defenders(pokemons_t *pokemons, global_t *glob)
{
    if (pokemons->time->pause == false)
        check_evolution(pokemons, glob);
    int defender = -1;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    pokemons->time->pause == false) {
        defender = click_on_a_defender(glob, pokemons);
    }
    if (glob->event.type == sfEvtMouseButtonReleased) {
        if (pokemons->defenders[1]->old_def != -1) {
            sfVector2i pos = sfMouse_getPositionRenderWindow(glob->window);
            check_squares(pokemons, pos, glob);
            int which_defender = pokemons->defenders[1]->old_def;
            sfSprite_setPosition(pokemons->defenders[which_defender]->sprite,
            pokemons->defenders[which_defender]->initial_pos);
        }
    }
    pokemons->defenders[1]->old_def = pokemons->defenders[0]->old_def;
    pokemons->defenders[0]->old_def = defender;
}
