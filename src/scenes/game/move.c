/*
** EPITECH PROJECT, 2020
** display the game
** File description:
** move.c
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void move(all_t *all, sfEvent *event)
{
    anim_character(all);
    move_left(all, event);
    move_right(all, event);
    move_down(all, event);
    move_up(all, event);
}

void move_left(all_t *all, sfEvent *event)
{
    sfIntRect offset1 = {all->game->value, 48, 48, 48};
    sfIntRect offset2 = {all->game->value, 240, 48, 48};

    if (event->key.code == sfKeyQ && go_left(all) == 3) {
        all->game->objects[0]->rect.left -= 4;
        sfSprite_setTextureRect(all->game->objects[0]->sprite,
            all->game->objects[0]->rect);
        all->game->character_move = 48;
        if (all->select->k == 0)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset1);
        else if (all->select->k == 1)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset2);
    }
}

void move_right(all_t *all, sfEvent *event)
{
    sfIntRect offset1 = {all->game->value, 96, 48, 48};
    sfIntRect offset2 = {all->game->value, 288, 48, 48};

    if (event->key.code == sfKeyD && go_right(all) == 3) {
        all->game->objects[0]->rect.left += 4;
        sfSprite_setTextureRect(all->game->objects[0]->sprite,
            all->game->objects[0]->rect);
        all->game->character_move = 48;
        if (all->select->k == 0)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset1);
        else if (all->select->k == 1)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset2);
    }
}

void move_down(all_t *all, sfEvent *event)
{
    sfIntRect offset1 = {all->game->value, 0, 48, 48};
    sfIntRect offset2 = {all->game->value, 192, 48, 48};

    if (event->key.code == sfKeyS && go_down(all) == 23) {

        all->game->objects[0]->rect.top += 4;
        sfSprite_setTextureRect(all->game->objects[0]->sprite,
            all->game->objects[0]->rect);
        all->game->character_move = 48;
        if (all->select->k == 0)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset1);
        else if (all->select->k == 1)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset2);
    }
}

void move_up(all_t *all, sfEvent *event)
{
    sfIntRect offset1 = {all->game->value, 144, 48, 48};
    sfIntRect offset2 = {all->game->value, 336, 48, 48};

    if (event->key.code == sfKeyZ && go_up(all) == 23) {
        all->game->objects[0]->rect.top -= 4;
        sfSprite_setTextureRect(all->game->objects[0]->sprite,
            all->game->objects[0]->rect);
        all->game->character_move = 48;
        if (all->select->k == 0)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset1);
        else if (all->select->k == 1)
            sfSprite_setTextureRect(all->game->objects[1]->sprite, offset2);
    }
}
