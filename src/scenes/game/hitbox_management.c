/*
** EPITECH PROJECT, 2020
** display the game
** File description:
** hitbox_management.c
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int go_left(all_t *all)
{
    sfColor get_color;
    int i = 0;
    int count = 0;

    while (i < 2) {
        get_color = sfImage_getPixel(all->game->hitbox,
            2474 + all->game->objects[0]->rect.left - 6,
            3514 + all->game->objects[0]->rect.top + i);
        count = passeable(get_color, count);
        i++;
    }
    return count + 1;
}

int go_right(all_t *all)
{
    sfColor get_color;
    int i = 0;
    int count = 0;

    while (i < 2) {
        get_color = sfImage_getPixel(all->game->hitbox,
            all->game->objects[0]->rect.left + 2474 + 32,
            all->game->objects[0]->rect.top + 3514 + i);
        count = passeable(get_color, count);
        i++;
    }
    return count + 1;
}

int go_down(all_t *all)
{
    sfColor get_color;
    int i = 0;
    int count = 0;

    while (i < 22) {
        get_color = sfImage_getPixel(all->game->hitbox,
            all->game->objects[0]->rect.left + 2474 + i,
            all->game->objects[0]->rect.top + 3494 + 32);
        count = passeable(get_color, count);
        i++;
    }
    return count + 1;
}

int go_up(all_t *all)
{
    sfColor get_color;
    int i = 0;
    int count = 0;

    while (i < 22) {
        get_color = sfImage_getPixel(all->game->hitbox,
            all->game->objects[0]->rect.left + 2474 + i,
            all->game->objects[0]->rect.top + 3494 + 6);
        count = passeable(get_color, count);
        i++;
    }
    return count + 1;
}

void anim_character(all_t *all)
{
    static int i = 1;

    choose_color_anim(all);
    if (all->game->value == 96 || all->game->value == 240 ||
        all->game->value == 384 || all->game->value == 528)
        i = -1;
    if (all->game->value == 0 || all->game->value == 144 ||
        all->game->value == 288 || all->game->value == 432)
        i = 1;
    all->game->time = sfClock_getElapsedTime(all->game->anim);
    all->game->seconds = all->game->time.microseconds / 1000000.0;
    if (all->game->seconds > 0.35)
    {
        all->game->value += 48 * i;
        sfClock_restart(all->game->anim);
    }
}