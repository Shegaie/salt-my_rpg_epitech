/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** event.c
*/

#include <stdlib.h>
#include "draw.h"
#include "physic.h"
#include "rpg.h"
#include "menu.h"
#include "player.h"
#include "draw.h"

void win_screen(rpg_t *rpg, mobs_t *mob)
{
	sfTexture *win_tx =
	sfTexture_createFromFile("./asset/WinScreen.png", NULL);
	sfSprite *win_sp = sfSprite_create();

	sfSprite_setTexture(win_sp, win_tx, sfTrue);
	for (int i = 0; i < 10; i++) {
		draw_bgd(rpg->window, rpg->background, rpg->door, mob->mobs_nb);
		draw_square(rpg->window, rpg->map, rpg->game);
		sfRenderWindow_drawRectangleShape(rpg->window,
			rpg->phs->sqr, NULL);
		sfRenderWindow_drawSprite(rpg->window, win_sp, NULL);
		sfRenderWindow_display(rpg->window);
		sfSleep((sfTime){100000});
	}
	rpg->game->is_return = 1;
}

void choose_map(rpg_t *rpg, int map)
{
	while (rpg->map->n == map || rpg->map->n == rpg->map->shop)
		rpg->map->n  = rand() % rpg->map->nb_map;
}


void tuto(rpg_t *rpg, sfEvent *event)
{
	if (event->key.code == sfKeyI && rpg->tuto_step == 2)
		rpg->tuto_step = 3;
	if (event->key.code == sfKeyA && rpg->tuto_step == 3)
		rpg->tuto_step = 4;
	if (event->key.code == sfKeyNum1 && rpg->tuto_step == 4)
		rpg->tuto_step = 5;
	if ((event->key.code == sfKeyQ || event->key.code == sfKeyD)
	&& rpg->tuto_step == 0)
		rpg->tuto_step = 1;
	if (event->key.code == sfKeyZ && rpg->tuto_step == 1)
		rpg->tuto_step = 2;
}

void change_map(rpg_t *rpg, mobs_t **mob)
{
	static int map;
	static int row;

	map = rpg->map->n;
	if (rpg->phs->sqr_pos.x >= 1920) {
		rpg->shop_music = 0;
		rpg->phs->sqr_pos.x = 70;
		for (int i = 0; i < 6; i++)
			zombie_initialisation(&(*mob)[i], rpg->map);
		if (row == 20)
			win_screen(rpg, mob[0]);
		if (rpg->map->nb_map > 1)
			choose_map(rpg, map);
		map = rpg->map->n;
		rpg->game->map_done++;
		row++;
	}
	if (rpg->game->map_done == 4) {
		rpg->game->map_done = 0;
		rpg->map->n = 0;
		rpg->shop_music = 1;
	}
}

int closing_event(sfEvent *event, rpg_t *rpg,
sfRenderWindow *window, mobs_t **mob)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
		if (pause_game(window, rpg) == -1)
			return (-1);
	}
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtKeyReleased
		&& event->key.code == sfKeyI)
			stat_player(window, rpg, event);
		tuto(rpg, event);
	}
	change_map(rpg, mob);
	return (0);
}
