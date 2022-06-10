/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu
*/

#include "menu_defender.h"

void destroy_menu(button_t **butt)
{
    for (int i = 0; i != 3; i++) {
        sfTexture_destroy(butt[i]->button_texture);
        sfSprite_destroy(butt[i]->button_sprite);
    }
}

void clic_button(global_t *glb, button_t **butt)
{
    if (glb->event.mouseButton.x >= 775 && glb->event.mouseButton.y >= 314
    && glb->event.mouseButton.x <= 1140 && glb->event.mouseButton.y <= 390) {
        destroy_menu(butt);
        menu_game(glb);
        return;
    }
    if (glb->event.mouseButton.x >= 775 && glb->event.mouseButton.y >= 515
    && glb->event.mouseButton.x <= 1140 && glb->event.mouseButton.y <= 590) {
        destroy_menu(butt);
        option(glb, 1);
        return;
    }
    if (glb->event.mouseButton.x >= 775 && glb->event.mouseButton.y >= 714
    && glb->event.mouseButton.x <= 1140 && glb->event.mouseButton.y <= 790) {
        destroy_menu(butt);
        sfRenderWindow_close(glb->window);
        return;
    }
}

void analyse_events(global_t *glob, button_t **butt)
{
    sfRenderWindow_display(glob->window);
    while (sfRenderWindow_pollEvent(glob->window, &glob->event)) {
        if (glob->event.type == sfEvtClosed)
            sfRenderWindow_close(glob->window);
        if (glob->event.type == sfEvtMouseButtonPressed
        && glob->event.mouseButton.button == sfMouseLeft)
            clic_button(glob, butt);
    }
}

char *button_way_menu(int i)
{
    if (i == 0) {
        return ("image/menu/START_BUTTON.png");
    }
    if (i == 1) {
        return ("image/menu/OPTION_BUTTON.png");
    }
    if (i == 2) {
        return ("image/menu/EXIT_BUTTON.png");
    }
    return "void";
}

button_t **init_button(button_t **button)
{
    int posy = 300;
    for (int i = 0; i < 3; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->button_sprite = sfSprite_create();
        button[i]->button_texture =
        sfTexture_createFromFile(button_way_menu(i), NULL);
        sfSprite_setTexture(button[i]->button_sprite,
        button[i]->button_texture, sfFalse);
        button[i]->size.x = 2;
        button[i]->size.y = 2;
        button[i]->pos.x = 770;
        button[i]->pos.y = posy;
        posy = posy + 200;
        sfSprite_setScale(button[i]->button_sprite, button[i]->size);
        sfSprite_setPosition(button[i]->button_sprite, button[i]->pos);
    }
    return (button);
}
