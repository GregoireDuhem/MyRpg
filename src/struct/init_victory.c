/*
** EPITECH PROJECT, 2020
** init_victory.c
** File description:
** function to init the victory struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

victory_t *create_audio_victory(victory_t *victory)
{
    victory->audio[0] = create_audio("sound/menu_back.ogg");
    victory->audio[1] = create_audio("sound/click.ogg");
    return victory;
}

victory_t *create_sprites_victory(victory_t *victory)
{
    victory->objects[0] = create_object("img/Overlay/you_win.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    victory->objects[1] = create_object("img/starting_menu/cursor.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 10, 10});
    return victory;
}

victory_t *init_victory(void)
{
    victory_t *victory = malloc(sizeof(victory_t));

    victory = create_audio_victory(victory);
    victory = create_sprites_victory(victory);
    return victory;
}