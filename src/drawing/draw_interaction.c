/*
** EPITECH PROJECT, 2017
** File Name : draw_interaction.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void draw_interaction(rpg_t *rpg)
{
	static int x = 0;

	rpg->shop->interaction->pos.x = rpg->phs->sqr_pos.x - 25;
	rpg->shop->interaction->pos.y = rpg->phs->sqr_pos.y - 110;
	sfSprite_setPosition(rpg->shop->interaction->sprite,
			rpg->shop->interaction->pos);
	if (x < 20) {
		sfRenderWindow_drawSprite(rpg->window,
			rpg->shop->interaction->sprite, NULL);
	}
	x++;
	if (x == 40)
		x = 0;
}
