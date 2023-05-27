/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** side
*/

#include "my_radar.h"

sfBool check_in_win(sfVector2f position)
{
    return (position.y <= 0 || position.x <= 0
    || position.x >= WIDTH || position.y >= HEIGHT);
}

void change_destination_side(var_t *var, int i)
{
    if (A[i]->arrival.x < 0)
        A[i]->arrival.x = WIDTH + A[i]->arrival.x;
    else if (A[i]->arrival.x > WIDTH)
        A[i]->arrival.x = 0 + A[i]->arrival.x ;
    if (A[i]->arrival.y < 0)
        A[i]->arrival.y = HEIGHT + A[i]->arrival.y;
    else if (A[i]->arrival.y > HEIGHT)
        A[i]->arrival.y = 0 + A[i]->arrival.y;
}

void change_aircraft_side(var_t *var, int i, float tmp_x, float tmp_y)
{
    sfVector2f position = sfSprite_getPosition(A[i]->sprite_aircraft);

    if (check_in_win(position)) {
        if (position.x <= 0)
            position.x = WIDTH;
        if (position.x > WIDTH)
            position.x = 0;
        if (position.y <= 0)
            position.y = HEIGHT;
        if (position.y > HEIGHT)
            position.y = 0;
        sfSprite_setPosition(A[i]->sprite_aircraft, position);
        sfConvexShape_setPosition(A[i]->hitbox, position);
    }
    A[i]->arrival.x = tmp_x;
    A[i]->arrival.y = tmp_y;
}
