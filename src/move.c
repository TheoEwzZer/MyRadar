/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** move
*/

#include "my_radar.h"

void move2(var_t *var, int i)
{
    sfVector2f position = {0, 0};

    sfConvexShape_move(A[i]->hitbox, A[i]->offset);
    sfSprite_move(A[i]->sprite_aircraft, A[i]->offset);
    position = sfSprite_getPosition(A[i]->sprite_aircraft);
    if (sfIntRect_contains(var->nw->rect, (int)position.x, (int)position.y))
        A[i]->zone = 0;
    if (sfIntRect_contains(var->ne->rect, (int)position.x, (int)position.y))
        A[i]->zone = 1;
    if (sfIntRect_contains(var->sw->rect, (int)position.x, (int)position.y))
        A[i]->zone = 2;
    if (sfIntRect_contains(var->se->rect, (int)position.x, (int)position.y))
        A[i]->zone = 3;
}

void land_on(var_t *var, int i)
{
    sfConvexShape_destroy(A[i]->hitbox);
    sfSprite_destroy(A[i]->sprite_aircraft);
    free(A[i]);
    A[i] = NULL;
    var->aircraft_arrived += 1;
}

void move(var_t *var)
{
    sfTime time = sfClock_getElapsedTime(var->time);
    float seconds = (float)time.microseconds / 1000000.0f;
    sfVector2f position = {0, 0};
    for (int i = 0; i < var->aircraft_nb; i++) {
        if (!A[i] || seconds < A[i]->delay)
            continue;
        float tmp_x = A[i]->arrival.x;
        float tmp_y = A[i]->arrival.y;
        position = sfSprite_getPosition(A[i]->sprite_aircraft);
        change_destination_side(var, i);
        float x = A[i]->arrival.x - position.x;
        float y = A[i]->arrival.y - position.y;
        double distance = sqrt((x * x) + (y * y));
        if (distance <= 10.0f) {
            land_on(var, i);
        } else {
            change_aircraft_side(var, i, tmp_x, tmp_y);
            move2(var, i);
        }
    }
}

void move_clock(var_t *var)
{
    sfTime time = sfClock_getElapsedTime(var->clock);
    float seconds = (float)time.microseconds / 1000000.0f;

    if (seconds > (1.0f / 30.0f)) {
        move(var);
        sfClock_restart(var->clock);
    }
}
