/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** draw_map.c
*/

#include "struct.h"
#include "parsing.h"

void draw_sprite(map_t *map, game_t *game, int i)
{
	if (map->square[map->n][i].cols == 1 &&
	game->map->seconds > 0.0001 && rand() % 2 == 1) {
		if (map->square[map->n][i].rect.left <= 384)
			map->square[map->n][i].rect.left += 64;
		else
			map->square[map->n][i].rect.left = 0;
		sfSprite_setTextureRect(map->square[map->n][i].sprite,
		map->square[map->n][i].rect);
		sfClock_restart(game->map->clock);
	}
}

void draw_square(sfRenderWindow *window, map_t *map, game_t *game)
{
	game->map->time = sfClock_getElapsedTime(game->map->clock);
	game->map->seconds = game->map->time.microseconds / 1000000.0;
	for (int i = 0; i != count_square(map->map[map->n]); i++) {
		draw_sprite(map, game, i);
		sfRenderWindow_drawSprite(window,
		map->square[map->n][i].sprite, NULL);
	}
};
