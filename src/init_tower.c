/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** init
*/

#include "my_radar.h"

#include <stdlib.h>
#include <time.h>

sfUint32 init_tower(var_t *var, char **infos)
{
    TNB = malloc(sizeof(tower_t));
    TNB->coordinates.x = (float)my_getnbr(infos[1]);
    TNB->coordinates.y = (float)my_getnbr(infos[2]);
    TNB->radius = WIDTH * ((float)my_getnbr(infos[3]) / 100.0f);
    TNB->sprite_tower = sfSprite_create();
    if (TNB->coordinates.x < 0.0f || TNB->coordinates.y < 0.0f)
        return 84;
    if (TNB->radius < 0.0f)
        return 84;
    var->tower_nb += 1;
    return 0;
}

sfSprite *set_tower_sprite(tower_t *tower)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/tower.png", NULL);
    sfVector2f position_area = {0, 0};
    sfVector2f position_tower = {tower->coordinates.x, tower->coordinates.y};

    position_area.x = tower->coordinates.x + 20.0f - tower->radius;
    position_area.y = tower->coordinates.y + 20.0f - tower->radius;
    AREA = sfCircleShape_create();
    sfCircleShape_setFillColor(AREA, sfTransparent);
    sfCircleShape_setOrigin(AREA, (sfVector2f){20.0f, 20.0f});
    sfCircleShape_setOutlineColor(AREA, sfBlue);
    sfCircleShape_setOutlineThickness(AREA, 1);
    sfCircleShape_setPosition(AREA, position_area);
    sfCircleShape_setRadius(AREA, tower->radius);
    sfSprite_setOrigin(sprite, (sfVector2f){20.0f, 20.0f});
    sfSprite_setPosition(sprite, position_tower);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
