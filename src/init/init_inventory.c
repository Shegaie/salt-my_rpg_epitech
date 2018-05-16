/*
** EPITECH PROJECT, 2017
** File Name : init_inventory.c
** File description:
** Rémi BISSON
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"

int init_slots(inventory_t *inventory)
{
	inventory->slot1 = malloc(sizeof(slot_t));
	inventory->slot1->object = malloc(sizeof(hud_t));
	inventory->slot2 = malloc(sizeof(slot_t));
	inventory->slot2->object = malloc(sizeof(hud_t));
	inventory->slot3 = malloc(sizeof(slot_t));
	inventory->slot3->object = malloc(sizeof(hud_t));
	inventory->slot4 = malloc(sizeof(slot_t));
	inventory->slot4->object = malloc(sizeof(hud_t));
	inventory->slot5 = malloc(sizeof(slot_t));
	inventory->slot5->object = malloc(sizeof(hud_t));
	if (inventory->slot4 == NULL || inventory->slot4->object == NULL ||
		inventory->slot5 == NULL || inventory->slot5->object == NULL ||
		inventory->slot3 == NULL || inventory->slot3->object == NULL ||
		inventory->slot2 == NULL || inventory->slot2->object == NULL ||
		inventory->slot1 == NULL || inventory->slot1->object == NULL)
		return (84);
	return (0);
}

int init_inventory(inventory_t *inventory)
{
	if (init_slots(inventory) == 84)
		return (84);
	inventory->invent = malloc(sizeof(hud_t));
	if (inventory->invent == NULL)
		return (84);
	init_object(inventory->invent, INVENT, 805, 0);
	init_object(inventory->slot1->object, INVENT_SWORD, 843, 15);
	init_object(inventory->slot2->object, STRENGTH, 887, 16);
	init_object(inventory->slot3->object, LPOTION, 950, 16);
	init_object(inventory->slot4->object, SPOTION, 1010, 16);
	init_object(inventory->slot5->object, COOLDOWN, 1073, 15);
	inventory->slot1->nb_objects = 0;
	inventory->slot2->nb_objects = 0;
	inventory->slot3->nb_objects = 0;
	inventory->slot4->nb_objects = 0;
	inventory->slot5->nb_objects = 0;
	return (0);
}
