/*
** EPITECH PROJECT, 2020
** starting_setting.c
** File description:
** files for the starting setting scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void move_cursor_setting(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float) moveEvent.y;
    vector2F.x = (float) moveEvent.x;
    sfSprite_setPosition(all->settings->objects[1]->sprite, vector2F);
    button_animation_s(all, vector2F);
}

int analyse_events_setting(all_t *all, sfEvent *event)
{
    all->scene = SETTINGS;
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = 0;
    if (event->type == sfEvtMouseButtonPressed)
        manage_click_option(all, event->mouseButton);
    else if (event->type == sfEvtMouseMoved)
        move_cursor_setting(all, event->mouseMove);
    return all->scene;
}

int setting_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->settings->objects[1]->sprite);
    sfMusic_play(all->menu->audio[0]->sound);
    while (all->scene == SETTINGS) {
        display_setting_sprites(window, all);
        option(window, all);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            analyse_events_setting(all, &all->event);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->menu->audio[0]->sound);
    return all->scene;
}