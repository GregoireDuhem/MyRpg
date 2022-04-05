/*
** EPITECH PROJECT, 2020
** button_animation.c
** File description:
** file for the button animation
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void button_animation_quit(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset3 = {0, 195, 444, 180};
    sfIntRect offset2 = {0, 0, 444, 180};

    if ((cursor_pos.x >= all->menu->objects[4]->position.x &&
        cursor_pos.x <= all->menu->objects[4]->position.x + 444) &&
        (cursor_pos.y >= all->menu->objects[4]->position.y &&
            cursor_pos.y <= all->menu->objects[4]->position.y + 180))
        sfSprite_setTextureRect(all->menu->objects[4]->sprite, offset3);
    else
        sfSprite_setTextureRect(all->menu->objects[4]->sprite, offset2);
}

void button_animation_help(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset3 = {0, 195, 444, 180};
    sfIntRect offset2 = {0, 0, 444, 180};

    if ((cursor_pos.x >= all->menu->objects[3]->position.x &&
        cursor_pos.x <= all->menu->objects[3]->position.x + 444) &&
        (cursor_pos.y >= all->menu->objects[3]->position.y &&
            cursor_pos.y <= all->menu->objects[3]->position.y + 180))
        sfSprite_setTextureRect(all->menu->objects[3]->sprite, offset3);
    else
        sfSprite_setTextureRect(all->menu->objects[3]->sprite, offset2);
}

void button_animation_play(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset1 = {0, 195, 444, 180};
    sfIntRect offset2 = {0, 0, 444, 180};

    if ((cursor_pos.x >= all->menu->objects[2]->position.x &&
        cursor_pos.x <= all->menu->objects[2]->position.x + 444) &&
        (cursor_pos.y >= all->menu->objects[2]->position.y &&
            cursor_pos.y <= all->menu->objects[2]->position.y + 180))
        sfSprite_setTextureRect(all->menu->objects[2]->sprite, offset1);
    else
        sfSprite_setTextureRect(all->menu->objects[2]->sprite, offset2);
}

void button_animation(all_t *all, sfVector2f cursor_pos)
{
    button_animation_play(all, cursor_pos);
    button_animation_help(all, cursor_pos);
    button_animation_quit(all, cursor_pos);
}