/*
** EPITECH PROJECT, 2017
** File Name : draw_inventory.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "shop.h"
#include "lib.h"

#define DRAW_SPRITE sfRenderWindow_drawSprite

void draw_inventory(rpg_t *rpg)
{
	DRAW_SPRITE(rpg->window, rpg->inventory->invent->sprite, NULL);
	DRAW_SPRITE(rpg->window, rpg->inventory->slot1->object->sprite, NULL);
	DRAW_SPRITE(rpg->window, rpg->inventory->slot2->object->sprite, NULL);
	DRAW_SPRITE(rpg->window, rpg->inventory->slot3->object->sprite, NULL);
	DRAW_SPRITE(rpg->window, rpg->inventory->slot4->object->sprite, NULL);
	DRAW_SPRITE(rpg->window, rpg->inventory->slot5->object->sprite, NULL);
	draw_text2(rpg, my_itoa(rpg->inventory->slot2->nb_objects),
		(sfVector2f){930, 60}, 15);
	draw_text2(rpg, my_itoa(rpg->inventory->slot3->nb_objects),
		(sfVector2f){1000, 60}, 15);
	draw_text2(rpg, my_itoa(rpg->inventory->slot4->nb_objects),
		(sfVector2f){1060, 60}, 15);
	draw_text2(rpg, my_itoa(rpg->inventory->slot5->nb_objects),
		(sfVector2f){1115, 60}, 15);
}
