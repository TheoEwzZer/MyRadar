/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** init_corner
*/

#include "my_radar.h"

void init_corner_ne(var_t *var)
{
    sfVector2f position = {0, 0};
    sfVector2f size = {0, 0};

    var->ne = malloc(sizeof(corner_t));
    var->ne->rect = malloc(sizeof(sfIntRect));
    var->ne->HEIGHTR = HEIGHT / 2;
    var->ne->LEFT = WIDTH / 2;
    var->ne->TOP = 0;
    var->ne->WIDTHR = WIDTH / 2;
    var->ne->shape = sfRectangleShape_create();
    position = (sfVector2f){(float)var->ne->LEFT, (float)var->ne->TOP};
    size = (sfVector2f){(float)var->ne->WIDTHR, (float)var->ne->HEIGHTR};
    sfRectangleShape_setFillColor(var->ne->shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(var->ne->shape, 1.0f);
    sfRectangleShape_setPosition(var->ne->shape, position);
    sfRectangleShape_setSize(var->ne->shape, size);
}

void init_corner_nw(var_t *var)
{
    sfVector2f position = {0, 0};
    sfVector2f size = {0, 0};

    var->nw = malloc(sizeof(corner_t));
    var->nw->rect = malloc(sizeof(sfIntRect));
    var->nw->HEIGHTR = HEIGHT / 2;
    var->nw->LEFT = 0;
    var->nw->TOP = 0;
    var->nw->WIDTHR = WIDTH / 2;
    var->nw->shape = sfRectangleShape_create();
    position = (sfVector2f){(float)var->nw->LEFT, (float)var->nw->TOP};
    size = (sfVector2f){(float)var->nw->WIDTHR, (float)var->nw->HEIGHTR};
    sfRectangleShape_setFillColor(var->nw->shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(var->nw->shape, 1.0f);
    sfRectangleShape_setPosition(var->nw->shape, position);
    sfRectangleShape_setSize(var->nw->shape, size);
}

void init_corner_se(var_t *var)
{
    sfVector2f position = {0, 0};
    sfVector2f size = {0, 0};

    var->se = malloc(sizeof(corner_t));
    var->se->rect = malloc(sizeof(sfIntRect));
    var->se->HEIGHTR = HEIGHT / 2;
    var->se->LEFT = WIDTH / 2;
    var->se->TOP = HEIGHT / 2;
    var->se->WIDTHR = WIDTH / 2;
    var->se->shape = sfRectangleShape_create();
    position = (sfVector2f){(float)var->se->LEFT, (float)var->se->TOP};
    size = (sfVector2f){(float)var->se->WIDTHR, (float)var->se->HEIGHTR};
    sfRectangleShape_setFillColor(var->se->shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(var->se->shape, 1.0f);
    sfRectangleShape_setPosition(var->se->shape, position);
    sfRectangleShape_setSize(var->se->shape, size);
}

void init_corner_sw(var_t *var)
{
    sfVector2f position = {0, 0};
    sfVector2f size = {0, 0};

    var->sw = malloc(sizeof(corner_t));
    var->sw->rect = malloc(sizeof(sfIntRect));
    var->sw->HEIGHTR = HEIGHT / 2;
    var->sw->LEFT = 0;
    var->sw->TOP = HEIGHT / 2;
    var->sw->WIDTHR = WIDTH / 2;
    var->sw->shape = sfRectangleShape_create();
    position = (sfVector2f){(float)var->sw->LEFT, (float)var->sw->TOP};
    size = (sfVector2f){(float)var->sw->WIDTHR, (float)var->sw->HEIGHTR};
    sfRectangleShape_setFillColor(var->sw->shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(var->sw->shape, 1.0f);
    sfRectangleShape_setPosition(var->sw->shape, position);
    sfRectangleShape_setSize(var->sw->shape, size);
}

void init_corner(var_t *var)
{
    init_corner_ne(var);
    init_corner_nw(var);
    init_corner_se(var);
    init_corner_sw(var);
}
