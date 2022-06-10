/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** calculate_rotations
*/

#include "game.h"

float deg(float rad)
{
    return (rad * 180 / 3.14159265359);
}

float calculate_to_rotate(float x, float y)
{
    if (x >= 0 && y >= 0) {
        float res = deg(atanf(y / x));
        return (res);
    }
    if (x < 0 && y >= 0) {
        float res = deg(atanf(y / -x)) + (2* (90 - deg(atanf(-y / x))));
        return (res + 20);
    }
    if (x < 0 && y < 0) {
        float res = deg(atanf(-y / x)) + (2* (90 - deg(atanf(-y / x))));
        return (res);
    }
    float res = deg(atanf(-y / x));
    return ((res * -1) - 20);
}
