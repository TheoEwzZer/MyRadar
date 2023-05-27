/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** init
*/

#include "my_radar.h"

sfUint32 init_line(var_t *var, char *line)
{
    char **infos = my_str_to_word_array(line);
    sfUint32 len = my_strlen_double(infos);
    if (line[0] == 'A' && len == 7)
        return init_aircraft(var, infos);
    if (line[0] == 'T' && len == 4)
        return init_tower(var, infos);
    return 84;
}

sfUint32 init_entities(var_t *var, char *script)
{
    int nbr_aircraft = number_of_entities(script, 'A');
    int nbr_tower = number_of_entities(script, 'T');

    if (nbr_aircraft <= 0 || nbr_tower == -1)
        return 84;
    A = malloc(sizeof(aircraft_t) * ((sfUint32)nbr_aircraft + 1));
    A[nbr_aircraft] = NULL;
    T = malloc(sizeof(tower_t) * ((sfUint32)nbr_tower + 1));
    T[nbr_tower] = NULL;
    var->aircraft_arrived = 0;
    var->aircraft_nb = 0;
    var->tower_nb = 0;
    return 0;
}

void init_text(var_t *var)
{
    var->text = malloc(sizeof(text_t));
    var->text->font = sfFont_createFromFile("assets/arial.ttf");
    var->text->shape_bool = sfText_create();
    var->text->shapes = sfText_create();
    var->text->sprite_bool = sfText_create();
    var->text->sprites = sfText_create();
    var->text->corner_bool = sfText_create();
    var->text->corners = sfText_create();
    var->text->timer = sfText_create();
}

var_t *init(char *script)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 24};
    var_t *var = malloc(sizeof(var_t));

    if (init_entities(var, script) == 84 || analyse_line(var, script) == 84)
        return NULL;
    init_corner(var);
    init_sprite(var);
    init_text(var);
    var->window = sfRenderWindow_create(mode, "My Radar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(var->window, 30);
    var->clock = sfClock_create();
    var->display_corner = sfTrue;
    var->display_shape = sfTrue;
    var->display_sprite = sfTrue;
    var->time = sfClock_create();
    var->pause = sfFalse;
    var->pause_t = sfClock_getElapsedTime(var->time);
    return var;
}

void init_sprite(var_t *var)
{
    sfTexture *texture = sfTexture_createFromFile("assets/bg.png", NULL);

    for (int i = 0; i < var->aircraft_nb; i++)
        A[i]->sprite_aircraft = set_aircraft_sprite(var, A[i]);
    for (int i = 0; i < var->tower_nb; i++)
        T[i]->sprite_tower = set_tower_sprite(T[i]);
    var->background = sfSprite_create();
    sfSprite_setTexture(var->background, texture, sfTrue);
}
