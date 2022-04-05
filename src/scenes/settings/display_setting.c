/*
** EPITECH PROJECT, 2020
** display_setting.c
** File description:
** function to display the setting assets
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void display_setting_sprites(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawSprite(window, all->settings->objects[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[3]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[5]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[6]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[7]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[8]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->settings->objects[1]->sprite, NULL);
}