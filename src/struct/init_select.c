/*
** EPITECH PROJECT, 2020
** init_select.c
** File description:
** init the assets for the select menu
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void create_audio_select(select_t *select)
{
    select->audio[0] = create_audio("sound/celestial.ogg");
    select->audio[1] = create_audio("sound/click.ogg");
}

select_t *create_sprites_select(select_t *select)
{
    select->objects[0] = create_object("img/Overlay/select_screen.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0});
    select->objects[1] = create_object("img/starting_menu/cursor.png",
        (sfVector2f){10, 10}, (sfIntRect){0, 0, 0, 0});
    select->objects[2] = create_object("img/character/select_hero.png",
        (sfVector2f){1270, 410}, (sfIntRect){0, 0, 0, 0});
    return select;
}

select_t *init_select_struct(void)
{
    select_t *select = malloc(sizeof(select_t));

    select = create_sprites_select(select);
    create_audio_select(select);
    select->i = 0;
    select->k = 0;
    return select;
}