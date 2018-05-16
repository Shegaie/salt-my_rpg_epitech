/*
** EPITECH PROJECT, 2017
** File Name : draw_shop.c
** File description:
** Rémi BISSON
*/

#include <stdlib.h>
#include "struct.h"
#include "draw.h"

void move_potion(hud_t *potion)
{
	if (potion->pos.y != 960)
		potion->pos.y = 960;
	potion->pos.y -= rand() % 10 + 1;
	sfSprite_setPosition(potion->sprite, potion->pos);
}

void move_heart(square_t *receptacle)
{
	receptacle->rect.left += 64;
	sfSprite_setTextureRect(receptacle->sprite, receptacle->rect);
	if (receptacle->rect.left == 384)
		receptacle->rect.left = 0;
}

void draw_shop(sfRenderWindow *window, shop_t *shop, clock_s *shop_clock)
{
	shop_clock->time = sfClock_getElapsedTime(shop_clock->clock);
	shop_clock->seconds = shop_clock->time.microseconds / 1000000.0;
	if (shop_clock->seconds > 0.1) {
		move_potion(shop->strength_potion);
		move_potion(shop->dash_cooldown);
		move_potion(shop->strength);
		move_potion(shop->life_potion);
		move_heart(shop->receptacle);
		sfClock_restart(shop_clock->clock);
	}
	for (int i = 0; i != 5; i++)
		sfRenderWindow_drawSprite(window, shop->music[i].sprite, NULL);
	sfRenderWindow_drawSprite(window, shop->strength->sprite, NULL);
	sfRenderWindow_drawSprite(window, shop->dash_cooldown->sprite, NULL);
	sfRenderWindow_drawSprite(window, shop->strength_potion->sprite, NULL);
	sfRenderWindow_drawSprite(window, shop->life_potion->sprite, NULL);
	sfRenderWindow_drawSprite(window, shop->receptacle->sprite, NULL);
}
