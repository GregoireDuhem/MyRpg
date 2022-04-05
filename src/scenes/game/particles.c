/*
** EPITECH PROJECT, 2020
** display the game
** File description:
** particles.c
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int passeable(sfColor get_color, int count)
{
    if ((get_color.a == sfWhite.a && get_color.r == sfWhite.r &&
        get_color.g == sfWhite.g && get_color.b == sfWhite.b) ||
        (get_color.a == sfRed.a && get_color.r == sfRed.r &&
            get_color.g == sfRed.g && get_color.b == sfRed.b))
        count++;
    return (count);
}

void draw_particles(sfRenderWindow *window, all_t *all)
{
    if (all->combat->stat->level >= 5 && all->combat->stat->level < 10) {
        sfRenderWindow_drawSprite(window, all->game->objects[4]->sprite, NULL);
        all->game->objects[4]->rect.top = 0;
    }
    if (all->combat->stat->level >= 10) {
        sfRenderWindow_drawSprite(window, all->game->objects[4]->sprite, NULL);
        all->game->objects[4]->rect.top = 672;
    }
}

void animation(all_t *all)
{
    float seconds = all->game->time.microseconds / 1000000.0;
    static int repeat = 0;

    if (seconds > 0.1 && repeat == 0) {
        particles(all);
        repeat = 1;
    } else if (seconds > 0.2) {
        particles(all);
        repeat = 0;
        sfClock_restart(all->game->clock);
    }
}

void particles(all_t *all)
{
    if (all->game->objects[4]->rect.left == 1134)
        all->game->objects[4]->rect.left = 0;
    else
        all->game->objects[4]->rect.left += 126;
    sfSprite_setTextureRect(all->game->objects[4]->sprite,
        all->game->objects[4]->rect);
}