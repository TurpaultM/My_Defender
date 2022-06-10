/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** movements_functions
*/

#include "game.h"

void go_right(enemies_t **enemies, movements_t *movements, int i)
{
    sfVector2f move;
    move.x = enemies[i]->speed;
    move.y = 0;
    sfSprite_move(enemies[i]->sprite, move);
    movements->travelled_distance[i] += enemies[i]->speed;
}

void go_top(enemies_t **enemies, movements_t *movements, int i)
{
    sfVector2f move;
    move.x = 0;
    move.y = (enemies[i]->speed) * -1;
    sfSprite_move(enemies[i]->sprite, move);
    movements->travelled_distance[i] += enemies[i]->speed;
}

void go_down(enemies_t **enemies, movements_t *movements, int i)
{
    sfVector2f move;
    move.x = 0;
    move.y = enemies[i]->speed;
    sfSprite_move(enemies[i]->sprite, move);
    movements->travelled_distance[i] += enemies[i]->speed;
}
