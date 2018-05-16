/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** init_tuto.c
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"

int init_tuto(rpg_t *rpg)
{
	rpg->tuto_step = 0;
	rpg->tuto.hud = malloc(sizeof(hud_t));
	if (rpg->tuto.hud == NULL)
		return (84);
	init_object(rpg->tuto.hud, "./asset/shop_text.png", 1200, 64);
	sfSprite_setScale(rpg->tuto.hud->sprite, (sfVector2f){ 0.5, 0.5 });
	return (0);
}