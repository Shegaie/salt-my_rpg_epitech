/*
** EPITECH PROJECT, 2017
** File Name : destroy_inventory.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void destroy_inventory(inventory_t *inventory)
{
	sfSprite_destroy(inventory->slot1->object->sprite);
	sfTexture_destroy(inventory->slot1->object->texture);
	sfSprite_destroy(inventory->slot2->object->sprite);
	sfTexture_destroy(inventory->slot2->object->texture);
	sfSprite_destroy(inventory->slot3->object->sprite);
	sfTexture_destroy(inventory->slot3->object->texture);
	sfSprite_destroy(inventory->slot4->object->sprite);
	sfTexture_destroy(inventory->slot4->object->texture);
	sfSprite_destroy(inventory->slot5->object->sprite);
	sfTexture_destroy(inventory->slot5->object->texture);
	sfSprite_destroy(inventory->invent->sprite);
	sfTexture_destroy(inventory->invent->texture);
}
