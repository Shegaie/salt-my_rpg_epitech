/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_pause
*/

#include <stdlib.h>
#include "rpg.h"
#include "struct.h"
#include "menu.h"
#include "free.h"
#include "init.h"
#define BUTTON_NB 3
#define RESUME "./asset/Resume.png"
#define QUIT_GAME "./asset/QuitGame.png"
#define STATS "./asset/Stats.png"
#define MENU "./asset/BackMenu.png"

void init_the_button(button_t *new_game, sfVector2f pos, char *path)
{
	new_game->rect.left = 0;
	new_game->rect.top = 0;
	new_game->rect.width = 600;
	new_game->rect.height = 300;
	new_game->button_tx = sfTexture_createFromFile(path, NULL);
	new_game->button_r = sfRectangleShape_create();
	sfRectangleShape_setTexture(new_game->button_r, new_game->button_tx,
	sfTrue);
	sfRectangleShape_setTextureRect(new_game->button_r, new_game->rect);
	sfRectangleShape_setSize(new_game->button_r, (sfVector2f){600, 300});
	sfRectangleShape_setScale(new_game->button_r, (sfVector2f){0.80, 0.80});
	sfRectangleShape_setPosition(new_game->button_r, pos);
}

int init_buttons_pause(button_t **button_arr)
{
	button_t *resume;
	button_t *quit_game;
	button_t *back_menu;

	resume = malloc(sizeof(button_t));
	quit_game = malloc(sizeof(button_t));
	back_menu = malloc(sizeof(button_t));
	init_the_button(resume, (sfVector2f){100, 100}, RESUME);
	init_the_button(quit_game, (sfVector2f){700, 900}, QUIT_GAME);
	init_the_button(back_menu, (sfVector2f){1300, 100}, MENU);
	button_arr[0] = resume;
	button_arr[1] = quit_game;
	button_arr[2] = back_menu;
	return (0);
}