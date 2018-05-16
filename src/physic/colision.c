/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** colision.c
*/

#include "struct.h"
#include "rpg.h"
#include "physic.h"
#include "parsing.h"
#define OFFSET 20

float cols_cond(phs_t *phs, int i)
{
	if ((phs->sqr_pos.x >= phs->map->square[phs->map->n][i].pos.x + 64)
	|| (phs->sqr_pos.x + OFFSET <= phs->map->square[phs->map->n][i].pos.x)
	|| (phs->sqr_pos.y >= phs->map->square[phs->map->n][i].pos.y + 64)
	|| (phs->sqr_pos.y + 50 <= phs->map->square[phs->map->n][i].pos.y))
		return (-1);
	else
		return (phs->map->square[phs->map->n][i].pos.y);
}

int cols(phs_t *phs)
{
	int ret;

	for (int i = 30; i ; i++) {
		if ((ret = cols_cond(phs, i)) != -1 &&
		phs->map->square[phs->map->n][i].cols == 0)
			return (ret);
		if (i >= phs->map->s + 29 &&
		phs->map->square[phs->map->n][i].cols == 0)
			return (-1);
	}
	return (0);
}

float cols_params_cond(phs_t *phs, int i, int x, int y)
{
	if ((phs->sqr_pos.x  + x >= phs->map->square[phs->map->n][i].pos.x + 64)
	|| (phs->sqr_pos.x + OFFSET  +
	x <= phs->map->square[phs->map->n][i].pos.x)
	|| (phs->sqr_pos.y + y >= phs->map->square[phs->map->n][i].pos.y + 64)
	|| (phs->sqr_pos.y + 50 + y <= phs->map->square[phs->map->n][i].pos.y))
		return (-1);
	else
		return (phs->map->square[phs->map->n][i].pos.y);
}

int cols_params(phs_t *phs, int x, int y)
{
	int ret;

	phs->map->s = count_square(phs->map->map[phs->map->n]) - 30;
	for (int i = 1; i ; i++) {
		if ((ret = cols_params_cond(phs, i, x, y)) != -1 &&
		phs->map->square[phs->map->n][i].cols == 0)
			return (ret);
		if (i >= phs->map->s &&
		phs->map->square[phs->map->n][i].cols == 0)
			return (-1);
	}
	return (0);
}
