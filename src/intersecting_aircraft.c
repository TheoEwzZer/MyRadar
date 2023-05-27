/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** intersecting
*/

#include "my_radar.h"

void crash(var_t *var, int i, int j)
{
    sfConvexShape_destroy(A[i]->hitbox);
    sfConvexShape_destroy(A[j]->hitbox);
    sfSprite_destroy(A[i]->sprite_aircraft);
    sfSprite_destroy(A[j]->sprite_aircraft);
    free(A[i]);
    free(A[j]);
    A[i] = NULL;
    A[j] = NULL;
    var->aircraft_arrived += 2;
}

sfBool intersecting_aircraft(var_t *var, int j, sfVector2f pos1, float s)
{
    sfVector2f pos2 = sfConvexShape_getPosition(A[j]->hitbox);

    return (pos1.x + s >= pos2.x && pos1.x <= pos2.x + s &&
            pos1.y + s >= pos2.y && pos1.y <= pos2.y + s);
}

void check_tower(var_t *var, int i, int j)
{
    if (!intersecting_tower(var, i) || !intersecting_tower(var, j))
        crash(var, i, j);
}

void check_collisions(var_t *var, int i)
{
    float scale = A[i]->scale * 20;
    sfVector2f pos = sfConvexShape_getPosition(A[i]->hitbox);

    for (int j = 0; j < var->aircraft_nb; j++) {
        if (i == j || !A[i] || !A[j])
            continue;
        if (A[i]->scale != A[j]->scale || A[i]->zone != A[j]->zone)
            continue;
        if (intersecting_aircraft(var, j, pos, scale))
            check_tower(var, i, j);
    }
}
