/*
** EPITECH PROJECT, 2020
** display_select.c
** File description:
** function to display the select assets
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void select_color(all_t *all, int a)
{
    sfIntRect offset1 = {0, a, 34, 50};
    sfIntRect offset2 = {34, a, 34, 50};
    sfIntRect offset3 = {68, a, 34, 50};
    sfIntRect offset4 = {102, a, 34, 50};

    if (all->select->i == 0)
        sfSprite_setTextureRect(all->select->objects[2]->sprite, offset1);
    if (all->select->i == 1)
        sfSprite_setTextureRect(all->select->objects[2]->sprite, offset1);
    if (all->select->i == 2)
        sfSprite_setTextureRect(all->select->objects[2]->sprite, offset2);
    if (all->select->i == 3)
        sfSprite_setTextureRect(all->select->objects[2]->sprite, offset3);
    if (all->select->i == 4)
        sfSprite_setTextureRect(all->select->objects[2]->sprite, offset4);
}

void display_select_sprites(sfRenderWindow *window, all_t *all)
{
    sfSprite_setPosition(all->select->objects[2]->sprite,
        (sfVector2f){900, 540});
    sfSprite_setScale(all->select->objects[2]->sprite, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(window, all->select->objects[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->select->objects[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->select->objects[1]->sprite, NULL);
}