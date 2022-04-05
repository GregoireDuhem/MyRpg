/*
** EPITECH PROJECT, 2020
** button_animation.c
** File description:
** file for the button animation
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void button_animation_down_sfx(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset3 = {0, 80, 72, 65};
    sfIntRect offset2 = {0, 0, 72, 65};

    if ((cursor_pos.x >= all->settings->objects[4]->position.x
        && cursor_pos.x <= all->settings->objects[4]->position.x + 72)
        && (cursor_pos.y >= all->settings->objects[4]->position.y
            && cursor_pos.y <= all->settings->objects[4]->position.y + 65))
        sfSprite_setTextureRect(all->settings->objects[4]->sprite, offset3);

    else
        sfSprite_setTextureRect(all->settings->objects[4]->sprite, offset2);
}

void button_animation_down_mu(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset3 = {0, 80, 72, 65};
    sfIntRect offset2 = {0, 0, 72, 65};

    if ((cursor_pos.x >= all->settings->objects[5]->position.x
        && cursor_pos.x <= all->settings->objects[5]->position.x + 72)
        && (cursor_pos.y >= all->settings->objects[5]->position.y
        && cursor_pos.y <= all->settings->objects[5]->position.y + 65))
        sfSprite_setTextureRect(all->settings->objects[5]->sprite, offset3);

    else
        sfSprite_setTextureRect(all->settings->objects[5]->sprite, offset2);
}

void button_animation_up_sfx(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset1 = {0, 80, 72, 65};
    sfIntRect offset2 = {0, 0, 72, 65};

    if ((cursor_pos.x >= all->settings->objects[2]->position.x
        && cursor_pos.x <= all->settings->objects[2]->position.x + 72)
        && (cursor_pos.y >= all->settings->objects[2]->position.y
            && cursor_pos.y <= all->settings->objects[2]->position.y + 65))
        sfSprite_setTextureRect(all->settings->objects[2]->sprite, offset1);

    else
        sfSprite_setTextureRect(all->settings->objects[2]->sprite, offset2);
}

void button_animation_up_mu(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset1 = {0, 80, 72, 65};
    sfIntRect offset2 = {0, 0, 72, 65};

    if ((cursor_pos.x >= all->settings->objects[3]->position.x
        && cursor_pos.x <= all->settings->objects[3]->position.x + 72)
        && (cursor_pos.y >= all->settings->objects[3]->position.y
        && cursor_pos.y <= all->settings->objects[3]->position.y + 65))
        sfSprite_setTextureRect(all->settings->objects[3]->sprite, offset1);

    else
        sfSprite_setTextureRect(all->settings->objects[3]->sprite, offset2);
}