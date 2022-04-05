/*
** EPITECH PROJECT, 2019
** my_rpg.h
** File description:
** dot_h for the my_rpg project
*/

#ifndef MY_RPG_STRUCT_H_
#define MY_RPG_STRUCT_H_

#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct objects
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
} t_ob;

typedef struct audio
{
    sfMusic *sound;
} t_audio;

typedef struct Time
{
    sfClock *clock;
    sfTime timer;
    float second;
} t_time;


// STRUCT WE WILL USE
/*
typedef struct Text
{
}t_text;


*/

typedef struct victory
{
    t_ob *objects[2];
    t_audio *audio[2];
} victory_t;

typedef struct death
{
    t_ob *objects[2];
    t_audio *audio[2];
    int light_on;
} death_t;

typedef struct enemy
{
    int life_enemy;
    int attack;
    sfText *text_enemy_life;
} enemy_t;

typedef struct stats
{
    int life;
    int life_max;
    int defense;
    int attack;
    int level;
    sfText *text_life;
} stats_t;

typedef struct help
{
    t_ob *objects[4];
    int slide;
} help_t;

typedef struct combat
{
    t_ob *enemy[11];
    t_ob *objects[4];
    t_audio *audio[2];
    stats_t *stat;
    enemy_t *enemy_stats;
    int **enemy_stat_array;
    sfText *mage_1;
    sfText *mage_2;
    sfText *mage_3;
    sfText *warrior_1;
    sfText *warrior_2;
    sfText *warrior_3;
    int cooldown_ult;
    int cooldown_buff;
} combat_t;

typedef struct inventory
{
    t_ob *objects[6];
    t_audio *audio[1];
    int inventory_value;
    sfText *health;
    sfText *def;
    sfText *att;
    sfText *lvl;
    sfText *pt_health;
    sfText *pt_def;
    sfText *pt_att;
    sfText *nb_lvl;
    char *str;
    char *str2;
    char *str3;
    int eat;
    int shield;
} inventory_t;

typedef struct pause
{
    t_ob *pause_sprite[3];
    t_audio *audio[1];
    int in_pause;
}pause_t;

typedef struct settings
{
    t_ob *objects[8];
    sfFont *font;
    sfFont *fontopt;
    int nb_sfx;
    int nb_mus;
    int i;
    int j;
    int k;
    int l;
    char *str;
    char *str2;
    sfText *sfx_nb;
    sfText *mus_nb;
}settings_t;

typedef struct menu
{
    t_ob *objects[6];
    t_audio *audio[2];
}menu_t;

typedef struct game
{
    t_ob *objects[6];
    t_ob *dialog[3];
    t_audio *audio[2];
    sfImage *hitbox;
    int character_move;
    int value;
    sfClock *anim;
    sfTime time;
    float seconds;
    int xp_bar;
    int diag_value;
    sfClock *clock;
}game_t;

typedef struct select
{
    t_ob *objects[3];
    t_audio *audio[2];
    int i;
    int k;
}select_t;

typedef struct all
{
    menu_t *menu;
    settings_t *settings;
    game_t *game;
    select_t *select;
    pause_t *pause;
    combat_t *combat;
    inventory_t *inventory;
    help_t *help;
    death_t *death;
    victory_t  *victory;
    sfEvent event;
    int scene;
}all_t;

#endif /* MY_RPG_STRUCT_H_ */
