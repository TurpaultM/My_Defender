/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** how to play
*/

#include "game_defender.h"

static void clic_button(global_t *glb, sfSprite *back, sfTexture *fond)
{
    if (glb->event.mouseButton.x >= 1590 && glb->event.mouseButton.y >= 935
    && glb->event.mouseButton.x <= 1870 && glb->event.mouseButton.y <= 977) {
        sfTexture_destroy(fond);
        sfSprite_destroy(back);
        menu_game(glb);
    }
}

static void analyse_events(global_t *glob, sfSprite *back, sfTexture *fond)
{
    while (sfRenderWindow_pollEvent(glob->window, &glob->event)) {
        if (glob->event.type == sfEvtMouseButtonPressed
        && glob->event.mouseButton.button == sfMouseLeft) {
            clic_button(glob, back, fond);
        }
    }
    sfRenderWindow_display(glob->window);
}

void how_to_play(global_t *glob)
{
    sfSprite *back = sfSprite_create();
    sfTexture *fond =
    sfTexture_createFromFile("image/map/how_to_play.jpg", NULL);
    sfVector2f size = {1, 0.96};

    sfSprite_setTexture(back, fond, sfFalse);
    sfSprite_setScale(back, size);
    while (sfRenderWindow_isOpen(glob->window)) {
        sfRenderWindow_clear(glob->window, sfBlack);
        sfRenderWindow_drawSprite(glob->window, back, sfFalse);
        analyse_events(glob, back, fond);
    }
}
