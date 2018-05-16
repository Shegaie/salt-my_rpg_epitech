/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** cooldown
*/

#include "struct.h"
#include "rpg.h"
#include "player.h"

int get_elapsed(game_t * game)
{
	game->cooldown_jump->time =
		sfClock_getElapsedTime(game->cooldown_jump->clock);
	game->cooldown_jump->seconds =
		game->cooldown_jump->time.microseconds / 1000000.0;
	game->cooldown_dash->time =
		sfClock_getElapsedTime(game->cooldown_dash->clock);
	game->cooldown_dash->seconds =
		game->cooldown_dash->time.microseconds / 1000000.0;
	game->cooldown_attack->time =
		sfClock_getElapsedTime(game->cooldown_attack->clock);
	game->cooldown_attack->seconds =
		game->cooldown_attack->time.microseconds / 1000000.0;
	return (0);
}

int cooldown(phs_t * phs, game_t * game)
{
	get_elapsed(game);
	if (game->cooldown_jump->seconds > 0.7)
		phs->can_jump = 1;
	if (game->cooldown_dash->seconds > game->dash_cooldown/10)
		phs->can_dash = 1;
	game->can_attack = 1;
	return (0);
}