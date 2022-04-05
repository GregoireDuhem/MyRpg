/*
** EPITECH PROJECT, 2020
** animation_pause.c
** File description:
** function for the pause buttons
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void button_animation_resume(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset1 = {0, 0, 510, 110};
    sfIntRect offset2 = {0, 110, 510, 110};

    if ((cursor_pos.x >= all->pause->pause_sprite[1]->position.x &&
        cursor_pos.x <= all->pause->pause_sprite[1]->position.x + 510) &&
        (cursor_pos.y >= all->pause->pause_sprite[1]->position.y &&
            cursor_pos.y <= all->pause->pause_sprite[1]->position.y + 110))
        sfSprite_setTextureRect(all->pause->pause_sprite[1]->sprite, offset2);
    else
        sfSprite_setTextureRect(all->pause->pause_sprite[1]->sprite, offset1);
}

void button_animation_quit_pause(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset1 = {0, 0, 490, 90};
    sfIntRect offset2 = {0, 90, 490, 90};

    if ((cursor_pos.x >= all->pause->pause_sprite[2]->position.x &&
        cursor_pos.x <= all->pause->pause_sprite[2]->position.x + 490) &&
        (cursor_pos.y >= all->pause->pause_sprite[2]->position.y &&
            cursor_pos.y <= all->pause->pause_sprite[2]->position.y + 90)) {
        sfSprite_setTextureRect(all->pause->pause_sprite[2]->sprite, offset2);
        all->pause->pause_sprite[2]->rect = offset2;
    } else {
        sfSprite_setTextureRect(all->pause->pause_sprite[2]->sprite, offset1);
        all->pause->pause_sprite[2]->rect = offset1;
    }
}

void change_button_resume(all_t *all, sfMouseButtonEvent event)
{
    sfIntRect offset2 = {0, 220, 510, 110};
    sfVector2f vector_play = sfSprite_getPosition(
        all->pause->pause_sprite[1]->sprite);

    if (event.y > vector_play.y && event.y < (vector_play.y + 110) &&
        event.x > vector_play.x && event.x < (vector_play.x + 510)) {
        sfSprite_setTextureRect(all->pause->pause_sprite[1]->sprite, offset2);
        all->pause->pause_sprite[1]->rect = offset2;
    }
}

void change_button_quit(all_t *all, sfMouseButtonEvent event)
{
    sfIntRect offset2 = {0, 180, 490, 90};
    sfVector2f vector_quit = sfSprite_getPosition(
        all->pause->pause_sprite[2]->sprite);

    if (event.y > vector_quit.y && event.y < (vector_quit.y + 90) &&
        event.x > vector_quit.x && event.x < (vector_quit.x + 490)) {
        sfSprite_setTextureRect(all->pause->pause_sprite[2]->sprite, offset2);
        all->pause->pause_sprite[2]->rect = offset2;
    }
}

void button_animation_pause(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f cursor_pos;
    cursor_pos.y = (float)moveEvent.y;
    cursor_pos.x = (float)moveEvent.x;
    button_animation_resume(all, cursor_pos);
    button_animation_quit_pause(all, cursor_pos);
}
