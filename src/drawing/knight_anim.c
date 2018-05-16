/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** chara animation
*/

#include "struct.h"
#include "physic.h"
#include "rpg.h"

#define SETSCALE sfRectangleShape_setScale

int apply_anim(phs_t * phs, anim_t * knight_a, game_t *game)
{
	game->anim_knight->time =
		sfClock_getElapsedTime(game->anim_knight->clock);
	game->anim_knight->seconds =
		game->anim_knight->time.microseconds / 1000000.0;
	if (game->anim_knight->seconds > 0.1) {
		sfRectangleShape_setRotation(phs->sqr, 0);
		((knight_a->knight_r.left >= 150) ?
		(knight_a->knight_r.left = 0) :
		(knight_a->knight_r.left += 50));
		sfRectangleShape_setTextureRect(phs->sqr, knight_a->knight_r);
		sfClock_restart(game->anim_knight->clock);
	}
	return (0);
}

int init_knight_animation(phs_t * phs, anim_t *knight_a,
sfRenderWindow *window)
{
	sfIntRect knight_r = { 0, 0, 50, 50 };

	knight_a->knight_r = knight_r;
	knight_a->knight_t =
		sfTexture_createFromFile("./asset/knight-sheet.png", NULL);
	phs->sqr = sfRectangleShape_create();
	sfRectangleShape_setOrigin(phs->sqr, (sfVector2f){20, 20});
	sfRectangleShape_scale(phs->sqr, (sfVector2f){
			1.70, 1.70});
	sfRectangleShape_setTexture(phs->sqr, knight_a->knight_t, 1);
	sfRectangleShape_setTextureRect(phs->sqr, knight_r);
	sfRectangleShape_setSize(phs->sqr, (sfVector2f){50, 50});
	sfRenderWindow_drawRectangleShape(window, phs->sqr, NULL);
	return (0);
}

int knight_anim_idle(phs_t * phs, anim_t * knight_a)
{
	sfRectangleShape_setRotation(phs->sqr, 0);
	sfRectangleShape_setTexture(phs->sqr, knight_a->knight_t, 1);
	sfRectangleShape_setTextureRect(phs->sqr, knight_a->knight_r);
	return (0);
}

int dash_anime(phs_t * phs, float angle)
{
	sfIntRect dash_r = { 50, 2*50, 50, 50 };
	sfVector2f actual_s = sfRectangleShape_getScale(phs->sqr);

	if (actual_s.x > 0) {
		if ((phs->mouse_pos.x - phs->sqr_pos_dash.x) < 0) {
			SETSCALE(phs->sqr, (sfVector2f){-1.70, 1.70});
			sfRectangleShape_setRotation(phs->sqr, -angle*20);

		} else
			sfRectangleShape_setRotation(phs->sqr, angle*50);
	} else
		if ((phs->mouse_pos.x - phs->sqr_pos_dash.x) > 0) {
			SETSCALE(phs->sqr, (sfVector2f){1.70, 1.70});
			sfRectangleShape_setRotation(phs->sqr, angle*50);
		} else
			sfRectangleShape_setRotation(phs->sqr, -angle*20);
	sfRectangleShape_setTexture(phs->sqr, phs->dash_txt, 1);
	sfRectangleShape_setTextureRect(phs->sqr, dash_r);
	return (0);
}
