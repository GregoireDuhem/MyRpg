##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Pierre BITTOU
##

CC =  gcc

SRC    =	src/main.c	\
		src/quit.c	\
		src/help.c	\
		src/help_flag.c \
		src/audio_settings.c    \
		src/free/free_all.c	\
		src/free/free_select.c  \
		src/free/free_game.c  \
		src/struct/init_audio.c	\
		src/struct/init_menu.c	\
		src/struct/init_sprites.c	\
		src/struct/init_struct.c	\
		src/struct/init_time.c	\
		src/struct/init_settings.c	\
		src/struct/init_pause.c	\
		src/struct/init_game.c	\
		src/struct/init_select.c	\
		src/struct/init_combat.c    \
		src/struct/init_enemy_combat.c    \
		src/struct/init_scale_combat.c    \
		src/struct/init_inventory.c \
		src/struct/init_help.c  \
		src/struct/init_combat_text.c   \
		src/struct/init_death.c \
		src/struct/init_victory.c   \
		src/struct/init_stat_array.c	\
		src/scenes/champ_selec/champ_select.c	\
		src/scenes/champ_selec/display_champ.c  \
		src/scenes/combat/combat.c	\
		src/scenes/combat/event_combat.c    \
		src/scenes/combat/display_combat.c  \
		src/scenes/combat/attack_warrior.c  \
		src/scenes/combat/attack_mage.c \
		src/scenes/game/display_game.c	\
		src/scenes/game/event_game.c	\
		src/scenes/game/game.c	\
		src/scenes/inventory/inventory.c	\
		src/scenes/inventory/inventory2.c	\
		src/scenes/pause/animation_pause.c	\
		src/scenes/pause/pause.c	\
		src/scenes/starting_menu/starting_menu.c	\
		src/scenes/starting_menu/display_menu.c	\
		src/scenes/starting_menu/button_animation.c	\
		src/scenes/settings/setting_menu.c	\
		src/scenes/settings/display_setting.c	\
		src/scenes/settings/button_animation_s.c	\
		src/scenes/settings/button_animation_s2.c	\
	 	src/scenes/settings/option.c	\
	 	src/scenes/settings/option2.c	\
		src/scenes/settings/mute.c	\
		src/scenes/game/move.c	\
		src/scenes/game/hitbox_management.c	\
		src/scenes/death/death.c    \
		src/scenes/death/death_event.c  \
		src/scenes/game/particles.c		\
		src/scenes/victory/victory.c    \
		src/scenes/victory/victory_event.c  \

OBJ    =  $(SRC:.c=.o)

NAME   =  my_rpg

INC    =  include

CFLAGS +=  -W -Wall -Wextra -lmy -I./$(INC) -l csfml-system -l csfml-window -l csfml-graphics -l csfml-audio -lm -g

all:	$(NAME)

$(NAME):$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all
	clean
	fclean
