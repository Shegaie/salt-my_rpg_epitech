##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##

CC 	=	gcc
SRC_DIR	=	$(realpath src)/
INIT_DIR=	$(realpath src/init)/
DRAW_DIR=	$(realpath src/drawing)/
PLAY_DIR=	$(realpath src/player)/
FREE_DIR=	$(realpath src/frees)/
SHOP_DIR=	$(realpath src/shop)/
MAP_DIR	=	$(realpath src/map)/
MOB_DIR = 	$(realpath src/mobs)/
ZOM_DIR =	$(realpath src/mobs/zombie)/
PAR_DIR =	$(realpath src/map/parsing)/
PHY_DIR	=	$(realpath src/physic)/
TIC_DIR =	$(realpath src/particles)/
MENU_DIR=	$(realpath src/menu_pause)/
INC	=	$(realpath include)/
SRC	=	$(SRC_DIR)main.c		\
		$(SRC_DIR)event.c		\
		$(SRC_DIR)music.c		\
		$(MENU_DIR)menu.c		\
		$(MENU_DIR)menu_second.c        \
		$(MENU_DIR)menu_third.c	        \
		$(MENU_DIR)pause.c	        \
		$(MENU_DIR)pause_init.c	        \
		$(MENU_DIR)stat.c		\
		$(FREE_DIR)destroy.c		\
		$(FREE_DIR)destroy_inventory.c	\
		$(FREE_DIR)destroy_music.c	\
		$(FREE_DIR)free_all.c		\
		$(PAR_DIR)parsing.c		\
		$(MAP_DIR)map.c			\
		$(PHY_DIR)physics.c		\
		$(PHY_DIR)colision.c		\
		$(PHY_DIR)mouv.c		\
		$(TIC_DIR)dash_particles.c	\
		$(DRAW_DIR)knight_anim.c	\
		$(DRAW_DIR)draw_map.c		\
		$(DRAW_DIR)draw_hearts.c	\
		$(DRAW_DIR)draw_bgd.c		\
		$(DRAW_DIR)draw_game.c		\
		$(DRAW_DIR)draw_shop.c		\
		$(DRAW_DIR)draw_gold.c		\
		$(DRAW_DIR)draw_inventory.c	\
		$(DRAW_DIR)draw_interaction.c	\
		$(INIT_DIR)init_bgd.c		\
		$(INIT_DIR)init_parsing.c	\
		$(INIT_DIR)set_texture.c	\
		$(INIT_DIR)init_player.c	\
		$(INIT_DIR)init_game.c		\
		$(INIT_DIR)init_tuto.c		\
		$(INIT_DIR)init_shop.c		\
		$(INIT_DIR)init_inventory.c	\
		$(INIT_DIR)init_text.c		\
		$(INIT_DIR)init_object.c	\
		$(PLAY_DIR)attack.c		\
		$(PLAY_DIR)cooldown.c		\
		$(PLAY_DIR)death.c		\
		$(MOB_DIR)mob_initialisation.c	\
		$(ZOM_DIR)mobs_attack.c		\
		$(ZOM_DIR)mob_shift.c		\
		$(ZOM_DIR)draw_extra.c		\
		$(SHOP_DIR)shop.c		\
		$(SHOP_DIR)check_collide.c	\
		$(SHOP_DIR)draw_text.c		\
		$(SHOP_DIR)music_collisions.c	\
		$(SHOP_DIR)handle_inventory.c	\
		$(SHOP_DIR)potions_collisions.c

LIB_DIR	=	$(realpath lib/my)/
LIB	=	my
LIBS	=	-L$(LIB_DIR) -l$(LIB)
OBJ	=	$(SRC:.c=.o)
NAME	=	my_rpg
CFLAGS +=	-Wall -W -Wextra -I$(INC)
CFLAGS +=	-lc_graph_prog -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

debug:	CFLAGS += -g

debug:	re

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:	clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re:	fclean all clean
