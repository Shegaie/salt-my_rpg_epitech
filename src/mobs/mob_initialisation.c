/*
** EPITECH PROJECT, 2018
** NOUHAUD Maïssa
** File description:
** RPG | mobs create
*/

#include "mob.h"
#include "parsing.h"

sprite_init_t mobs_init(char *file, int *rect, float *pos)
{
	sprite_init_t init;

	init.rect.left = rect[0];
	init.rect.top = rect[1];
	init.rect.width = rect[2];
	init.rect.height = rect[3];
	init.pos.x = pos[0];
	init.pos.y = pos[1];
	init.texture = sfTexture_createFromFile(file, NULL);
	init.sprite = sfSprite_create();
	sfSprite_setTexture(init.sprite, init.texture, sfTrue);
	sfSprite_setPosition(init.sprite, init.pos);
	return (init);
}

int check_s(map_t *map, int random)
{
	for (int i = 0; count_square(map->map[map->n]) != i; i++)
		if (map->square[map->n][random].pos.x ==
		map->square[map->n][i].pos.x
		&& map->square[map->n][random].pos.y - 64 ==
		map->square[map->n][i].pos.y)
			return (1);
	return (0);
}

int get_random(map_t *map)
{
	int square = count_square(map->map[map->n]) - 30;
	int random;

	while ((random = rand() % square))
		if ((map->square[map->n][random].pos.x != 0 ||
		map->square[map->n][random].pos.x != 1920 - 64)
		&& check_s(map, random) == 0)
			return (random + 30);
	return (random);
}

void zombie_initialisation(mobs_t *mob, map_t *map)
{
	int rect[4] = {0, 0, 50, 50};
	int random = get_random(map);
	float pos[2];
	float pos2[2] = {400.0, 500.0};

	mob->draw_mob = 0;
	mob->mobs_nb = 6;
	pos[0] = map->square[map->n][random].pos.x;
	pos[1] = map->square[map->n][random].pos.y - 64;
	mob->mob_dead = 0;
	mob->mob_life = 70;
	mob->lose = 0;
	mob->stop = 0;
	mob->stop2 = 0;
	mob->damages = 0;
	mob->life_lose.clock = sfClock_create();
	mob->mob_shift.clock = sfClock_create();
	mob->mob_dying.clock = sfClock_create();
	mob->mob_damages.clock = sfClock_create();
	mob->zombie = mobs_init("asset/zombie.png", rect, pos);
	mob->zombie_dying = mobs_init("asset/zombie_dying.png", rect, pos2);
	mob->zombie_damages = mobs_init("asset/zombie_damages.png", rect, pos2);
}

void mob_initialisation(mobs_t **mob, map_t *map)
{
	int i = 0;
	*mob = malloc(sizeof(mobs_t) * 120);

	while (i < 120) {
		zombie_initialisation(&(*mob)[i], map);
		i++;
	}
}
