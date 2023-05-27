/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** init
*/

#include "my_radar.h"

#include <stdlib.h>
#include <time.h>

float height(void)
{
    float *heights = malloc(sizeof(float) * 3);
    int rand_num = rand() % 3;

    heights[0] = 1.0f;
    heights[1] = 1.5f;
    heights[2] = 2.0f;
    return heights[rand_num];
}

sfUint32 init_aircraft(var_t *var, char **infos)
{
    ANB = malloc(sizeof(aircraft_t));
    ANB->departure.x = (float)my_getnbr(infos[1]);
    ANB->departure.y = (float)my_getnbr(infos[2]);
    ANB->arrival.x = (float)my_getnbr(infos[3]);
    ANB->arrival.y = (float)my_getnbr(infos[4]);
    ANB->speed = (float)my_getnbr(infos[5]) / 30.0f;
    ANB->delay = my_getnbr(infos[6]);
    ANB->sprite_aircraft = sfSprite_create();
    ANB->scale = height();
    ANB->zone = 0;
    ANB->offset = init_offset(var);
    if (ANB->departure.x == -1.0f || ANB->departure.y == -1.0f)
        return 84;
    if (ANB->arrival.x == -1.0f || ANB->arrival.y == -1.0f)
        return 84;
    if (ANB->delay < 0.0f || ANB->speed <= 0.0f)
        return 84;
    var->aircraft_nb += 1;
    return 0;
}

void create_hitbox(aircraft_t *aircraft, sfVector2f position)
{
    HITBOX = sfConvexShape_create();
    sfConvexShape_setPointCount(HITBOX, 12);
    sfConvexShape_setPoint(HITBOX, 0, (sfVector2f){0.0f, 6.0f});
    sfConvexShape_setPoint(HITBOX, 1, (sfVector2f){3.0f, 9.0f});
    sfConvexShape_setPoint(HITBOX, 2, (sfVector2f){10.0f, 9.0f});
    sfConvexShape_setPoint(HITBOX, 3, (sfVector2f){8.0f, 0.0f});
    sfConvexShape_setPoint(HITBOX, 4, (sfVector2f){13.0f, 9.0f});
    sfConvexShape_setPoint(HITBOX, 5, (sfVector2f){20.0f, 10.0f});
    sfConvexShape_setPoint(HITBOX, 6, (sfVector2f){20.0f, 10.0f});
    sfConvexShape_setPoint(HITBOX, 7, (sfVector2f){13.0f, 11.0f});
    sfConvexShape_setPoint(HITBOX, 8, (sfVector2f){8.0f, 20.0f});
    sfConvexShape_setPoint(HITBOX, 9, (sfVector2f){10.0f, 11.0f});
    sfConvexShape_setPoint(HITBOX, 10, (sfVector2f){3.0f, 11.0f});
    sfConvexShape_setPoint(HITBOX, 11, (sfVector2f){0.0f, 14.0f});
    sfConvexShape_setFillColor(HITBOX, sfTransparent);
    sfConvexShape_setOrigin(HITBOX, (sfVector2f){10.0f * SCALE, 10.0f * SCALE});
    sfConvexShape_setOutlineColor(HITBOX, sfGreen);
    sfConvexShape_setOutlineThickness(HITBOX, 1.0f);
    sfConvexShape_setPosition(HITBOX, position);
    sfConvexShape_setScale(HITBOX, (sfVector2f){SCALE, SCALE});
}

sfSprite *set_aircraft_sprite(var_t *var, aircraft_t *aircraft)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/aircraft.png", NULL);
    sfVector2f position = {aircraft->departure.x, aircraft->departure.y};

    create_hitbox(aircraft, position);
    set_rotation(aircraft, sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){10.0f * SCALE, 10.0f * SCALE});
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f){SCALE, SCALE});
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (sfIntRect_contains(var->nw->rect, (int)position.x, (int)position.y))
        aircraft->zone = 0;
    if (sfIntRect_contains(var->ne->rect, (int)position.x, (int)position.y))
        aircraft->zone = 1;
    if (sfIntRect_contains(var->sw->rect, (int)position.x, (int)position.y))
        aircraft->zone = 2;
    if (sfIntRect_contains(var->se->rect, (int)position.x, (int)position.y))
        aircraft->zone = 3;
    return sprite;
}
