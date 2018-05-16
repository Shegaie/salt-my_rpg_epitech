/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** destroy.c
*/

#include "struct.h"
#include "parsing.h"
#include "rpg.h"
#include "player.h"
#include "free.h"

void destroy_map(map_t *map)
{
	for (int j = 0; j < map->nb_map; j++) {
		for (int i = 0; i != count_square(map->map[j]); i++) {
			sfSprite_destroy(map->square[j][i].sprite);
			sfTexture_destroy(map->square[j][i].texture);
		}
	}
}

void destroy_player(player_t *player)
{
	sfSprite_destroy(player->heart->sprite);
	sfTexture_destroy(player->heart->texture);
	sfTexture_destroy(player->half_heart->texture);
	sfSprite_destroy(player->half_heart->sprite);
	sfTexture_destroy(player->empty_heart->texture);
	sfSprite_destroy(player->empty_heart->sprite);
	sfTexture_destroy(player->gold->texture);
	sfSprite_destroy(player->gold->sprite);
}

void destroy_bgd(hud_t *background)
{
	sfSprite_destroy(background->sprite);
	sfTexture_destroy(background->texture);
}

void destroy_shop(shop_t *shop)
{
	sfSprite_destroy(shop->interaction->sprite);
	sfTexture_destroy(shop->interaction->texture);
	sfSprite_destroy(shop->banner->sprite);
	sfTexture_destroy(shop->banner->texture);
	sfSprite_destroy(shop->strength->sprite);
	sfTexture_destroy(shop->strength->texture);
	sfTexture_destroy(shop->dash_cooldown->texture);
	sfSprite_destroy(shop->dash_cooldown->sprite);
	for (int i = 0; i != 4; i++) {
		sfTexture_destroy(shop->music[i].texture);
		sfSprite_destroy(shop->music[i].sprite);
	}
	sfTexture_destroy(shop->strength_potion->texture);
	sfSprite_destroy(shop->strength_potion->sprite);
	sfTexture_destroy(shop->life_potion->texture);
	sfSprite_destroy(shop->life_potion->sprite);
	sfTexture_destroy(shop->receptacle->texture);
	sfSprite_destroy(shop->receptacle->sprite);
}

void destroy_all(sfRenderWindow *window, rpg_t *rpg)
{
	destroy_map(rpg->map);
	destroy_player(rpg->player);
	destroy_bgd(rpg->background);
	destroy_shop(rpg->shop);
	destroy_inventory(rpg->inventory);
	destroy_music(rpg);
	sfVertexArray_destroy(rpg->phs->part_array);
	sfVertexArray_destroy(rpg->phs->part_array_pause);
	sfRenderWindow_destroy(window);
}
