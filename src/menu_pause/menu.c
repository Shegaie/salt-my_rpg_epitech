/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** menu
*/

#include "rpg.h"
#include "struct.h"
#include "menu.h"
#include <stdlib.h>
#define BUTTON_NB 2

int game_loop_menu(button_t **button_arr, sfRenderWindow *window, sfTime wait,
sfEvent event)
{
	int stat = 0;

	mouse_on_button(button_arr, window, BUTTON_NB, 80);
	stat = event_handle(&event, button_arr, window);
	if (stat == 1) {
		sfSleep(wait);
		return (1);
	} else if (stat == 2) {
		sfSleep(wait);
		return (2);
	}
	for (int i = 0; i < BUTTON_NB; i++) {
		sfRenderWindow_drawRectangleShape(window,
		button_arr[i]->button_r, NULL);
	}
	return (0);
}

int menu_loop(sfRenderWindow *window, button_t **button_arr, sfTexture *menu_t,
sfSprite *menu_s)
{
	sfTime wait = {0};
	sfEvent event;
	int stat = 0;

	sfSprite_setTexture(menu_s, menu_t, sfTrue);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_drawSprite(window, menu_s, NULL);
		stat = game_loop_menu(button_arr, window, wait, event);
		if (stat == 1) {
			free_destroy(button_arr, menu_t, menu_s, BUTTON_NB);
			return (0);
		}
		else if (stat == 2) {
			free_destroy(button_arr, menu_t, menu_s, BUTTON_NB);
			return (-1);
		}
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			return (-1);
		display_reinit(window, button_arr, BUTTON_NB);
	}
	return (-1);
}

int menu(sfRenderWindow *window)
{
	sfTexture *menu_t = sfTexture_createFromFile("./asset/menu.png", NULL);
	sfSprite *menu_s = sfSprite_create();
	button_t **button_arr = malloc(sizeof(button_t *) * BUTTON_NB);

	if (!button_arr)
		return (-1);
	init_buttons(button_arr);
	if (menu_loop(window, button_arr, menu_t, menu_s) == 0)
		return (0);
	else
		return (-1);
}
