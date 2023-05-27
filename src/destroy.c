/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** destroy
*/

#include "my_radar.h"

void destroy_text(var_t *var)
{
    if (var->text->font)
        sfFont_destroy(var->text->font);
    if (var->text->shape_bool)
        sfText_destroy(var->text->shape_bool);
    if (var->text->shapes)
        sfText_destroy(var->text->shapes);
    if (var->text->sprite_bool)
        sfText_destroy(var->text->sprite_bool);
    if (var->text->sprites)
        sfText_destroy(var->text->sprites);
    if (var->text->timer)
        sfText_destroy(var->text->timer);
    free(var->text);
    var->text = NULL;
}

void destroy_entities(var_t *var)
{
    for (int i = 0; i < var->aircraft_nb; i++) {
        if (!A[i])
            continue;
        sfConvexShape_destroy(A[i]->hitbox);
        sfSprite_destroy(A[i]->sprite_aircraft);
        free(A[i]);
        A[i] = NULL;
    }
    for (int i = 0; i < var->tower_nb; i++) {
        if (!T[i])
            continue;
        sfCircleShape_destroy(T[i]->area);
        sfSprite_destroy(T[i]->sprite_tower);
        free(T[i]);
        T[i] = NULL;
    }
    free(A);
    free(T);
    A = NULL;
    T = NULL;
}

void destroy(var_t *var)
{
    destroy_text(var);
    destroy_entities(var);
    sfClock_destroy(var->clock);
    sfClock_destroy(var->time);
    sfRenderWindow_destroy(var->window);
    sfSprite_destroy(var->background);
    free(var);
    var = NULL;
}
