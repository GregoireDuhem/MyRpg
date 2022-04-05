/*
** EPITECH PROJECT, 2020
** champ_select.c
** File description:
** functions for the champ selction
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void move_cursor_select(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float) moveEvent.y;
    vector2F.x = (float) moveEvent.x;
    sfSprite_setPosition(all->select->objects[1]->sprite, vector2F);
}

void manage_click_select_2(all_t *all, sfMouseButtonEvent event)
{
    if (event.y > 369 && event.y < 510 && event.x > 321 && event.x < 427)
        all->select->k = 1;
    else if (event.y > 601 && event.y < 685 && event.x > 321 && event.x < 427)
        all->select->k = 0;
    if (event.y > 868 && event.y < 1014 && event.x > 1675 && event.x < 1840)
        all->scene = GAME;
}

void manage_click_select(all_t *all, sfMouseButtonEvent event)
{
    if (event.y > 312 && event.y < 388 && event.x > 1504 && event.x < 1582)
        all->select->i = 1;
    else if (event.y > 432 && event.y < 508 && event.x > 1504 && event.x < 1582)
        all->select->i = 2;
    if (event.y > 552 && event.y < 628 && event.x > 1504 && event.x < 1582)
        all->select->i = 3;
    else if (event.y > 662 && event.y < 738 && event.x > 1504 && event.x < 1582)
        all->select->i = 4;
    manage_click_select_2(all, event);
}

int analyse_events_select(all_t *all, sfEvent *event)
{
    static int a = 0;

    if (all->select->k == 0)
        a = 0;
    if (all->select->k == 1)
        a = 50;

    select_color(all, a);
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = QUIT;
    if (event->type == sfEvtMouseButtonPressed) {
        sfMusic_play(all->select->audio[1]->sound);
        sfMusic_stop(all->select->audio[1]->sound);
        manage_click_select(all, event->mouseButton);
    }
    else if (event->type == sfEvtMouseMoved)
        move_cursor_select(all, event->mouseMove);
    return all->scene;
}

int select_main(sfRenderWindow *window, all_t *all)
{
    static int i = 0;
    sfIntRect offset1 = {0, 0, 34, 50};

    set_cursor_on_mouse(window, all->menu->objects[1]->sprite);
    sfMusic_play(all->select->audio[0]->sound);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->select->audio[0]->sound, 0);
    while (all->scene == CHAMP_SELECT) {
        if (i == 0) {
            sfSprite_setTextureRect(all->select->objects[2]->sprite, offset1);
            i = 1;
        }
        display_select_sprites(window, all);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &all->event))
            analyse_events_select(all, &all->event);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->select->audio[0]->sound);
    return all->scene;
}