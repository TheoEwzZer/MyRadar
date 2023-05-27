/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** display
*/

#include "my_radar.h"

void display_corner(var_t *var)
{
    sfRenderWindow_drawRectangleShape(var->window, var->nw->shape, NULL);
    sfRenderWindow_drawRectangleShape(var->window, var->ne->shape, NULL);
    sfRenderWindow_drawRectangleShape(var->window, var->sw->shape, NULL);
    sfRenderWindow_drawRectangleShape(var->window, var->se->shape, NULL);
}

void display(var_t *var)
{
    sfTime time = var->pause ? var->pause_t : sfClock_getElapsedTime(var->time);
    float seconds = (float)time.microseconds / 1000000.0f;

    sfRenderWindow_drawSprite(var->window, var->background, NULL);
    for (int i = 0; i < var->tower_nb; i++) {
        if (var->display_sprite)
            sfRenderWindow_drawSprite(var->window, T[i]->sprite_tower, NULL);
        if (var->display_shape)
            sfRenderWindow_drawCircleShape(var->window, T[i]->area, NULL);
    }
    for (int i = 0; i < var->aircraft_nb; i++) {
        if (!A[i] || seconds < A[i]->delay)
            continue;
        if (var->display_sprite)
            sfRenderWindow_drawSprite(var->window, A[i]->sprite_aircraft, NULL);
        if (var->display_shape)
            sfRenderWindow_drawConvexShape(var->window, A[i]->hitbox, NULL);
    }
    if (var->display_corner)
        display_corner(var);
}

void display_timer(var_t *var)
{
    char *timer = malloc(sizeof(char) * 6);
    sfTime time = var->pause ? var->pause_t : sfClock_getElapsedTime(var->time);
    int minutes = (int)time.microseconds / 1000000 / 60;
    int seconds = (int)time.microseconds / 1000000 % 60;

    timer[0] = (char)((minutes / 10) + 48);
    timer[1] = (char)((minutes % 10) + 48);
    timer[2] = ':';
    timer[3] = (char)((seconds / 10) + 48);
    timer[4] = (char)((seconds % 10) + 48);
    timer[5] = '\0';
    sfText_setCharacterSize(var->text->timer, 50);
    sfText_setColor(var->text->timer, sfYellow);
    sfText_setFont(var->text->timer, var->text->font);
    sfText_setOutlineThickness(var->text->timer, 5.0f);
    sfText_setPosition(var->text->timer, (sfVector2f){1780.0f, 10.0f});
    sfText_setString(var->text->timer, timer);
    sfRenderWindow_drawText(var->window, var->text->timer, NULL);
}
