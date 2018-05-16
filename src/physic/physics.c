/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** physics.c (Lanfranchini Grégoire)
*/

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "rpg.h"
#include "physic.h"
#include "player.h"

float launch_dash2(phs_t * phs, int i)
{
	float y = (float)phs->mouse_pos.y - phs->sqr_pos_dash.y;
	float x = (float)phs->mouse_pos.x - phs->sqr_pos_dash.x;
	float angle = atan2(y, x);
	int speed = 30;

	if (i == 0)
		return (phs->sqr_pos.x + cosf(angle)*speed);
	return (phs->sqr_pos.y + sinf(angle)*speed);
}

int init_physics(phs_t * phs, map_t *map)
{
	sfVector2f sqr_size = { 50, 50 };
	sfVector2f sqr_pos = { 1920 / 2 - sqr_size.x, (1080 - sqr_size.y) - 64};
	sfVector2f velocity = { 0, 0 };

	phs->map = map;
	phs->can_jump = 1;
	phs->can_dash = 1;
	phs->sqr_size = sqr_size;
	phs->sqr_pos = sqr_pos;
	phs->velocity = velocity;
	phs->is_dash = 0;
	phs->part_pos = malloc(sizeof(sfVector2f) * PART_NB);
	phs->part_pos_pause = malloc(sizeof(sfVector2f) * PART_NB_PAUSE);
	if (!phs->part_pos || !phs->part_pos_pause)
		return (84);
	init_vertexArray(phs);
	init_vertexArray_pause(phs);
	phs->dash_txt = sfTexture_createFromFile
	("./asset/knight-sheet.png", NULL);
	sfRectangleShape_setPosition(phs->sqr, sqr_pos);
	return (0);
}

int gravity_n_cinetic(phs_t * phs)
{
	float n;

	if (phs->velocity.x != 0)
		((phs->velocity.x > 0) ? (phs->velocity.x -= 0.5)
		: (phs->velocity.x += 0.5));
	if (phs->velocity.y != 0) {
		if (cols_params(phs, 0, -50) != - 1)
			phs->velocity.y += 5;
		if (phs->velocity.y > 0  && cols_params(phs, 0, -70) == -1)
			phs->velocity.y -= 0.5;
		else
			phs->velocity.y += 0.5;
	}
	if (phs->sqr_pos.y < (1080 - 56) - phs->sqr_size.y && cols(phs) == -(1))
		phs->velocity.y += 1.8;
	else if ((n = cols(phs)) != -1) {
		phs->sqr_pos.y = n - phs->sqr_size.y;
		phs->velocity.y = 0;
	}
	return (0);
}

int physics(sfRenderWindow * window, phs_t * phs,
	anim_t * knight_a, game_t *game)
{
	float angle = 0;

	dash(window, phs, game);
	cooldown(phs, game);
	if (phs->is_dash == 0) {
		mouv(phs, knight_a, game);
		apply_anim(phs, knight_a, game);
	} else if (phs->is_dash <= DASH_RANGE) {
		phs->velocity.y = -2;
		if (launch_dash2(phs, 0) > 88.0 && launch_dash2(phs, 0) < 1810.0
		&& launch_dash2(phs, 1) > 64.0 && launch_dash2(phs, 1) < 1016)
			angle = launch_dash(phs);
		else
			phs->is_dash = 0;
		dash_anime(phs, angle);
	} else {
		phs->is_dash = 0;
		knight_anim_idle(phs, knight_a);
	}
	sfRectangleShape_setPosition(phs->sqr, phs->sqr_pos);
	return (0);
}
