/*
** EPITECH PROJECT, 2017
** File Name : init_player.c
** File description:
** Rémi BISSON
*/

#include <stdlib.h>
#include "init.h"
#include "struct.h"
#include "player.h"

void init_heart(hud_t *heart)
{
	heart->texture = sfTexture_createFromFile(HEART, NULL);
	heart->sprite = sfSprite_create();
	sfSprite_setTexture(heart->sprite, heart->texture, sfTrue);
	heart->pos.x = 0;
	heart->pos.y = 0;
}

void init_half_heart(hud_t *half_heart)
{
	half_heart->texture = sfTexture_createFromFile(HALF_HEART, NULL);
	half_heart->sprite = sfSprite_create();
	sfSprite_setTexture(half_heart->sprite, half_heart->texture, sfTrue);
	half_heart->pos.x = 0;
	half_heart->pos.y = 0;
}

void init_empty_heart(hud_t *empty_heart)
{
	empty_heart->texture = sfTexture_createFromFile(EMPTY_HEART, NULL);
	empty_heart->sprite = sfSprite_create();
	sfSprite_setTexture(empty_heart->sprite, empty_heart->texture, sfTrue);
	empty_heart->pos.x = 0;
	empty_heart->pos.y = 0;
}

int init_player(player_t *player)
{
	player->heart = malloc(sizeof(hud_t));
	player->half_heart = malloc(sizeof(hud_t));
	player->empty_heart = malloc(sizeof(hud_t));
	player->gold = malloc(sizeof(hud_t));
	if (player->heart == NULL || player->half_heart == NULL ||
		player->empty_heart == NULL || player->gold == NULL)
		return (84);
	init_heart(player->heart);
	init_half_heart(player->half_heart);
	init_empty_heart(player->empty_heart);
	init_object(player->gold, GOLD, 1700, 0);
	player->nb_gold = 50000;
	player->nb_lives = 10;
	player->max_lives = 10;
	player->tmp_lives = 0;
	player->tmp_strength = 0;
	player->strength = 30;
	return (0);
}
