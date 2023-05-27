/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main
*/

#include "my_radar.h"

void analyse_events(var_t *var, sfEvent event)
{
    while (sfRenderWindow_pollEvent(var->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(var->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(var->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
            var->display_shape = !var->display_shape;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            var->display_sprite = !var->display_sprite;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
            var->display_corner = !var->display_corner;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            var->pause_t = sfClock_getElapsedTime(var->time);
            var->pause = !var->pause;
        }
    }
}

void check_all_collisions(var_t *var)
{
    for (int i = 0; i < var->aircraft_nb; i++) {
        if (A[i])
            check_collisions(var, i);
    }
}

void my_radar(var_t *var)
{
    sfEvent event;

    if (var->aircraft_arrived == var->aircraft_nb)
        sfRenderWindow_close(var->window);
    sfRenderWindow_clear(var->window, sfBlack);
    analyse_events(var, event);
    if (!var->pause) {
        move_clock(var);
        check_all_collisions(var);
    }
    display(var);
    display_timer(var);
    display_usage_corner(var);
    display_usage_shape(var);
    display_usage_sprite(var);
    sfRenderWindow_display(var->window);
}

sfBool error_handling(int argc, char **argv)
{
    if (argc < 2 || argc > 2) {
        write(2, "./my_radar: bad arguments: ", 28);
        my_put_nbr_error(argc - 1, 0);
        write(2, " given but 84 is required\n", 26);
        write(2, "retry with -h\n", 14);
        return 84;
    }
    if (argc == 2 && !my_strcmp(argv[1], "-h")) {
        write(1, "Air traffic simulation panel\n\n", 30);
        write(1, "USAGE\n", 6);
        write(1, " ./my_radar [OPTIONS] path_to_script\n", 37);
        write(1, "  path_to_script    The path to the script file.\n\n", 50);
        write(1, "OPTIONS\n", 8);
        write(1, " -h                print the usage and quit.\n\n", 46);
        write(1, "USER INTERACTIONS\n", 18);
        write(1, " ‘L’ key        enable/disable hitboxes and areas.\n", 55);
        write(1, " ‘S’ key        enable/disable sprites.\n", 44);
        return sfFalse;
    }
    return sfTrue;
}

int main(int argc, char **argv)
{
    var_t *var;
    int error = error_handling(argc, argv);

    srand((sfUint32)time(NULL));
    if (error == sfFalse || error == 84)
        return error;
    var = init(argv[1]);
    if (!var) {
        write(2, "./my_radar: script incorrect or not found\n", 43);
        return 84;
    }
    while (sfRenderWindow_isOpen(var->window))
        my_radar(var);
    destroy(var);
    return 0;
}
