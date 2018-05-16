/*
** EPITECH PROJECT, 2017
** File Name : shop.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "shop.h"

void handle_buy_clock(shop_t *shop)
{
	shop->buy_clock->time =
		sfClock_getElapsedTime(shop->buy_clock->clock);
	shop->buy_clock->seconds =
		shop->buy_clock->time.microseconds / 1000000.0;
	if (shop->buy_clock->seconds > 0.5)
		shop->can_buy = 1;
}

void shop_collisions(rpg_t *rpg)
{
	strength_collision(rpg);
	cooldown_collision(rpg);
	life_collision(rpg);
	strength2_collision(rpg);
	receptacle_collision(rpg);
	greg_music_collision(rpg);
	maissa_music_collision(rpg);
	mathieu_music_collision(rpg);
	remi_music_collision(rpg);
	abel_music_collision(rpg);
}

int shop(rpg_t *rpg)
{
	shop_collisions(rpg);
	return (0);
}
