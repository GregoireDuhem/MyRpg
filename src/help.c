/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** file for the help function
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void display_help_sprites(sfRenderWindow *window, all_t *all)
{
    if (all->help->slide != 4)
        sfRenderWindow_drawSprite(window,
            all->help->objects[all->help->slide]->sprite, NULL);
}

int analyse_events_help(all_t *all, sfEvent *event)
{
    int scene = HELP;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        scene = QUIT;
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyRight &&
        all->help->slide < 4)
        all->help->slide += 1;
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyLeft &&
        all->help->slide > 0)
        all->help->slide -= 1;
    return scene;
}

int help_main(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    all->help->slide = 0;
    sfMusic_play(all->menu->audio[0]->sound);
    while (all->scene == HELP) {
        sfRenderWindow_display(window);
        display_help_sprites(window, all);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            all->scene = analyse_events_help(all, &all->event);
        }
        if (all->help->slide == 4)
            all->scene = MAIN_MENU;
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->menu->audio[0]->sound);
    return all->scene;
}