/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu
*/

#include "option_defender.h"

void music(int vol, global_t *glob)
{
    glob->music.pow = (float)((vol * 100) / 353);
    if (glob->music.pow > 100)
        glob->music.pow = 100;
    if (glob->music.pow < 0)
        glob->music.pow = 0;
    sfMusic_setVolume(glob->music.music, glob->music.pow);
}

void volume_bar(global_t *glob)
{
    if (glob->event.mouseButton.x >= 350 && glob->event.mouseButton.x <= 1040
    && glob->event.mouseButton.y >= 325 && glob->event.mouseButton.y <= 390) {
        glob->music.volume.width =
        (((((glob->event.mouseButton.x - 305) * 100) / 732) * 353) / 100);
        music(glob->music.volume.width, glob);
    }
}

void sound_bar(global_t *glob)
{
    if (glob->event.mouseButton.x >= 350 && glob->event.mouseButton.x <= 1040
    && glob->event.mouseButton.y >= 605 && glob->event.mouseButton.y <= 665) {
        glob->music.sound.width =
        (((((glob->event.mouseButton.x - 305) * 100) / 732) * 353) / 100);
        glob->music.pow_sound =
        (float)((glob->music.sound.width * 100) / 353);
    }
}
