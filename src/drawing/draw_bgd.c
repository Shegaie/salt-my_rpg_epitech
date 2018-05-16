/*
** EPITECH PROJECT, 2017
** File Name : draw_bgd.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

int draw_bgd(sfRenderWindow *window, hud_t *background, hud_t *door, int mob_nb)
{
	sfRenderWindow_drawSprite(window, background->sprite, NULL);
	if (mob_nb != 0)
		sfRenderWindow_drawSprite(window, door->sprite, NULL);
	else
		sfRenderWindow_drawSprite(window, background->sprite, NULL);
	return (0);
}
