/*
** EPITECH PROJECT, 2020
** my_rpg.h
** File description:
** .h for the rpg functions
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>

enum scenes
{
    QUIT = 0,
    MAIN_MENU = 1,
    SETTINGS = 2,
    CHAMP_SELECT = 3,
    GAME = 4,
    COMBAT = 5,
    INVENTORY = 6,
    HELP = 7,
    DEATH = 8,
    VICTORY = 9
};


// ~~~ FILES ~~~

// SRC:
// quit.c
int quit_main(sfRenderWindow *window, all_t *all);
//audio_settings.c
void audio_settings(all_t *all);
//help.c
int help_flag(int ac, char **av);
//button_animation.c
void button_animation(all_t *all, sfVector2f cursor_pos);


// SRC/STRUCT:
//init_audio.c
t_audio *create_audio(char const *path);
//init_sprites.c
t_ob *create_object(char const *path, sfVector2f mouv, sfIntRect rect);
//init_time.c
t_time *create_time_game(void);
//init_struct.c
all_t *init_all(void);
sfVector2f set_cursor_on_mouse(sfRenderWindow *window, sfSprite *cursor);
//init_menu.c
menu_t *init_menu_struct(void);
//init_settings.c
settings_t *init_settings_struct(void);
//init_select.c
select_t *init_select_struct(void);
//init_game.c
game_t *init_game(void);
//init_pause.c
pause_t *init_pause_menu_struct(void);
//init_inventory
inventory_t *init_inventory(void);
//init_combat
combat_t *init_combat(all_t *all);
void set_text_combat_mage(combat_t *combat, all_t *all);
void set_text_combat_warrior(combat_t *combat, all_t *all);
void create_sprites_enemy_combat(combat_t *combat);
int **create_array_stat();
void set_scale(combat_t *combat);
void champ_combat(all_t *all);
//init_help
help_t  *init_help(void);
//init_death
death_t *init_death(void);
//init_victory
victory_t *init_victory(void);


// SRC/FREE:
//free_all.c
void free_all(all_t *all);

void free_pause(all_t *all);
void free_select(all_t *all);
void free_game(all_t *all);
void free_inventory(all_t *all);
void free_help(all_t *all);
void free_death(all_t *all);
void free_victory(all_t *all);

// SRC/SCENES:

//starting_menu/display_menu.c
void display_menu_sprites(sfRenderWindow *window, all_t *all);
//starting_menu/starting_menu.c
int menu_main(sfRenderWindow *window, all_t *all);

//settings/display_setting.c
void display_setting_sprites(sfRenderWindow *window, all_t *all);
//settings/setting_menu.c
int setting_main(sfRenderWindow *window, all_t *all);
//settings/button_animation_s2.c
void button_animation_down_sfx(all_t *all, sfVector2f cursor_pos);
void button_animation_up_sfx(all_t *all, sfVector2f cursor_pos);
void button_animation_down_mu(all_t *all, sfVector2f cursor_pos);
void button_animation_up_mu(all_t *all, sfVector2f cursor_pos);
void button_animation_s(all_t *all, sfVector2f cursor_pos);
void manage_click_option(all_t *all, sfMouseButtonEvent event);
//settings/option.c
void mute_gestion(all_t *all);
void mus_gestion(all_t *all);
void sfx_gestion(all_t *all);
//settings/settings_menu.c
void option(sfRenderWindow *window, all_t *all);

//champ_select
void display_select_sprites(sfRenderWindow *window, all_t *all);
int select_main(sfRenderWindow *window, all_t *all);
void select_color(all_t *all, int a);

//game
int game_main(sfRenderWindow *window, all_t *all);
void event_game(sfRenderWindow *window, all_t *all);
void move_cursor_game(all_t *all, sfMouseMoveEvent moveEvent);
void display_game_sprites(sfRenderWindow *window, all_t *all);

void move(all_t *all, sfEvent *event);
void move_left(all_t *all, sfEvent *event);
void move_right(all_t *all, sfEvent *event);
void move_down(all_t *all, sfEvent *event);
void move_up(all_t *all, sfEvent *event);

int go_left(all_t *all);
int go_right(all_t *all);
int go_down(all_t *all);
int go_up(all_t *all);

void choose_color_anim(all_t *all);
void anim_character(all_t *all);

int is_dialog(all_t *all);
void animation(all_t *all);
void particles(all_t *all);
void draw_particles(sfRenderWindow *window, all_t *all);

int passeable(sfColor get_color, int count);

//pause
int analyse_events_pause_menu(all_t *all, sfEvent *event);
int pause_menu_main(sfRenderWindow *window, all_t *all);
void change_button_quit(all_t *all, sfMouseButtonEvent event);
void change_button_resume(all_t *all, sfMouseButtonEvent event);
void button_animation_pause(all_t *all, sfMouseMoveEvent moveEvent);

//combat
int combat_main(sfRenderWindow *window, all_t *all);
int manage_click_combat(all_t *all, sfMouseButtonEvent event);
void display_combat(sfRenderWindow *window, all_t *all);

int attack_warrior_1(all_t *all);
int attack_warrior_2(all_t *all);
int attack_warrior_3(all_t *all);
int attack_mage_1(all_t *all);
int attack_mage_2(all_t *all);
int attack_mage_3(all_t *all);

//inventory
int inventory_main(sfRenderWindow *window, all_t *all);
void display_inventory_sprites(sfRenderWindow *window, all_t *all);
void set_text(all_t *all);

//help
int help_main(sfRenderWindow *window, all_t *all);

//death
int death_main(sfRenderWindow *window, all_t *all);
void move_cursor_death(all_t *all, sfMouseMoveEvent moveEvent);
int manage_click_death(all_t *all, sfMouseButtonEvent event);

//victory
int manage_click_victory(all_t *all, sfMouseButtonEvent event);
void move_cursor_victory(all_t *all, sfMouseMoveEvent moveEvent);
int victory_main(sfRenderWindow *window, all_t *all);
#endif /* MY_RPG_H_ */