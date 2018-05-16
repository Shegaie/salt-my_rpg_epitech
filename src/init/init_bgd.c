/*
** EPITECH PROJECT, 2017
** File Name : init_bgd.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "init.h"
#include "stdlib.h"

int init_bgd(hud_t *background, hud_t *door)
{
	door->texture = sfTexture_createFromFile("./asset/door.png", NULL);
	door->sprite = sfSprite_create();
	background->texture = sfTexture_createFromFile(BGD, NULL);
	background->sprite = sfSprite_create();
	sfSprite_setTexture(door->sprite, door->texture, sfTrue);
	sfSprite_setTexture(background->sprite, background->texture, sfTrue);
	background->pos.x = 0;
	background->pos.y = 0;
	door->pos = (sfVector2f){1920-64, 0};
	sfSprite_setPosition(door->sprite, door->pos);
	sfSprite_setPosition(background->sprite, background->pos);
	return (0);
}
