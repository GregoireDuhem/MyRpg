/*
** EPITECH PROJECT, 2020
** event_game.c
** File description:
** function to handle the envent of the gmae scene
*/

#include "my_rpg_struct.h"
#include "my_rpg.h"
#include "my.h"

void is_blue(all_t *all, sfEvent *event)
{
    sfColor get_color;
    int i = 0;

    for (; i < 23; i++) {
        get_color = sfImage_getPixel(all->game->hitbox,
            2474 + all->game->objects[0]->rect.left + 16,
            3514 + all->game->objects[0]->rect.top - i);
        if (get_color.a == sfBlue.a && get_color.r == sfBlue.r &&
            get_color.g == sfBlue.g && get_color.b == sfBlue.b)
            if (event->type == sfEvtKeyReleased && event->key.code == sfKeyE)
                is_dialog(all);
    }
}

void is_red(all_t *all, sfEvent *event)
{
    sfColor get_color;

    get_color = sfImage_getPixel(all->game->hitbox,
        2474 + all->game->objects[0]->rect.left,
        3514 + all->game->objects[0]->rect.top);
    if (get_color.a == sfRed.a && get_color.r == sfRed.r &&
        get_color.g == sfRed.g && get_color.b == sfRed.b)
        if (event->type == sfEvtKeyReleased && event->key.code == sfKeyC)
            all->scene = COMBAT;
}

void move_cursor_game(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float)moveEvent.y;
    vector2F.x = (float)moveEvent.x;
    sfSprite_setPosition(all->game->objects[2]->sprite, vector2F);
}

int analyse_events_game(all_t *all, sfEvent *event)
{
    if (all->pause->in_pause == 0) {
        if (event->type == sfEvtMouseMoved)
            move_cursor_game(all, event->mouseMove);
        if (event->type == sfEvtKeyPressed)
            move(all, event);
        if (event->type == sfEvtKeyReleased && event->key.code == sfKeyP)
            all->pause->in_pause = 1;
        is_red(all, event);
        is_blue(all, event);
        if (event->type == sfEvtKeyReleased && event->key.code == sfKeyI)
            all->scene = INVENTORY;
        if (event->type == sfEvtMouseButtonReleased) {
            return GAME;
        }
    }
    return all->scene;
}

void event_game(sfRenderWindow *window, all_t *all)
{
    while (sfRenderWindow_pollEvent(window, &all->event)) {
        if (all->event.type == sfEvtClosed ||
            all->event.key.code == sfKeyEscape)
            all->scene = QUIT;

        all->scene = analyse_events_pause_menu(all, &all->event);
        all->scene = analyse_events_game(all, &all->event);
    }
}