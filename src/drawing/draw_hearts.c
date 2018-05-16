/*
** EPITECH PROJECT, 2017
** File Name : draw_hearts.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "parsing.h"

void draw_empty_hearts(player_t *player, sfRenderWindow *window)
{
	int i = 0;

	for (i = 0; i < player->max_lives; i += 2) {
		player->empty_heart->pos.x += 66;
		sfSprite_setPosition(player->empty_heart->sprite,
				player->empty_heart->pos);
		sfRenderWindow_drawSprite(window,
			player->empty_heart->sprite, NULL);
	}
	player->empty_heart->pos.x = 0;
}

void draw_lives(player_t *player, sfRenderWindow *window)
{
	int i = 0;
	int nb_lives = player->nb_lives;

	draw_empty_hearts(player, window);
	if (nb_lives % 2 != 0)
		nb_lives -= 1;
	for (i = 0; i < nb_lives; i += 2) {
		player->heart->pos.x += 66;
		sfSprite_setPosition(player->heart->sprite,
			player->heart->pos);
		sfRenderWindow_drawSprite(window, player->heart->sprite, NULL);
	}
	if (player->nb_lives % 2 != 0) {
		player->half_heart->pos.x = player->heart->pos.x + 66;
		sfSprite_setPosition(player->half_heart->sprite,
			player->half_heart->pos);
		sfRenderWindow_drawSprite(window,
			player->half_heart->sprite, NULL);
	}
	player->heart->pos.x = 0;
}
