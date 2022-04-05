/*
** EPITECH PROJECT, 2020
** option.c
** File description:
** files for the starting setting scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void sfx_gestion(all_t *all)
{
    all->settings->str = my_itoa(all->settings->nb_sfx);
    sfText_setFont(all->settings->sfx_nb, all->settings->fontopt);
    sfText_setCharacterSize(all->settings->sfx_nb, 50);
    sfText_setColor(all->settings->sfx_nb, sfWhite);
    if (all->settings->nb_sfx >= 0 && all->settings->nb_sfx <= 9)
        sfText_setPosition(all->settings->sfx_nb, (sfVector2f){1130, 415});
    else if (all->settings->nb_sfx == 100)
        sfText_setPosition(all->settings->sfx_nb, (sfVector2f){1110, 415});
    else
        sfText_setPosition(all->settings->sfx_nb, (sfVector2f){1120, 415});
}

void set_volume_music(all_t *all)
{
    if (all->settings->k == 2)
        sfMusic_setVolume(all->menu->audio[0]->sound, all->settings->nb_mus);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->menu->audio[0]->sound, 0);
}

void mus_gestion(all_t *all)
{
    all->settings->str2 = my_itoa(all->settings->nb_mus);
    sfText_setFont(all->settings->mus_nb, all->settings->fontopt);
    sfText_setCharacterSize(all->settings->mus_nb, 50);
    sfText_setColor(all->settings->mus_nb, sfWhite);
    if (all->settings->nb_mus >= 0 && all->settings->nb_mus <= 9)
        sfText_setPosition(all->settings->mus_nb, (sfVector2f){1130, 515});
    else if (all->settings->nb_mus == 100)
        sfText_setPosition(all->settings->mus_nb, (sfVector2f){1110, 515});
    else
        sfText_setPosition(all->settings->mus_nb, (sfVector2f){1120, 515});
    set_volume_music(all);
}