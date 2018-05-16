/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** menu functions
*/

#include "rpg.h"
#include "struct.h"
#include "menu.h"
#include <stdlib.h>
#define BUTTON_NB 2

void init_newGame_button(button_t *new_game)
{
	new_game->rect.left = 0;
	new_game->rect.top = 0;
	new_game->rect.width = 600;
	new_game->rect.height = 300;
	new_game->button_tx = sfTexture_createFromFile("./asset/StartGame.png",
	NULL);
	new_game->button_r = sfRectangleShape_create();
	sfRectangleShape_setTexture(new_game->button_r, new_game->button_tx,
	sfTrue);
	sfRectangleShape_setTextureRect(new_game->button_r, new_game->rect);
	sfRectangleShape_setSize(new_game->button_r, (sfVector2f){600, 300});
	sfRectangleShape_setPosition(new_game->button_r,
		(sfVector2f){200, 200});
}

void init_quitGame_button(button_t *quit_game)
{
	quit_game->rect.left = 0;
	quit_game->rect.top = 0;
	quit_game->rect.width = 600;
	quit_game->rect.height = 300;
	quit_game->button_tx = sfTexture_createFromFile("./asset/QuitGame.png",
	NULL);
	quit_game->button_r = sfRectangleShape_create();
	sfRectangleShape_setTexture(quit_game->button_r, quit_game->button_tx,
	sfTrue);
	sfRectangleShape_setTextureRect(quit_game->button_r, quit_game->rect);
	sfRectangleShape_setSize(quit_game->button_r,
		(sfVector2f){600, 300});
	sfRectangleShape_setPosition(quit_game->button_r,
		(sfVector2f){200, 600});
}

int is_mouse_on(sfRectangleShape *rect_shape, sfVector2i mouse_pos, int offset)
{
	return (mouse_pos.x >=
	sfRectangleShape_getGlobalBounds(rect_shape).left &&
	mouse_pos.x <= sfRectangleShape_getGlobalBounds(rect_shape).width +
	sfRectangleShape_getGlobalBounds(rect_shape).left && mouse_pos.y >=
	sfRectangleShape_getGlobalBounds(rect_shape).top +
		offset && mouse_pos.y <=
	sfRectangleShape_getGlobalBounds(rect_shape).height +
	sfRectangleShape_getGlobalBounds(rect_shape).top);
}

int button_state_released(sfVector2i mouse_pos, button_t **button_arr,
sfRenderWindow *window)
{
	if (is_mouse_on(button_arr[0]->button_r, mouse_pos, 130) == 1) {
		button_arr[0]->rect.left = 1200;
		sfRectangleShape_setTextureRect
		(button_arr[0]->button_r, button_arr[0]->rect);
		sfRenderWindow_drawRectangleShape(window,
		button_arr[0]->button_r, NULL);
		sfRenderWindow_display(window);
		return (1);
	}
	if (is_mouse_on(button_arr[1]->button_r, mouse_pos, 130) == 1) {
		button_arr[1]->rect.left = 1200;
		sfRectangleShape_setTextureRect
		(button_arr[1]->button_r, button_arr[1]->rect);
		sfRenderWindow_drawRectangleShape(window,
		button_arr[1]->button_r, NULL);
		sfRenderWindow_display(window);
		return (2);
	}
	return (0);
}

int init_buttons(button_t **button_arr)
{
	button_t *new_game;
	button_t *quit_game;

	new_game = malloc(sizeof(button_t));
	quit_game = malloc(sizeof(button_t));
	init_newGame_button(new_game);
	init_quitGame_button(quit_game);
	button_arr[0] = new_game;
	button_arr[1] = quit_game;
	return (0);
}
