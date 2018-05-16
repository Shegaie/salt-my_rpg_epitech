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

int free_destroy(button_t **button_arr, sfTexture *menu_t, sfSprite *menu_s,
int bt_nb)
{
	for (int i = 0; i < bt_nb; i++)
		free(button_arr[i]);
	sfSprite_destroy(menu_s);
	sfTexture_destroy(menu_t);
	return (0);
}

int display_reinit(sfRenderWindow *window, button_t **button_arr, int bt_nb)
{
	sfRenderWindow_display(window);
	for (int i = 0; i < bt_nb; i++) {
		button_arr[i]->rect.left = 0;
		sfRectangleShape_setTextureRect(button_arr[i]->button_r,
			button_arr[i]->rect);
	}
	return (0);
}

int event_handle(sfEvent *event, button_t **button_arr, sfRenderWindow *window)
{
	sfVector2i mouse_pos;
	int which_button = 0;

	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtMouseButtonReleased) {
			mouse_pos.x = event->mouseButton.x;
			mouse_pos.y = event->mouseButton.y;
			which_button = button_state_released(mouse_pos,
			button_arr, window);
		}
		if (which_button == 1)
			return (1);
		else if (which_button == 2)
			return (2);
		else
			return (0);
	}
	return (0);
}

int mouse_on_button(button_t **button_arr, sfRenderWindow *window, int bt_nb,
int offset)
{
	for (int i = 0; i < bt_nb; i++) {
		if (is_mouse_on(button_arr[i]->button_r,
		sfMouse_getPositionRenderWindow(window), offset) == 1) {
			button_arr[i]->rect.left = 600;
			sfRectangleShape_setTextureRect(button_arr[i]->button_r,
			button_arr[i]->rect);
		}
	}
	return (0);
}
