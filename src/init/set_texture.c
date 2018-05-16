/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** set_texture.c
*/

#include "struct.h"
#include "parsing.h"

void set_texture(square_t *square, char c)
{
	if (c == '*')
		square->texture = sfTexture_createFromFile(STONE, NULL);
	if (c == '#' || c == 'm')
		square->texture = sfTexture_createFromFile(WOOD, NULL);
}

void set_sprite(square_t *square, char c)
{
	if (c == 't')
		square->texture = sfTexture_createFromFile(TORCH, NULL);
	if (c == 'c')
		square->texture = sfTexture_createFromFile(COIN, NULL);
	square->rect.top = 0;
	square->rect.left = 0;
	square->rect.width = 64;
	square->rect.height = 64;
}
