/*
** EPITECH PROJECT, 2020
** init_menu.c
** File description:
** init the assets for the menu
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

menu_t *create_audio_menu(menu_t *menu)
{
    menu->audio[0] = create_audio("sound/celestial.ogg");
    menu->audio[1] = create_audio("sound/click.ogg");
    return menu;
}

menu_t *set_rect_menu(menu_t *menu)
{
    sfSprite_setTextureRect(menu->objects[2]->sprite,
            (sfIntRect){0, 0, 444, 180});
    sfSprite_setTextureRect(menu->objects[4]->sprite,
            (sfIntRect){0, 0, 444, 180});
    sfSprite_setTextureRect(menu->objects[3]->sprite,
            (sfIntRect){0, 0, 444, 180});
    return menu;
}

menu_t *create_sprites_menu(menu_t *menu)
{
    menu->objects[0] = create_object("img/starting_menu/launch_screen.jpg",
            (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0});
    menu->objects[1] = create_object("img/starting_menu/cursor.png",
            (sfVector2f){10, 10}, (sfIntRect){0, 0, 0, 0});
    menu->objects[2] = create_object("img/starting_menu/play.png",
            (sfVector2f){750, 400}, (sfIntRect){0, 0, 444, 180});
    menu->objects[3] = create_object("img/starting_menu/help.png",
            (sfVector2f){750, 550}, (sfIntRect){0, 0, 444, 180});
    menu->objects[4] = create_object("img/starting_menu/quit.png",
            (sfVector2f){750, 740}, (sfIntRect){0, 0, 444, 180});
    menu->objects[5] = create_object("img/starting_menu/settings.png",
            (sfVector2f){1600, 750}, (sfIntRect){0, 0, 0, 0});
    menu = set_rect_menu(menu);
    return menu;
}

menu_t *init_menu_struct(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu = create_audio_menu(menu);
    menu = create_sprites_menu(menu);
    return menu;
}