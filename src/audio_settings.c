/*
** EPITECH PROJECT, 2020
** audio_settings.c
** File description:
** setting the audio throughout the game
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void set_loop_all(all_t *all)
{
    sfMusic_setLoop(all->menu->audio[0]->sound, sfTrue);
    sfMusic_setLoop(all->game->audio[0]->sound, sfTrue);
    sfMusic_setLoop(all->select->audio[0]->sound, sfTrue);
    sfMusic_setLoop(all->pause->audio[0]->sound, sfTrue);
    sfMusic_setLoop(all->combat->audio[0]->sound, sfTrue);
    sfMusic_setLoop(all->victory->audio[0]->sound, sfTrue);
}

void set_all_mute(all_t *all)
{
    sfMusic_setVolume(all->menu->audio[0]->sound, 0);
    sfMusic_setVolume(all->game->audio[0]->sound, 0);
    sfMusic_setVolume(all->select->audio[0]->sound, 0);
    sfMusic_setVolume(all->pause->audio[0]->sound, 0);
    sfMusic_setVolume(all->combat->audio[0]->sound, 0);
    sfMusic_setVolume(all->death->audio[0]->sound, 0);
    sfMusic_setVolume(all->victory->audio[0]->sound, 0);
}

void set_volume_all(all_t *all)
{
    sfMusic_setVolume(all->menu->audio[0]->sound, all->settings->nb_mus);
    sfMusic_setVolume(all->game->audio[0]->sound, all->settings->nb_mus);
    sfMusic_setVolume(all->select->audio[0]->sound, all->settings->nb_mus);
    sfMusic_setVolume(all->pause->audio[0]->sound, all->settings->nb_mus);
    sfMusic_setVolume(all->combat->audio[0]->sound, all->settings->nb_mus);
    sfMusic_setVolume(all->death->audio[0]->sound, all->settings->nb_mus);
    sfMusic_setVolume(all->victory->audio[0]->sound, all->settings->nb_mus);
}

void audio_settings(all_t *all)
{
    set_loop_all(all);
    if (all->settings->k == 1)
        set_all_mute(all);
    else
        set_volume_all(all);
}