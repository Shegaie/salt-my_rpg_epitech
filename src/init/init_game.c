/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init game struct
*/

#include <stdlib.h>
#include "struct.h"
#include "init.h"
#include "parsing.h"
#include "rpg.h"

int init_stat(stat_t *stat)
{
	stat->hud = malloc(sizeof(hud_t) * 5);
	if (stat->hud == NULL)
		return (84);
	init_object(&stat->hud[0], "./asset/stat.png", 0, 0);
	init_object(&stat->hud[1], "./asset/coin.png", 800, 300);
	init_object(&stat->hud[2], "./asset/heart_stat.png", 800, 500);
	init_object(&stat->hud[3], "./asset/hourglass.png", 800, 700);
	init_object(&stat->hud[4], "./asset/strength_stat.png", 800, 900);
	return (0);
}

int init_game(game_t *game)
{
	game->anim_knight = malloc(sizeof(clock_s));
	game->cooldown_jump = malloc(sizeof(clock_s));
	game->cooldown_dash = malloc(sizeof(clock_s));
	game->cooldown_attack = malloc(sizeof(clock_s));
	game->anim_attack = malloc(sizeof(clock_s));
	game->shop_clock = malloc(sizeof(clock_s));
	game->map = malloc(sizeof(clock_s));
	game->shop_clock->clock = sfClock_create();
	game->anim_knight->clock = sfClock_create();
	game->cooldown_jump->clock = sfClock_create();
	game->cooldown_dash->clock = sfClock_create();
	game->cooldown_attack->clock = sfClock_create();
	game->anim_attack->clock = sfClock_create();
	game->map->clock = sfClock_create();
	game->is_attacking = 0;
	game->can_attack = 1;
	game->dash_cooldown = 10;
	return (0);
}

int init_rpg(rpg_t *rpg)
{
	rpg->phs = malloc(sizeof(phs_t));
	rpg->game = malloc(sizeof(game_t));
	rpg->player = malloc(sizeof(player_t));
	rpg->background = malloc(sizeof(hud_t));
	rpg->door = malloc(sizeof(hud_t));
	rpg->knight_a = malloc(sizeof(anim_t));
	rpg->map = malloc(sizeof(map_t));
	rpg->shop = malloc(sizeof(shop_t));
	rpg->text = malloc(sizeof(text_t));
	rpg->inventory = malloc(sizeof(inventory_t));
	rpg->stat = malloc(sizeof(stat_t));
	rpg->game->map_done = 0;
	if (rpg->phs == NULL || rpg->game == NULL ||
		rpg->player == NULL || rpg->background == NULL ||
		rpg->knight_a == NULL || rpg->map == NULL ||
		rpg->shop == NULL || rpg->text == NULL ||
		rpg->inventory == NULL || rpg->stat == NULL)
		return (84);
	return (0);
}

int init_music(rpg_t *rpg)
{
	rpg->music = malloc(sizeof(sfMusic *) * MUSIC_NB);
	if (!rpg->music)
		return (84);
	rpg->shop_music = 0;
	rpg->music[MAIN_MUSIC] = sfMusic_createFromFile
	("./asset/music/main_music.ogg");
	rpg->music[SHOP_MUSIC] = sfMusic_createFromFile
	("./asset/music/shop_music.ogg");
	rpg->music[GREG_MUSIC] = sfMusic_createFromFile
	("./asset/music/greg_music.ogg");
	rpg->music[MATH_MUSIC] = sfMusic_createFromFile
	("./asset/music/math_music.ogg");
	rpg->music[REMI_MUSIC] = sfMusic_createFromFile
	("./asset/music/remi_music.ogg");
	rpg->music[MAISSA_MUSIC] = sfMusic_createFromFile
	("./asset/music/maïssa_music.ogg");
	rpg->music[ABEL_MUSIC] = sfMusic_createFromFile
	("./asset/music/abel_music.ogg");
	rpg->main_music = rpg->music[MAIN_MUSIC];
	return (0);
}

int init_all(rpg_t *rpg)
{
	init_bgd(rpg->background, rpg->door);
	init_knight_animation(rpg->phs, rpg->knight_a, rpg->window);
	rpg->music = malloc(sizeof(sfMusic *));
	if (init_player(rpg->player) == 84 || init_game(rpg->game) == 84 ||
		init_music(rpg) == 84)
		return (84);
	load_map(rpg->map);
	init_physics(rpg->phs, rpg->map);
	init_inventory(rpg->inventory);
	if (init_physics(rpg->phs, rpg->map) == 84)
		return (84);
	rpg->map->s = count_square(rpg->map->map[0]) - 30;
	init_shop(rpg->shop);
	init_text(rpg->text);
	if (init_stat(rpg->stat) == 84)
		return (84);
	rpg->game->is_return = 0;
	if (init_tuto(rpg) == 84)
		return (84);
	return (0);
}
