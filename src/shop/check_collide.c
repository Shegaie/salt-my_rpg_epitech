/*
** EPITECH PROJECT, 2017
** File Name : check_collide.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "shop.h"

int check_collide(sfSprite *sprite, sfVector2f pos)
{
	return (pos.x >= sfSprite_getGlobalBounds(sprite).left &&
	pos.x <= sfSprite_getGlobalBounds(sprite).width +
	sfSprite_getGlobalBounds(sprite).left && pos.y >=
	sfSprite_getGlobalBounds(sprite).top && pos.y <=
	sfSprite_getGlobalBounds(sprite).height +
	sfSprite_getGlobalBounds(sprite).top);
}
