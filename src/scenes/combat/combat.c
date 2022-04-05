/*
** EPITECH PROJECT, 2020
** combat.c
** File description:
** function for the fighting in the game
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void set_enemy_stats(all_t * all)
{
    all->combat->enemy_stats->life_enemy =
            all->combat->enemy_stat_array[all->combat->stat->level - 1][0];
    all->combat->enemy_stats->attack =
            all->combat->enemy_stat_array[all->combat->stat->level - 1][1];
}

void reset_stat(all_t *all)
{
    int level = all->combat->stat->level;

    if (all->select->k == 0) {
        all->combat->stat->defense = ((3 * level) + 3);
        all->combat->stat->attack = ((2 * level) + 2);
        all->combat->stat->defense += 10;
    }
    if (all->select->k == 1) {
        all->combat->stat->defense = ((2 *level) + 5);
        all->combat->stat->attack = ((3 * level) + 5);
        all->combat->stat->attack += 10;
    }
    all->combat->cooldown_buff = 0;
    all->combat->cooldown_ult = 0;
    set_enemy_stats(all);
}

void move_cursor_combat(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float) moveEvent.y;
    vector2F.x = (float) moveEvent.x;
    sfSprite_setPosition(all->combat->objects[2]->sprite, vector2F);
}

void analyse_events_combat(all_t  *all, sfEvent *event)
{
    all->scene = COMBAT;
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = QUIT;
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyC))
        all->scene = GAME;
    if (event->type == sfEvtMouseButtonPressed)
        all->scene = manage_click_combat(all, event->mouseButton);
    if (event->type == sfEvtMouseMoved)
        move_cursor_combat(all, event->mouseMove);
}

int combat_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->combat->objects[2]->sprite);
    sfMusic_play(all->combat->audio[0]->sound);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->combat->audio[0]->sound, 0);
    reset_stat(all);
    while (all->scene == COMBAT) {
        display_combat(window, all);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            analyse_events_combat(all, &all->event);
        }
    }
    if (all->scene == GAME)
        all->game->xp_bar += (4 + all->combat->stat->level);
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->combat->audio[0]->sound);
    return all->scene;
}