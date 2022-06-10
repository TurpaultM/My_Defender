/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu
*/

#include "menu_defender.h"
#include "game.h"

sfRenderWindow *createwindow(unsigned int x, unsigned int y,
unsigned int bbp, char *title)
{
    sfVideoMode mode = {x, y, bbp};
    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}

void menu(global_t *glob)
{
    button_t **button = malloc(sizeof(button_t*) * 3);
    sfSprite *back = sfSprite_create();
    sfTexture *fond =
    sfTexture_createFromFile("image/menu/backgroundmenu.jpg", NULL);

    init_button(button);
    sfSprite_setTexture(back, fond, sfFalse);
    while (sfRenderWindow_isOpen(glob->window)) {
        sfRenderWindow_clear(glob->window, sfWhite);
        sfRenderWindow_drawSprite(glob->window, back, sfFalse);
        for (int i = 0; i < 3; i++) {
            sfRenderWindow_drawSprite(glob->window,
            button[i]->button_sprite, sfFalse);
        }
        analyse_events(glob, button);
    }
}

void init_music(global_t *glob)
{
    glob->music.music =
    sfMusic_createFromFile("music_sound/ambiance/pokemon_music.ogg");
    glob->music.pow = 0;
    glob->music.volume.height = 37;
    glob->music.volume.left = 0;
    glob->music.volume.top = 0;
    glob->music.volume.width = 353;
    glob->music.sound.height = 37;
    glob->music.sound.left = 0;
    glob->music.sound.top = 0;
    glob->music.pow_sound = 100;
    glob->music.sound.width = 353;
    glob->pokedex_access = malloc(sizeof(char));
    glob->pokedex_access[0] = '\0';
}

void start_menu(void)
{
    global_t glob;

    create_coins_structure(&glob);
    glob.window = createwindow(1920, 1080, 2, "Pokedefence");
    init_music(&glob);
    init_jiggly(&glob);
    init_end_condition(&glob);
    sfMusic_play(glob.music.music);
    sfMusic_setLoop(glob.music.music, sfTrue);
    menu(&glob);
    sfMusic_stop(glob.music.music);
    sfMusic_destroy(glob.music.music);
}
