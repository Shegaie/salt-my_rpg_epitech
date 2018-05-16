/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** free.c
*/

#include "struct.h"
#include "parsing.h"

void free_map(map_t *map)
{
	for (int i = 0; i < map->nb_map; i++) {
			free(map->square[i]);
	}
	free(map->square);
	for (int i = 0; i < map->nb_map; i++) {
		for (int j = 0; j < 17; j++) {
			free(map->map[i][j]);
		}
	}
	free(map->map);
	for (int i = 0; i < map->nb_map; i++) {
		free(map->name[i]);
	}
	free(map->name);
}

void free_player(player_t *player)
{
	free(player->heart);
	free(player->half_heart);
	free(player->empty_heart);
	free(player->gold);
}

void free_shop(shop_t *shop)
{
	free(shop->interaction);
	free(shop->banner);
	free(shop->strength);
	free(shop->dash_cooldown);
	free(shop->music);
	free(shop->strength_potion);
	free(shop->life_potion);
	free(shop->receptacle);
}

void free_inventory(inventory_t *inventory)
{
	free(inventory->slot1->object);
	free(inventory->slot1);
	free(inventory->slot2->object);
	free(inventory->slot2);
	free(inventory->slot3->object);
	free(inventory->slot3);
	free(inventory->slot4->object);
	free(inventory->slot4);
	free(inventory->slot5->object);
	free(inventory->slot5);
	free(inventory->invent);
}

void free_all(rpg_t *rpg)
{
	free_map(rpg->map);
	free(rpg->map);
	free_player(rpg->player);
	free(rpg->player);
	free_shop(rpg->shop);
	free_inventory(rpg->inventory);
	free(rpg->shop);
	free(rpg->phs);
	free(rpg->game);
	free(rpg->background);
	free(rpg->inventory);
}
