/*
** EPITECH PROJECT, 2020
** victory.c
** File description:
** function for the vitory scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void display_victory(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawSprite(window, all->victory->objects[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->victory->objects[1]->sprite, NULL);
}

int analyse_events_victory(all_t *all, sfEvent *event)
{
    all->scene = VICTORY;
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = QUIT;
    if (event->type == sfEvtMouseMoved)
        move_cursor_victory(all, event->mouseMove);
    if (event->type == sfEvtMouseButtonPressed)
        all->scene = manage_click_victory(all, event->mouseButton);
    return all->scene;
}

int victory_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->victory->objects[1]->sprite);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->victory->audio[0]->sound, 0);
    sfMusic_play(all->victory->audio[0]->sound);
    while (all->scene == VICTORY) {
        display_victory(window, all);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            analyse_events_victory(all, &all->event);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->victory->audio[0]->sound);
    return all->scene;
}