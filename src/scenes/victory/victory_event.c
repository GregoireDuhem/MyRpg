/*
** EPITECH PROJECT, 2020
** victory_event.c
** File description:
** event for the victory scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void move_cursor_victory(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float)moveEvent.y;
    vector2F.x = (float)moveEvent.x;
    sfSprite_setPosition(all->victory->objects[1]->sprite, vector2F);
}

int manage_click_victory(all_t *all, sfMouseButtonEvent event)
{
    int i = VICTORY;

    sfMusic_stop(all->victory->audio[1]->sound);
    sfMusic_play(all->victory->audio[1]->sound);
    if (event.y > 700 && event.y < 820
        && event.x > 180 && event.x < 740)
        i = GAME;
    if (event.y > 650 && event.y < 885
        && event.x > 1300 && event.x < 1540)
        i = MAIN_MENU;
    return i;
}