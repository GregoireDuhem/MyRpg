/*
** EPITECH PROJECT, 2020
** death_event.c
** File description:
** function for the death scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void move_cursor_death(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float)moveEvent.y;
    vector2F.x = (float)moveEvent.x;
    sfSprite_setPosition(all->death->objects[1]->sprite, vector2F);
}

int manage_click_death(all_t *all, sfMouseButtonEvent event)
{
    int i = DEATH;

    sfMusic_stop(all->death->audio[1]->sound);
    sfMusic_play(all->death->audio[1]->sound);
    if (event.y > 685 && event.y < 810
        && event.x > 200 && event.x < 775)
        i = GAME;
    if (event.y > 640 && event.y < 880
        && event.x > 1315 && event.x < 1555)
        i = MAIN_MENU;
    return i;
}