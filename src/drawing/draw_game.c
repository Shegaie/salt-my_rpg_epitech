/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** draw_game.c
*/

#include "struct.h"
#include "draw.h"
#include "player.h"
#include "physic.h"
#include "parsing.h"
#include "shop.h"
#include "lib.h"

void draw_tuto(rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window, rpg->tuto.hud->sprite, NULL);
	if (rpg->tuto_step == 0)
		draw_text2(rpg, "Press key Q or D to move",(sfVector2f){1250, 80}, 15);
	if (rpg->tuto_step == 1)
		draw_text2(rpg, "Press key Z or space to jump",(sfVector2f){1250, 80}, 15);
	if (rpg->tuto_step == 2)
		draw_text2(rpg, "Press I to open stat info",(sfVector2f){1250, 80}, 15);
	if (rpg->tuto_step == 3)
		draw_text2(rpg, "Press key A to dash",(sfVector2f){1250, 80}, 15);
	if (rpg->tuto_step == 4)
		draw_text2(rpg, "Press key 1 2 3 4 to use potions",(sfVector2f){1250, 80}, 15);
}

void draw_game(sfRenderWindow *window, rpg_t *rpg, anim_t *knight_a,
mobs_t *mob)
{
	draw_bgd(window, rpg->background, rpg->door, mob->mobs_nb);
	if (rpg->tuto_step < 5)
		draw_tuto(rpg);
	draw_square(window, rpg->map, rpg->game);
	if ((rpg->game->map_done == 0 && rpg->map->n == 0)
			|| rpg->map->nb_map == 1) {
		draw_shop(window, rpg->shop, rpg->game->shop_clock);
		shop(rpg);
	}
	physics(window, rpg->phs, knight_a, rpg->game);
	player_attack(rpg->phs, knight_a, rpg->game);
	draw_lives(rpg->player, window);
	draw_gold(window, rpg->player->gold);
	draw_text2(rpg, my_itoa(rpg->player->nb_gold),
		(sfVector2f){1780, 25}, 28);
	draw_inventory(rpg);
//	if (mob->draw_mob == 1)
		mob_handling(mob, rpg, window);
	sfRenderWindow_drawRectangleShape(window, rpg->phs->sqr, NULL);
}
