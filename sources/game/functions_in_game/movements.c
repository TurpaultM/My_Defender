/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** movements
*/

#include "game.h"

void check_end_of_deplacement(pokemons_t *pokemons, char **patterns)
{
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (pokemons->movements->travelled_distance[i] >
        pokemons->movements->movements[i] &&
        patterns[i][pokemons->movements->pos_pattern[i]] != '\0') {
            pokemons->movements->pos_pattern[i] += 5;
            pokemons->movements->travelled_distance[i] = 0;
        }
    }
}

void move_to_the_right_direction(pokemons_t *pokemons, char *args,
void (*function[3])(enemies_t **, movements_t *, int), int j)
{
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        if (args[j] == pokemons->movements->direction[i] &&
        pokemons->enemies[i]->is_on_map == true)
            function[j](pokemons->enemies, pokemons->movements, i);
    }
}

void move_pokemons(pokemons_t *pokemons, char **patterns)
{
    check_end_of_deplacement(pokemons, patterns);
    for (int i = 0; i < pokemons->nb_of_pokemons; i++) {
        pokemons->movements->movements[i] =
        my_getnbr(&patterns[i][pokemons->movements->pos_pattern[i]]);
        pokemons->movements->direction[i] =
        patterns[i][pokemons->movements->pos_pattern[i]];
    }
    void (*function[3])(enemies_t **, movements_t *, int) =
    {go_right, go_top, go_down};
    char *args = "DHB";
    for (int j = 0; j < 3; j++) {
        move_to_the_right_direction(pokemons, args, function, j);
    }
}

void move_pokemons_each_second(pokemons_t *pokemons, char **patterns)
{
    pokemons->time->total_time++;
    if (pokemons->time->total_time >=
    pokemons->enemies[pokemons->nb_of_pokemons]->time_to_wait &&
    pokemons->nb_of_pokemons < pokemons->nb_total) {
        pokemons->nb_of_pokemons++;
        pokemons->time->total_time = 0;
    }
    move_pokemons(pokemons, patterns);
    for (int i = 0; i < pokemons->nb_of_defenders; i++) {
        check_if_defenders_detect_enemies(pokemons, i);
    }
    pokemons->time->elapsedTime -= 50000;
}
