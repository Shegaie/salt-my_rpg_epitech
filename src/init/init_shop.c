/*
** EPITECH PROJECT, 2017
** File Name : init_shop.c
** File description:
** Rémi BISSON
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"

void init_jukebox(hud_t *music, int i)
{
	music->texture = sfTexture_createFromFile(MUSIC, NULL);
	music->sprite = sfSprite_create();
	sfSprite_setTexture(music->sprite, music->texture, sfTrue);
	music->pos.x = 950 + (i * 100);
	music->pos.y = 960;
	sfSprite_setPosition(music->sprite, music->pos);
}

void init_receptacle(square_t *receptacle)
{
	receptacle->texture = sfTexture_createFromFile(RECEPTACLE, NULL);
	receptacle->sprite = sfSprite_create();
	sfSprite_setTexture(receptacle->sprite, receptacle->texture, sfTrue);
	receptacle->pos.x = 850;
	receptacle->pos.y = 960;
	sfSprite_setPosition(receptacle->sprite, receptacle->pos);
	receptacle->rect.top = 0;
	receptacle->rect.left = 0;
	receptacle->rect.width = 64;
	receptacle->rect.height = 64;
}

int malloc_shop(shop_t *shop)
{
	shop->music = malloc(sizeof(hud_t) * 5);
	shop->interaction = malloc(sizeof(hud_t));
	shop->buy_clock = malloc(sizeof(clock_s));
	shop->strength = malloc(sizeof(hud_t));
	shop->dash_cooldown = malloc(sizeof(hud_t));
	shop->strength_potion = malloc(sizeof(hud_t));
	shop->life_potion = malloc(sizeof(hud_t));
	shop->receptacle = malloc(sizeof(square_t));
	shop->banner = malloc(sizeof(hud_t));
	if (shop->music == NULL || shop->interaction == NULL ||
		shop->buy_clock == NULL || shop->strength == NULL ||
		shop->dash_cooldown == NULL || shop->banner == NULL ||
		shop->strength_potion == NULL || shop->life_potion == NULL ||
		shop->receptacle == NULL)
		return (84);
	return (0);
}

int init_shop(shop_t *shop)
{
	if (malloc_shop(shop) == 84)
		return (84);
	shop->buy_clock->clock = sfClock_create();
	for (int i = 0; i < 5; i++)
		init_jukebox(&shop->music[i], i);
	init_object(shop->interaction, INTERACTION, 0, 0);
	init_object(shop->strength, STRENGTH, 450, 960);
	init_object(shop->dash_cooldown, COOLDOWN, 550, 960);
	init_object(shop->banner, BANNER, 300, 64);
	init_object(shop->strength_potion, SPOTION, 750, 960);
	init_object(shop->life_potion, LPOTION, 650, 960);
	init_receptacle(shop->receptacle);
	shop->can_buy = 1;
	return (0);
}
