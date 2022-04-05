/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** function to init the structs from the .h
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

sfVector2f set_cursor_on_mouse(sfRenderWindow *window, sfSprite *cursor)
{
    sfVector2f mouse;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    mouse.x = sfMouse_getPositionRenderWindow(window).x;
    mouse.y = sfMouse_getPositionRenderWindow(window).y;
    sfSprite_setPosition(cursor, mouse);
    return mouse;
}

all_t *init_all(void)
{
    all_t *all = malloc(sizeof(all_t));
    all->menu = init_menu_struct();
    all->settings = init_settings_struct();
    all->game = init_game();
    all->select = init_select_struct();
    all->pause = init_pause_menu_struct();
    all->combat = init_combat(all);
    all->inventory = init_inventory();
    all->help = init_help();
    all->death = init_death();
    all->victory = init_victory();
    all->scene = MAIN_MENU;
    return all;
}