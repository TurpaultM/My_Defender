/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** game
*/

#include "game.h"

void clock_for_pokemons(pokemons_t *pokemons,
global_t *global, char **patterns)
{
    if (pokemons->increase_coins >= 50) {
        global->coins->nb_of_coins++;
        pokemons->increase_coins = 0;
    }
    sfTime currElapsedTime = sfClock_restart(pokemons->time->clock);
    pokemons->time->elapsedTime += currElapsedTime.microseconds;
    sfTime currElapsedTime_animations =
    sfClock_restart(pokemons->time->clock_animations);
    pokemons->time->elapsedTime_animations +=
    currElapsedTime_animations.microseconds;
    while (pokemons->time->elapsedTime >= 50000) {
        move_pokemons_each_second(pokemons, patterns);
    }
    while (pokemons->time->elapsedTime_animations >= 100000) {
        animate_pokemons(pokemons, global->window);
        pokemons->time->elapsedTime_animations -= 100000;
    }
}

void check_pause(global_t *glob, pokemons_t *pokemons)
{
    if (glob->event.type == sfEvtKeyPressed &&
    glob->event.key.code == sfKeyEscape) {
        if (pokemons->time->pause == false) {
            pokemons->time->pause = true;
        } else {
            pokemons->time->pause = false;
        }
    }
}

static void analyse_events(global_t *glob, pokemons_t *pokemons)
{
    check_pause(glob, pokemons);
    if (glob->event.type == sfEvtKeyPressed &&
    glob->event.key.code == sfKeyC) {
        if (pokemons->display_circles == false)
            pokemons->display_circles = true;
        else
            pokemons->display_circles = false;
    }
    if (glob->event.type == sfEvtClosed) {
        destroy_all_pokemons(pokemons);
        sfRenderWindow_close(glob->window);
    }
    leave_button_for_win_and_lose(pokemons, glob);
    press_butt(glob, pokemons);
    handle_defenders(pokemons, glob);
}

void game_when_window_is_open(pokemons_t *pokemons, global_t *global,
sfSprite *map)
{
    char**patterns = define_patterns();
    while (sfRenderWindow_isOpen(global->window)) {
        sfRenderWindow_clear(global->window, sfBlack);
        check_end_of_game(pokemons, global);
        display_sprites(global, map, pokemons);
        while (sfRenderWindow_pollEvent(global->window, &global->event)) {
            analyse_events(global, pokemons);
        }
        print_menu(global->window, &pokemons->validation,
        pokemons->time->pause);
        if (pokemons->time->pause == false)
            clock_for_pokemons(pokemons, global, patterns);
        else
            sfClock_restart(pokemons->time->clock);
        check_end_condition(pokemons, global);
        sfRenderWindow_display(global->window);
    }
}

void game(global_t *global, char *enemies)
{
    srand(0);
    sfSprite *map = sfSprite_create();
    sfTexture *texture_map =
    sfTexture_createFromFile("image/map/map_finale.jpg", NULL);
    sfSprite_setTexture(map, texture_map, sfFalse);
    sfSprite_setPosition(map, (sfVector2f){0, -1});
    pokemons_t* pokemons =
    create_pokemons_structure(enemies, global->coins->sprite);
    init_valid(&pokemons->validation);
    game_when_window_is_open(pokemons, global, map);
}
