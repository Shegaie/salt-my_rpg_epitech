/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particles for the dash
*/

#include <stdlib.h>
#include "struct.h"
#include "physic.h"

int init_vertexArray(phs_t *phs)
{
	sfVertex point;
	size_t dim = PART_NB;

	phs->part_array = sfVertexArray_create();
	sfVertexArray_resize(phs->part_array, dim);
	for (int i = 0; i <= PART_NB; i++)
		sfVertexArray_append(phs->part_array, point);
	return (0);
}

int init_vertexArray_pause(phs_t *phs)
{
	sfVertex point;
	size_t dim = PART_NB;

	phs->part_array_pause = sfVertexArray_create();
	sfVertexArray_resize(phs->part_array_pause, dim);
	for (int i = 0; i <= PART_NB; i++)
		sfVertexArray_append(phs->part_array_pause, point);
	return (0);
}

int pause_particles(rpg_t *rpg)
{
	sfVertex *point;
	static int row = 0;

	if (row == 0) {
		for (int i = 0; i < PART_NB_PAUSE; i++) {
			rpg->phs->part_pos_pause[i].y = 550+(rand() % 300);
			rpg->phs->part_pos_pause[i].x = 1108 + rand() % 256;
		}
	}
	for (int i = 0; i < PART_NB_PAUSE; i++) {
		point = sfVertexArray_getVertex(rpg->phs->part_array_pause, i);
		point->position.y = rpg->phs->part_pos_pause[i].y + 2.5;
		point->position.x = rpg->phs->part_pos_pause[i].x;
		if (rpg->phs->part_pos_pause[i].y > 550+(200 +
				(rand() % 100))) {
			point->position.y = 550;
			rpg->phs->part_pos_pause[i].y = point->position.y;
		}
		rpg->phs->part_pos_pause[i].y = point->position.y;
	}
	sfRenderWindow_drawVertexArray(rpg->window, rpg->phs->part_array_pause,
	NULL);
	row++;
	return (0);
}

int reinit_particles(phs_t *phs, sfVector2f pos)
{
	static int x = 0;
	static int x_past = 1;
	static int row = 0;
	int i = 0;
	int posy = 0;

	x = pos.x;
	if (x != x_past)
		row = 0;
	x_past = x;
	if (row == 0) {
		while (i < PART_NB) {
			phs->part_pos[i].x = pos.x + (rand() % 64);
			posy = rand() % 180;
			phs->part_pos[i].y = (1080 - 60) - posy;
			i++;
		}
	}
	row++;
	return (0);
}

int potion_particles(phs_t *phs, sfRenderWindow *window, sfVector2f pos,
__attribute__((unused)) sfColor color)
{
	sfVertex *point;
	int i = 0;

	reinit_particles(phs, pos);
	while (i < PART_NB) {
			point = sfVertexArray_getVertex(phs->part_array, i);
			point->color = sfWhite;
			point->position.y = phs->part_pos[i].y - 2.5;
			point->position.x = phs->part_pos[i].x;
			if (phs->part_pos[i].y < (800 + (rand() % 100))) {
				point->position.y = 1080 - 60;
				phs->part_pos[i].y = point->position.y;
			}
			phs->part_pos[i].y = point->position.y;
			i++;
	}
	sfRenderWindow_drawVertexArray(window, phs->part_array, NULL);
	return (0);
}
