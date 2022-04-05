/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** function for the inventory
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int manage_click_inventory(all_t *all, sfMouseButtonEvent event)
{
    if (event.y > 228 && event.y < 312 && all->combat->stat->level >= 2 &&
        event.x > 214 && event.x < 290 && all->inventory->eat == 0) {
        all->inventory->eat = 1;
        all->combat->stat->life += 5;
    }
    if (event.y > 228 && event.y < 312 && all->combat->stat->level >= 3 &&
        event.x > 385 && event.x < 476 && all->inventory->shield == 0) {
        all->inventory->shield = 1;
        all->combat->stat->defense += 1;
    }
    return INVENTORY;
}

void move_cursor_inventory(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float) moveEvent.y;
    vector2F.x = (float) moveEvent.x;
    sfSprite_setPosition(all->inventory->objects[2]->sprite, vector2F);
}

void analyse_events_inventory(all_t  *all, sfEvent *event)
{
    all->scene = INVENTORY;
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = QUIT;
    if (event->type == sfEvtKeyReleased || event->key.code == sfKeyI)
        all->scene = GAME;
    if (event->type == sfEvtMouseButtonPressed)
        all->scene = manage_click_inventory(all, event->mouseButton);
    else if (event->type == sfEvtMouseMoved)
        move_cursor_inventory(all, event->mouseMove);
}

int inventory_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->inventory->objects[1]->sprite);
    sfMusic_play(all->inventory->audio[0]->sound);

    while (all->scene == INVENTORY) {
        display_inventory_sprites(window, all);
        sfRenderWindow_display(window);
        set_text(all);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            analyse_events_inventory(all, &all->event);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->inventory->audio[0]->sound);
    return all->scene;
}