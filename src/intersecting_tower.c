/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** intersecting_tower
*/

#include "my_radar.h"

double check_x(sfVector2f tower, sfVector2f aircraft, float scale)
{
    if (tower.x < aircraft.x)
        return aircraft.x;
    if (tower.x > aircraft.x + (20.0f * scale))
        return aircraft.x + (20.0f * scale);
    return tower.x;
}

double check_y(sfVector2f tower, sfVector2f aircraft, float scale)
{
    if (tower.y < aircraft.y)
        return aircraft.y;
    if (tower.y > aircraft.y + (20.0f * scale))
        return aircraft.y + (20.0f * scale);
    return tower.y;
}

sfBool intersecting_tower(var_t *var, int j)
{
    sfVector2f aircraft = {0, 0};
    sfVector2f tower = {0, 0};
    if (!A[j])
        return sfFalse;
    aircraft = sfConvexShape_getPosition(A[j]->hitbox);
    for (int i = 0; i < var->tower_nb; i++) {
        if (!T[i])
            continue;
        tower = sfCircleShape_getPosition(T[i]->area);
        tower.x += (float)T[i]->radius;
        tower.y += (float)T[i]->radius;
        double x = check_x(tower, aircraft, A[j]->scale);
        double y = check_y(tower, aircraft, A[j]->scale);
        double dist_x = tower.x - x;
        double dist_y = tower.y - y;
        double dist = sqrt((dist_x * dist_x) + (dist_y * dist_y));
        if (dist <= T[i]->radius)
            return sfTrue;
    }
    return sfFalse;
}
