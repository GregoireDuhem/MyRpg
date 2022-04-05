/*
** EPITECH PROJECT, 2020
** init_sprites.c
** File description:
** function to init a t_ob struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

t_ob *create_object(char const *path, sfVector2f mouv, sfIntRect rect)
{
    t_ob *objects = malloc(sizeof(t_ob));
    objects->texture = sfTexture_createFromFile(path, NULL);
    objects->sprite = sfSprite_create();
    objects->position = mouv;
    objects->rect = rect;
    sfSprite_setPosition(objects->sprite, objects->position);
    sfSprite_setTexture(objects->sprite, objects->texture, sfTrue);
    return objects;
}