/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** pause
*/

#include <stdlib.h>
#include "rpg.h"
#include "struct.h"
#include "menu.h"
#include "free.h"
#include "init.h"
#include "physic.h"
#include "player.h"
#define BUTTON_NB 3
#define RESUME "./asset/Resume.png"
#define QUIT_GAME "./asset/QuitGame.png"
#define STATS "./asset/Stats.png"
#define MENU "./asset/BackMenu.png"

int which_button_released(sfVector2i mouse_pos, button_t **button_arr,
sfRenderWindow *window)
{
	for (int i = 0; i < BUTTON_NB; i++) {
		if (is_mouse_on(button_arr[i]->button_r, mouse_pos, 0) == 1) {
			button_arr[i]->rect.left = 1200;
			sfRectangleShape_setTextureRect
			(button_arr[i]->button_r, button_arr[i]->rect);
			sfRenderWindow_drawRectangleShape(window,
			button_arr[i]->button_r, NULL);
			sfRenderWindow_display(window);
			return (i);
		}
	}
	return (-1);
}

int click_on_button(button_t **button_arr, sfRenderWindow *window, int *stat)
{
	sfVector2i mouse_pos;
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonReleased) {
			mouse_pos.x = event.mouseButton.x;
			mouse_pos.y = event.mouseButton.y;
			*stat = which_button_released(mouse_pos,
			button_arr, window);
		} else
			*stat = -1;
	}
	return (-1);
}

int pause_loop(rpg_t *rpg, button_t **button_arr, hud_t bg,
int *stat)
{
	sfSprite_setTexture(bg.sprite, bg.texture, sfTrue);
	while (1) {
		sfRenderWindow_drawSprite(rpg->window, bg.sprite, NULL);
		mouse_on_button(button_arr, rpg->window, BUTTON_NB, 0);
		click_on_button(button_arr, rpg->window, stat);
		pause_particles(rpg);
		if (*stat == -1) {
			for (int i = 0; i < BUTTON_NB; i++)
				sfRenderWindow_drawRectangleShape(rpg->window,
				button_arr[i]->button_r, NULL);
			display_reinit(rpg->window, button_arr, BUTTON_NB);
		} else
			break;
	}
	return (0);
}

int pause_game(sfRenderWindow *window, rpg_t *rpg)
{
	hud_t bg = {sfTexture_createFromFile("./asset/pause.png", NULL),
	sfSprite_create(), (sfVector2f){0, 0}};
	button_t **button_arr = malloc(sizeof(button_t *) * BUTTON_NB);
	int stat = 0;

	if (!button_arr)
		return (-1);
	init_buttons_pause(button_arr);
	pause_loop(rpg, button_arr, bg, &stat);
	free_destroy(button_arr, bg.texture, bg.sprite, BUTTON_NB);
	if (stat == 0)
		return (0);
	else if (stat == 1)
		return (-1);
	else if (stat == 2) {
		destroy_music(rpg);
		init_all(rpg);
		return (menu(window) == -1 ? -1 : 0);
	}
	return (0);
}
