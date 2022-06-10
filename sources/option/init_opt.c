/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu
*/

#include "option_defender.h"

char *button_way(int i)
{
    switch (i) {
        case 0:
            return ("image/option/VOLUME_TITLE.png");
        case 2:
        case 5:
            return ("image/option/MUSIC_BAR.png");
        case 1:
        case 4:
            return ("image/option/MUSIC_BAR_INT.png");
        case 3:
            return ("image/option/SOUND_TITLE.png");
        case 6:
            return ("image/option/BACK_BUTTON.png");
    default:
        break;
    }
    return ("void");
}

void vector_set_pos(button_t **button, int i)
{
    static int posy = 200;
    static int posx = 320;

    button[i]->size.x = 2;
    button[i]->size.y = 2;
    if (i == 6) {
        posx = 1480;
        posy = posy + 150;
    }
    if (i == 3)
        posy = posy + 60;
    button[i]->pos.x = posx;
    button[i]->pos.y = posy;
    i != 1 && i != 4 ?  posy = posy + 110 : 0;
    sfSprite_setScale(button[i]->button_sprite, button[i]->size);
    sfSprite_setPosition(button[i]->button_sprite, button[i]->pos);
    if (i == 6) {
        posy = 200;
        posx = 320;
    }
}

button_t **init_button_and_title(button_t **button)
{
    for (int i = 0; i < 7; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->button_sprite = sfSprite_create();
        button[i]->button_texture =
        sfTexture_createFromFile(button_way(i), NULL);
        sfSprite_setTexture(button[i]->button_sprite,
        button[i]->button_texture, sfFalse);
        vector_set_pos(button, i);
    }
    return (button);
}
