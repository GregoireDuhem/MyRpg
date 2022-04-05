/*
** EPITECH PROJECT, 2020
** death.c
** File description:
** main file for the death scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void display_death(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawSprite(window, all->death->objects[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->death->objects[1]->sprite, NULL);
}

int analyse_events_death(all_t *all, sfEvent *event)
{
    all->scene = DEATH;
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = QUIT;
    all->death->light_on = 0;
    if (event->type == sfEvtMouseMoved)
        move_cursor_death(all, event->mouseMove);
    if (event->type == sfEvtMouseButtonPressed)
        all->scene = manage_click_death(all, event->mouseButton);
    return all->scene;
}

int death_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->death->objects[1]->sprite);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->death->audio[0]->sound, 0);
    sfMusic_play(all->death->audio[0]->sound);
    while (all->scene == DEATH) {
        display_death(window, all);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            analyse_events_death(all, &all->event);
        }
    }
    all->combat->stat->life = all->combat->stat->life_max;
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->death->audio[0]->sound);
    return all->scene;
}