/*
** EPITECH PROJECT, 2017
** File Name : init_object.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void init_object(hud_t *object, char *filepath, int x, int y)
{
	object->texture = sfTexture_createFromFile(filepath, NULL);
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->pos.x = x;
	object->pos.y = y;
	sfSprite_setPosition(object->sprite, object->pos);
}
