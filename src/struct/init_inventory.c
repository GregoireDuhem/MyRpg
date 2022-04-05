/*
** EPITECH PROJECT, 2020
** init_inventory.c
** File description:
** functions to init the inventory struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void create_audio_inventory(inventory_t *inventory)
{
    inventory->audio[0] = create_audio("sound/click.ogg");
}

void create_sprites_inventory(inventory_t *inventory)
{
    inventory->objects[0] = create_object("img/Overlay/inventory.png",
            (sfVector2f){0, 0},
            (sfIntRect){0, 0, 0, 0});
    inventory->objects[1] = create_object("img/character/select_hero.png",
            (sfVector2f){300, 300},
            (sfIntRect){0, 0, 0, 0});
    inventory->objects[2] = create_object("img/starting_menu/cursor.png",
            (sfVector2f){0, 0},
            (sfIntRect){0, 0, 10, 10});
    inventory->objects[3] = create_object("img/map/map_RPG.png",
            (sfVector2f){0, 0},
            (sfIntRect){2000, 2000, 1920, 1080});
    sfSprite_setTextureRect(inventory->objects[3]->sprite,
        inventory->objects[3]->rect);
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    create_sprites_inventory(inventory);
    create_audio_inventory(inventory);
    inventory->health = sfText_create();
    inventory->def = sfText_create();
    inventory->att = sfText_create();
    inventory->pt_health = sfText_create();
    inventory->pt_def = sfText_create();
    inventory->pt_att = sfText_create();
    inventory->lvl = sfText_create();
    inventory->nb_lvl = sfText_create();
    inventory->inventory_value = 0;
    inventory->eat = 0;
    inventory->shield = 0;
    return inventory;
}