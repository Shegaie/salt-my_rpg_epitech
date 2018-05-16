/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my_rpg.c
*/

#include <unistd.h>
#include <time.h>
#include "struct.h"
#include "draw.h"
#include "init.h"
#include "parsing.h"
#include "player.h"
#include "free.h"
#include "rpg.h"
#include "lib.h"
#include "physic.h"
#include "mob.h"
#include "menu.h"
#include "shop.h"

sfRenderWindow *open_window(void)
{
	sfVideoMode mode = { 1920, 1080, 32 };
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "Salt", sfResize | sfClose
		| sfFullscreen, NULL);
	if (window == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}

int game_loop(rpg_t *rpg)
{
	sfEvent event;
	mobs_t *mob;

	if (init_all(rpg) == 84)
		return (84);
	mob_initialisation(&mob, rpg->map);
	sfRenderWindow_setFramerateLimit(rpg->window, 60);
	while (sfRenderWindow_isOpen(rpg->window)) {
		music_handle(rpg);
		sfRenderWindow_clear(rpg->window, sfBlack);
		if (closing_event(&event, rpg, rpg->window, &mob) != 0 ||
		rpg->game->is_return == 1)
			break;
		handle_buy_clock(rpg->shop);
		handle_inventory(rpg);
		draw_game(rpg->window, rpg, rpg->knight_a, mob);
		sfRenderWindow_display(rpg->window);
	}
	destroy_all(rpg->window, rpg);
	free_all(rpg);
	return (0);
}

int main(int ac, char __attribute__((unused)) **argv)
{
	rpg_t rpg;
	rpg.window = open_window();

	srand(time(NULL));
	if (ac == 1 && init_rpg(&rpg) == 0 && menu(rpg.window) == 0) {
		if (init_map(rpg.map) == 84)
			return (84);
		game_loop(&rpg);
		return (0);
	}
	return (84);
}
