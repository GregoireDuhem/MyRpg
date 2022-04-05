/*
** EPITECH PROJECT, 2020
** option2.c
** File description:
** files for the starting setting scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void draw_option2(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawText(window, all->settings->sfx_nb, NULL);
    sfRenderWindow_drawText(window, all->settings->mus_nb, NULL);
}

void draw_option_mute(all_t *all)
{
    if (all->settings->i == 1) {
        sfText_setString(all->settings->sfx_nb, "0");
        sfText_setPosition(all->settings->sfx_nb, (sfVector2f){1130, 415});
    }
    if (all->settings->k == 1) {
        sfText_setString(all->settings->mus_nb, "0");
        sfText_setPosition(all->settings->mus_nb, (sfVector2f){1130, 515});
    }
    if (all->settings->i == 2) {
        sfText_setString(all->settings->sfx_nb, all->settings->str);
    }
    if (all->settings->k == 2) {
        sfText_setString(all->settings->mus_nb, all->settings->str2);
    }
}

void event_option(sfRenderWindow *window, all_t *all)
{
    while (sfRenderWindow_pollEvent(window, &all->event)) {
        mute_gestion(all);
    }
}

void option(sfRenderWindow *window, all_t *all)
{
    event_option(window, all);
    sfx_gestion(all);
    mus_gestion(all);
    draw_option_mute(all);
    draw_option2(window, all);
}