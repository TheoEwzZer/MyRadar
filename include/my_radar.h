/*
** EPITECH PROJECT, 2022
** my_radar.h
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_

    #define MY_RADAR_H_

    #include "my.h"
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>

    #define A var->aircraft
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define ANB A[var->aircraft_nb]
    #define AREA tower->area
    #define HEIGHT 1080
    #define HEIGHTR rect->height
    #define HITBOX aircraft->hitbox
    #define LEFT rect->left
    #define SCALE aircraft->scale
    #define T var->tower
    #define TNB T[var->tower_nb]
    #define TOP rect->top
    #define WIDTH 1920
    #define WIDTHR rect->width

typedef struct aircraft {
    sfVector2f departure;
    sfVector2f arrival;
    float speed;
    int delay;
    sfSprite *sprite_aircraft;
    sfConvexShape *hitbox;
    float scale;
    sfUint32 zone;
    sfVector2f offset;
} aircraft_t;

typedef struct corner {
    sfIntRect *rect;
    sfRectangleShape *shape;
} corner_t;

typedef struct text {
    sfFont *font;
    sfText *shape_bool;
    sfText *shapes;
    sfText *sprite_bool;
    sfText *sprites;
    sfText *corner_bool;
    sfText *corners;
    sfText *timer;
} text_t;

typedef struct tower {
    sfVector2f coordinates;
    float radius;
    sfSprite *sprite_tower;
    sfCircleShape *area;
} tower_t;

typedef struct structure {
    aircraft_t **aircraft;
    corner_t *ne;
    corner_t *nw;
    corner_t *se;
    corner_t *sw;
    int aircraft_arrived;
    int aircraft_nb;
    int tower_nb;
    sfBool display_corner;
    sfBool display_shape;
    sfBool display_sprite;
    sfBool pause;
    sfBool resume;
    sfClock *clock;
    sfClock *time;
    sfRenderWindow *window;
    sfSprite *background;
    sfTime pause_t;
    sfTime resume_t;
    text_t *text;
    tower_t **tower;
} var_t;

double check_x(sfVector2f tower, sfVector2f aircraft, float scale);
double check_y(sfVector2f tower, sfVector2f aircraft, float scale);
float height(void);
int number_of_entities(char *script, char type);
sfBool check_in_win(sfVector2f position);
sfBool error_handling(int argc, char **argv);
sfBool intersecting_aircraft(var_t *var, int j, sfVector2f pos1, float s);
sfBool intersecting_tower(var_t *var, int j);
sfSprite *set_aircraft_sprite(var_t *var, aircraft_t *aircraft);
sfSprite *set_tower_sprite(tower_t *tower);
sfUint32 analyse_line(var_t *var, char *script);
sfUint32 init_aircraft(var_t *var, char **infos);
sfUint32 init_entities(var_t *var, char *script);
sfUint32 init_line(var_t *var, char *line);
sfUint32 init_tower(var_t *var, char **infos);
sfVector2f init_offset(var_t *var);
var_t *init(char *script);
void analyse_events(var_t *var, sfEvent event);
void change_aircraft_side(var_t *var, int i, float tmp_x, float tmp_y);
void change_destination_side(var_t *var, int i);
void check_all_collisions(var_t *var);
void check_collisions(var_t *var, int i);
void check_tower(var_t *var, int i, int j);
void crash(var_t *var, int i, int j);
void create_hitbox(aircraft_t *aircraft, sfVector2f position);
void destroy(var_t *var);
void destroy_entities(var_t *var);
void destroy_text(var_t *var);
void display(var_t *var);
void display_corner(var_t *var);
void display_timer(var_t *var);
void display_usage_corner(var_t *var);
void display_usage_shape(var_t *var);
void display_usage_sprite(var_t *var);
void init_corner(var_t *var);
void init_corner_ne(var_t *var);
void init_corner_nw(var_t *var);
void init_corner_se(var_t *var);
void init_corner_sw(var_t *var);
void init_sprite(var_t *var);
void init_text(var_t *var);
void land_on(var_t *var, int i);
void move(var_t *var);
void move2(var_t *var, int i);
void move_clock(var_t *var);
void my_radar(var_t *var);
void set_rotation(aircraft_t *aircraft, sfSprite *sprite);
void sort_aircraft(var_t *var, int left, int right);

#endif /* MY_RADAR_H_ */
