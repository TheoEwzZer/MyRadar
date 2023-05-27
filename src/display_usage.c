/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** display_usage
*/

#include "my_radar.h"

void display_usage_corner(var_t *var)
{
    sfColor color = var->display_corner ? sfGreen : sfRed;
    const char *string = var->display_corner ? "ON" : "OFF";

    sfText_setCharacterSize(var->text->corner_bool, 50);
    sfText_setCharacterSize(var->text->sprites, 50);
    sfText_setColor(var->text->corner_bool, color);
    sfText_setColor(var->text->sprites, sfYellow);
    sfText_setFont(var->text->corner_bool, var->text->font);
    sfText_setFont(var->text->sprites, var->text->font);
    sfText_setOutlineThickness(var->text->corner_bool, 5.0f);
    sfText_setOutlineThickness(var->text->sprites, 5.0f);
    sfText_setPosition(var->text->corner_bool, (sfVector2f){670.0f, 10.0f});
    sfText_setPosition(var->text->sprites, (sfVector2f){370.0f, 10.0f});
    sfText_setString(var->text->corner_bool, string);
    sfText_setString(var->text->sprites, "Corners (C) :");
    sfRenderWindow_drawText(var->window, var->text->sprites, NULL);
    sfRenderWindow_drawText(var->window, var->text->corner_bool, NULL);
}

void display_usage_sprite(var_t *var)
{
    sfColor color = var->display_sprite ? sfGreen : sfRed;
    const char *string = var->display_sprite ? "ON" : "OFF";

    sfText_setCharacterSize(var->text->sprite_bool, 50);
    sfText_setCharacterSize(var->text->sprites, 50);
    sfText_setColor(var->text->sprite_bool, color);
    sfText_setColor(var->text->sprites, sfYellow);
    sfText_setFont(var->text->sprite_bool, var->text->font);
    sfText_setFont(var->text->sprites, var->text->font);
    sfText_setOutlineThickness(var->text->sprite_bool, 5.0f);
    sfText_setOutlineThickness(var->text->sprites, 5.0f);
    sfText_setPosition(var->text->sprite_bool, (sfVector2f){1075.0f, 10.0f});
    sfText_setPosition(var->text->sprites, (sfVector2f){795.0f, 10.0f});
    sfText_setString(var->text->sprite_bool, string);
    sfText_setString(var->text->sprites, "Sprites (S) :");
    sfRenderWindow_drawText(var->window, var->text->sprites, NULL);
    sfRenderWindow_drawText(var->window, var->text->sprite_bool, NULL);
}

void display_usage_shape(var_t *var)
{
    sfColor color = var->display_shape ? sfGreen : sfRed;
    const char *string = var->display_shape ? "ON" : "OFF";

    sfText_setCharacterSize(var->text->shape_bool, 50);
    sfText_setCharacterSize(var->text->sprites, 50);
    sfText_setColor(var->text->shape_bool, color);
    sfText_setColor(var->text->sprites, sfYellow);
    sfText_setFont(var->text->shape_bool, var->text->font);
    sfText_setFont(var->text->sprites, var->text->font);
    sfText_setOutlineThickness(var->text->shape_bool, 5.0f);
    sfText_setOutlineThickness(var->text->sprites, 5.0f);
    sfText_setPosition(var->text->shape_bool, (sfVector2f){1485.0f, 10.0f});
    sfText_setPosition(var->text->sprites, (sfVector2f){1200.0f, 10.0f});
    sfText_setString(var->text->shape_bool, string);
    sfText_setString(var->text->sprites, "Shapes (L) :");
    sfRenderWindow_drawText(var->window, var->text->sprites, NULL);
    sfRenderWindow_drawText(var->window, var->text->shape_bool, NULL);
}
