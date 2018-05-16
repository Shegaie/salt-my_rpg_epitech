/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** stat.c
*/

#include <stdlib.h>
#include "draw.h"
#include "physic.h"
#include "rpg.h"
#include "menu.h"
#include "player.h"
#include "lib.h"
#include "shop.h"

int anim_stat(stat_t *stat, anim_t * knight_a, game_t *game)
{
	game->anim_knight->time =
		sfClock_getElapsedTime(game->anim_knight->clock);
	game->anim_knight->seconds =
		game->anim_knight->time.microseconds / 1000000.0;
	if (game->anim_knight->seconds > 0.1) {
		sfRectangleShape_setRotation(stat->rect, 0);
		((knight_a->knight_r.left >= 150) ?
		(knight_a->knight_r.left = 0) :
		(knight_a->knight_r.left += 50));
		sfRectangleShape_setTextureRect(stat->rect, knight_a->knight_r);
		sfClock_restart(game->anim_knight->clock);
	}
	return (0);
}

void set_stat(rpg_t *rpg)
{
	rpg->stat->rect = sfRectangleShape_copy(rpg->phs->sqr);
	sfRectangleShape_setScale(rpg->stat->rect, (sfVector2f){ 6, 6 });
	rpg->knight_a->knight_r.top = 0;
	sfRectangleShape_setPosition(rpg->stat->rect, (sfVector2f){ 400, 500});
}

void print_stat(rpg_t *rpg)
{
	draw_bgd(rpg->window, rpg->background, rpg->door, 1);
	anim_stat(rpg->stat, rpg->knight_a, rpg->game);
	draw_square(rpg->window, rpg->map, rpg->game);
	sfRenderWindow_drawRectangleShape(rpg->window, rpg->phs->sqr, NULL);
	for (int i = 0; i < 5; i++)
		sfRenderWindow_drawSprite(rpg->window,
		rpg->stat->hud[i].sprite, NULL);
	draw_text2(rpg, my_itoa(rpg->player->nb_gold),
		(sfVector2f){ 900, 320 }, 30);
	draw_text2(rpg, my_itoa(rpg->player->max_lives / 2),
		(sfVector2f){ 900, 520 }, 30);
	draw_text2(rpg, my_itoa(rpg->game->dash_cooldown),
		(sfVector2f){ 900, 720 }, 30);
	draw_text2(rpg, my_itoa(rpg->player->strength),
		(sfVector2f){ 900, 920 }, 30);
	sfRenderWindow_drawRectangleShape(rpg->window, rpg->stat->rect, NULL);
}

int stat_player(sfRenderWindow *window, rpg_t *rpg, sfEvent *event)
{
	set_stat(rpg);
	while (1) {
		sfRenderWindow_clear(window, sfBlack);
		while (sfRenderWindow_pollEvent(window, event))
			if (event->type == sfEvtKeyReleased &&
					event->key.code == sfKeyI)
				return (0);
		print_stat(rpg);
		sfRenderWindow_display(window);
	}
	return (0);
}
