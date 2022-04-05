/*
** EPITECH PROJECT, 2020
** init_pause.c
** File description:
** function to init the pause struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

pause_t *create_sprites_pause(pause_t *pause)
{
    pause->pause_sprite[0] =
            create_object("img/starting_menu/launch_screen.jpg",
            (sfVector2f){0, 0},
            (sfIntRect){0, 0, 1920, 1080});
    pause->pause_sprite[1] = create_object("img/pause/resume.png",
            (sfVector2f){955 - (510 / 2), 500 - (110 / 2)},
            (sfIntRect){0, 0, 510, 110});
    pause->pause_sprite[2] = create_object("img/pause/quit.png",
            (sfVector2f){(955 - (490 / 2)), 700 - (90 / 2)},
            (sfIntRect){0, 0, 490, 90});
    sfSprite_setTextureRect(pause->pause_sprite[1]->sprite,
            pause->pause_sprite[1]->rect);
    sfSprite_setTextureRect(pause->pause_sprite[2]->sprite,
            pause->pause_sprite[2]->rect);
    return pause;
}

pause_t *create_audio_pause_menu(pause_t *pause)
{
    pause->audio[0] = create_audio("sound/click.ogg");
    return pause;
}

pause_t *init_pause_menu_struct(void)
{
    pause_t *pause = malloc(sizeof(pause_t));
    pause->in_pause = 0;
    pause = create_sprites_pause(pause);
    pause = create_audio_pause_menu(pause);
    return pause;
}