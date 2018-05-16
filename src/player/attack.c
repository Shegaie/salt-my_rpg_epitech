/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** attack player
*/

#include "struct.h"
#include "rpg.h"
#include "physic.h"

int anim_attack(phs_t * phs, anim_t * knight_a, game_t *game, int attack_prog)
{
	knight_a->knight_r.top = 50;
	knight_a->knight_r.left = 50 * attack_prog;
	sfRectangleShape_setTextureRect
		(phs->sqr, knight_a->knight_r);
	(attack_prog == 3 ? game->is_attacking = 0 : 1 == 1);
	(attack_prog == 3 ? attack_prog = 0 : attack_prog++);
	((knight_a->knight_r.left == 150) ?
	(knight_a->knight_r.left = 0) : 1 == 1);
	sfClock_restart(game->anim_attack->clock);
	return (attack_prog);
}

void player_attack(phs_t * phs, anim_t * knight_a, game_t * game)
{
	static int attack_prog = 0;

	if (sfMouse_isButtonPressed(sfMouseLeft) && game->can_attack == 1) {
		attack_prog = 1;
		game->can_attack = 0;
		game->is_attacking = 1;
		sfClock_restart(game->cooldown_attack->clock);
	} else if (attack_prog != 0) {
		game->anim_attack->time =
			sfClock_getElapsedTime(game->anim_attack->clock);
		game->anim_attack->seconds =
			game->anim_attack->time.microseconds / 1000000.0;
		if (game->anim_attack->seconds > 0.06)
			attack_prog = anim_attack
				(phs, knight_a, game, attack_prog);
	}
}
