/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** end_of_the_game
*/

#include "game.h"

void leave_button_for_win_and_lose(pokemons_t *pok, global_t *glob)
{
    if (glob->event.mouseButton.x >= 940 && glob->event.mouseButton.x <= 1270
    && glob->event.mouseButton.y >= 605 && glob->event.mouseButton.y <= 705) {
        if (pok->total_life <= 0 || all_pokemons_are_destroyed(pok) == true) {
                menu_game(glob);
        }
    }
}

void check_end_condition(pokemons_t *pokemons, global_t *glob)
{
    if (all_pokemons_are_destroyed(pokemons) == true) {
        sfText_setString(glob->success->text, "Well played\n\t\t\tYou WIN");
        sfText_setScale(glob->success->text, (sfVector2f){2.2, 2.2});
        sfSprite_setScale(glob->success->image, (sfVector2f){1.5, 1.5});
        sfText_setPosition(glob->success->text, glob->success->pos_text);
        sfSprite_setPosition(glob->success->image, glob->success->pos);
        sfText_setColor(glob->success->text, sfYellow);
        sfRenderWindow_drawSprite(glob->window, glob->success->image, NULL);
        sfRenderWindow_drawText(glob->window, glob->success->text, NULL);
    }
    if (pokemons->total_life <= 0) {
        sfText_setString(glob->success->text, "You're bad\n\t\t\tRetry !");
        sfText_setPosition(glob->success->text, glob->success->pos_text);
        sfSprite_setPosition(glob->success->image, glob->success->pos);
        sfText_setScale(glob->success->text, (sfVector2f){2.2, 2.2});
        sfSprite_setScale(glob->success->image, (sfVector2f){1.5, 1.5});
        sfText_setColor(glob->success->text, sfYellow);
        sfRenderWindow_drawSprite(glob->window, glob->success->image, NULL);
        sfRenderWindow_drawText(glob->window, glob->success->text, NULL);
    }
}
