/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** mouv.c
*/

#include <math.h>
#include "struct.h"
#include "rpg.h"
#include "physic.h"

int right_left(phs_t * phs, anim_t *knight_a, int r_l)
{
	if (r_l == 0) {
		sfRectangleShape_setScale(phs->sqr, (sfVector2f){-1.70, 1.70});
		phs->velocity.x = -5;
	} else {
		sfRectangleShape_setScale(phs->sqr, (sfVector2f){1.70, 1.70});
		phs->velocity.x = 5;
	}
	knight_a->knight_r.top = 150;
	return (0);
}

int mouv_jump(phs_t * phs, game_t *game)
{
	if (((sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue
	|| sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	&& phs->can_jump == 1)
	&& phs->sqr_pos.y > 100
	&& cols_params(phs, 0, -30) == -1) {
		phs->velocity.y = -30;
		phs->can_jump = 0;
		sfClock_restart(game->cooldown_jump->clock);
	}
	return (0);
}

int mouv(phs_t * phs, anim_t *knight_a, game_t *game)
{
	mouv_jump(phs, game);
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue
	&& cols_params(phs, 30, 0) == -1)
		right_left(phs, knight_a, 1);
	else if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
	phs->sqr_pos.x > (90) && cols_params(phs, -30, 0) == -1)
		right_left(phs, knight_a, 0);
	else
		knight_a->knight_r.top = 0;
	phs->sqr_pos.x += phs->velocity.x;
	phs->sqr_pos.y += phs->velocity.y;
	gravity_n_cinetic(phs);
	return (0);
}

float launch_dash(phs_t * phs)
{
	float y = (float)phs->mouse_pos.y - phs->sqr_pos_dash.y;
	float x = (float)phs->mouse_pos.x - phs->sqr_pos_dash.x;
	float angle = atan2(y, x);
	int speed = 30;

	phs->sqr_pos.x += cosf(angle)*speed;
	phs->sqr_pos.y += sinf(angle)*speed;
	phs->is_dash++;
	phs->sqr_pos.y -= 10;
	return (angle);
}

int dash(sfRenderWindow * window, phs_t * phs, game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && phs->can_dash == 1) {
		phs->mouse_pos = sfMouse_getPositionRenderWindow(window);
		phs->sqr_pos_dash.x = phs->sqr_pos.x;
		phs->sqr_pos_dash.y = phs->sqr_pos.y;
		phs->is_dash = 1;
		phs->can_dash = 0;
		sfClock_restart(game->cooldown_dash->clock);
	}
	return (0);
}
