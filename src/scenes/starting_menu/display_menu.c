/*
** EPITECH PROJECT, 2020
** display_menu.c
** File description:
** function to display the menu assets
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void display_menu_sprites(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawSprite(window, all->menu->objects[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->menu->objects[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->menu->objects[3]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->menu->objects[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->menu->objects[5]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->menu->objects[1]->sprite, NULL);
}