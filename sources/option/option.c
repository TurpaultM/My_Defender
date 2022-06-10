/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu
*/

#include "option_defender.h"

void destroy_button(button_t **butt)
{
    for (int i = 0; i != 6; i++) {
        sfTexture_destroy(butt[i]->button_texture);
        sfSprite_destroy(butt[i]->button_sprite);
    }
}

static void clic_button(global_t *glob, int scene, button_t **butt)
{
    if (glob->event.mouseButton.x >= 1485 && glob->event.mouseButton.y >= 865
    && glob->event.mouseButton.x <= 1855
    && glob->event.mouseButton.y <= 945) {
        if (scene == 1) {
            destroy_button(butt);
            menu(glob);
        }
        if (scene == 2) {
            destroy_button(butt);
            menu_game(glob);
        }
    }
}

static void analyse_events(global_t *glob, button_t **butt, int scene)
{
    while (sfRenderWindow_pollEvent(glob->window, &glob->event)) {
        if (glob->event.type == sfEvtClosed) {
            sfRenderWindow_close(glob->window);
            destroy_button(butt);
        }
        if (glob->event.type == sfEvtMouseButtonPressed
        && glob->event.mouseButton.button == sfMouseLeft) {
            clic_button(glob, scene, butt);
            volume_bar(glob);
            sound_bar(glob);
        }
    }
    sfSprite_setTextureRect(butt[1]->button_sprite, glob->music.volume);
    sfSprite_setTextureRect(butt[4]->button_sprite, glob->music.sound);
    sfRenderWindow_display(glob->window);
}

void option(global_t *glob, int scene)
{
    button_t **button = malloc(sizeof(button_t *) * 7);
    sfSprite *back = sfSprite_create();
    sfTexture *fond =
    sfTexture_createFromFile("image/menu/backgroundmenu.jpg", NULL);

    init_button_and_title(button);
    sfSprite_setTexture(back, fond, sfFalse);
    while (sfRenderWindow_isOpen(glob->window)) {
        sfRenderWindow_clear(glob->window, sfBlack);
        sfRenderWindow_drawSprite(glob->window, back, sfFalse);
        for (int i = 0; i < 7; i++) {
            sfRenderWindow_drawSprite(glob->window,
            button[i]->button_sprite, sfFalse);
        }
        analyse_events(glob, button, scene);
    }
}
