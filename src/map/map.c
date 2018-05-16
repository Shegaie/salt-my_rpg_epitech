/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** map.c
*/

#include "struct.h"
#include "parsing.h"
#include "lib.h"

int check_char_map(char c)
{
	if (is_in_str(c, SQUARE) == 0)
		return (0);
	return (-1);
}

square_t init_square(square_t square, int x, int y, char c)
{
	set_texture(&square, c);
	if (is_in_str(c, SPRITE) == 0)
		set_sprite(&square, c);
	square.cols = is_in_str(c, COLS);
	square.pos.x = x;
	square.pos.y = y;
	square.sprite = sfSprite_create();
	sfSprite_setTexture(square.sprite, square.texture, sfTrue);
	sfSprite_setPosition(square.sprite, square.pos);
	if (is_in_str(c, SPRITE) == 0)
		sfSprite_setTextureRect(square.sprite, square.rect);
	return (square);
}

void init_map_game(map_t *map, int nmap)
{
	int x = 0;
	int y = 0;
	int j = 0;

	map->square[nmap] = malloc(sizeof(square_t) *
	(count_square(map->map[nmap])));
	for (int i = 0; map->map[nmap][i] != NULL; i++) {
		for (int n = 0; map->map[nmap][i][n] != '\0'; n++) {
			if (check_char_map(map->map[nmap][i][n]) == 0) {
				x = n * 64;
				map->square[nmap][j] = init_square(
					map->square[nmap][j], x, y,
					map->map[nmap][i][n]);
				j++;
			}
		}
		y += 64;
	}
}

void load_map(map_t *map)
{
	for (int i = 0; i < map->nb_map; i++)
		init_map_game(map, i);
}
