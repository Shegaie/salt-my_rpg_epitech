/*
** EPITECH PROJECT, 2017
** File Name : draw_gold.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void draw_gold(sfRenderWindow *window, hud_t *gold)
{
	sfRenderWindow_drawSprite(window, gold->sprite, NULL);
}
