/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** init_path.c
*/

#include "my_radar.h"

sfVector2f init_offset(var_t *var)
{
    sfVector2f offset = {0, 0};
    float x = ANB->arrival.x - ANB->departure.x;
    float y = ANB->arrival.y - ANB->departure.y;
    float len = (ABS(x) < ABS(y)) ? ABS(y) : ABS(x);

    offset.x = (x / len) * ANB->speed;
    offset.y = (y / len) * ANB->speed;
    return offset;
}

void set_rotation(aircraft_t *aircraft, sfSprite *sprite)
{
    float adjacent = aircraft->arrival.x - aircraft->departure.x;
    float opposite = aircraft->arrival.y - aircraft->departure.y;
    float angle = atan2f(opposite, adjacent) * (180.0f / 3.141592741f);

    sfConvexShape_setRotation(HITBOX, angle);
    sfSprite_setRotation(sprite, angle);
}
