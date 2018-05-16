/*
** EPITECH PROJECT, 2018
** NOUHAUD Maïssa
** File description:
** RPG | mob.h
*/

#include "rpg.h"
#include "struct.h"
#include <unistd.h>
#include <time.h>

#ifndef MOB_H_
#define MOB_H_

typedef struct sprite {
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f pos;
} sprite_init_t;

typedef struct mobs {
	int changed_map;
	int draw_mob;
	int mobs_nb;
	int lose;
	int mob_life;
	int mob_dead;
	int witch_dead;
	int stop;
	int stop2;
	int damages;
	clock_s life_lose;
	clock_s mob_shift;
	clock_s mob_dying;
	clock_s mob_damages;
	clock_s witch_shift;
	sprite_init_t zombie;
	sprite_init_t zombie_dying;
	sprite_init_t zombie_damages;
	sprite_init_t witch;
	sprite_init_t witch_dying;
} mobs_t;

void mob_initialisation(mobs_t **, map_t *);
void mob_handling(mobs_t *, rpg_t *, sfRenderWindow *);
int mob_collision(sfVector2f, sfVector2f);
void mob_moving(mobs_t *, sfRenderWindow *, phs_t *, rpg_t *);
void witch_shift(mobs_t *, sfRenderWindow *, phs_t *);
void draw_smoke(mobs_t *, sfRenderWindow *);
void draw_damages(mobs_t *, sfRenderWindow *);
void zombie_initialisation(mobs_t *, map_t *);

#endif
