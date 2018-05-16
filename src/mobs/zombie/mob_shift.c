/*
** EPITECH PROJECT, 2018
** RPG | mobs attack
** File description:
** NOUHAUD Maïssa
*/

#include "mob.h"
#include "parsing.h"
#include <stdio.h>

void mob_right(mobs_t *mob, map_t *map)
{
	mob->mob_shift.time = sfClock_getElapsedTime(mob->mob_shift.clock);
	mob->mob_shift.seconds = mob->mob_shift.time.microseconds / 1000000.0;
	if (mob->mob_shift.seconds > 0.1) {
		mob->zombie.rect.top = 50;
		mob->zombie.rect.left += 50;
		if (mob->zombie.rect.left >= 150)
			mob->zombie.rect.left = 0;
		sfClock_restart(mob->mob_shift.clock);
	}
	for (int i = 0; count_square(map->map[map->n]) != i; i++)
		if (mob->zombie.pos.y == map->square[map->n][i].pos.y - 64 &&
		mob->zombie.pos.x <= map->square[map->n][i].pos.x + 64 &&
		mob->zombie.pos.x >= map->square[map->n][i].pos.x)
			mob->zombie.pos.x += 0.9;
}

void mob_left(mobs_t *mob, map_t *map)
{
	mob->mob_shift.time = sfClock_getElapsedTime(mob->mob_shift.clock);
	mob->mob_shift.seconds = mob->mob_shift.time.microseconds / 1000000.0;
	if (mob->mob_shift.seconds > 0.1) {
		mob->zombie.rect.left += 50;
		mob->zombie.rect.top = 0;
		if (mob->zombie.rect.left >= 150)
			mob->zombie.rect.left = 0;
		sfClock_restart(mob->mob_shift.clock);
	}
	for (int i = 0; count_square(map->map[map->n]) != i; i++)
		if (mob->zombie.pos.y == map->square[map->n][i].pos.y - 64 &&
		mob->zombie.pos.x <= map->square[map->n][i].pos.x + 64 &&
		mob->zombie.pos.x >= map->square[map->n][i].pos.x)
			mob->zombie.pos.x -= 0.9;
}

void mob_shifting(mobs_t *mob, sfRenderWindow *window, int i, map_t *map)
{
	sfSprite_setTextureRect(mob->zombie.sprite, mob->zombie.rect);
	sfSprite_setPosition(mob->zombie.sprite, mob->zombie.pos);
	sfRenderWindow_drawSprite(window, mob->zombie.sprite, NULL);
	if (i == 1)
		mob_right(mob, map);
	if (i == 2)
		mob_left(mob, map);
}

void mob_moving(mobs_t *mob, sfRenderWindow *window, phs_t *chara, rpg_t *rpg)
{
	sfVector2f mob_position;
	sfVector2f char_position;

	mob_position = sfSprite_getPosition(mob->zombie.sprite);
	char_position = sfRectangleShape_getPosition(chara->sqr);
	if (mob_position.x < char_position.x && mob->mob_dead == 0)
		mob_shifting(mob, window, 1, rpg->map);
	if (mob_position.x > char_position.x && mob->mob_dead == 0)
		mob_shifting(mob, window, 2, rpg->map);
}
