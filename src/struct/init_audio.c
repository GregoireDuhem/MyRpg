/*
** EPITECH PROJECT, 2020
** init_audio.c
** File description:
** function to init an audio_t struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

t_audio *create_audio(char const *path)
{
    t_audio *audio = malloc(sizeof(t_audio));
    audio->sound = sfMusic_createFromFile(path);
    return audio;
}