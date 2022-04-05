/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** main fuction for the game scene
*/

#include "my_rpg_struct.h"
#include "my_rpg.h"
#include "my.h"

int is_dialog(all_t *all)
{
    if (all->game->diag_value == 0) {
        all->game->diag_value = 1;
        return (0);
    }
    if (all->game->diag_value == 1) {
        all->game->diag_value = 0;
        return (0);
    }
    return (0);
}

void xp_check(all_t *all)
{
    if (all->game->xp_bar >= ((10 * all->combat->stat->level) / 2) + 1) {
        all->game->xp_bar -= ((10 * all->combat->stat->level) / 2);
        all->combat->stat->level += 1;
        if (all->select->k == 0) {
            all->combat->stat->attack = 3 * all->combat->stat->level;
            all->combat->stat->defense = 3 * all->combat->stat->level;
        }
        if (all->select->k == 1) {
            all->combat->stat->attack = 4 * all->combat->stat->level;
            all->combat->stat->defense = 2 * all->combat->stat->level;
        }
    }
}

int game_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->game->objects[1]->sprite);
    sfMusic_play(all->game->audio[0]->sound);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->game->audio[0]->sound, 0);
    while (all->scene == GAME) {
        sfRenderWindow_display(window);
        all->game->time = sfClock_getElapsedTime(all->game->clock);
        if (all->pause->in_pause == 1)
            pause_menu_main(window, all);
        else {
            xp_check(all);
            display_game_sprites(window, all);
        }
        event_game(window, all);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->game->audio[0]->sound);
    return all->scene;
}