/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** physic.h
*/

#ifndef PHYSIC_H
#define PHYSIC_H

#include "struct.h"

#define PART_NB 100
#define PART_NB_PAUSE 100
#define DASH_RANGE 12

int init_physics(phs_t *phs, map_t *);
int physics(sfRenderWindow * window, phs_t *phs, anim_t * knight_a,
	game_t *game);
int cols_params(phs_t *, int, int);
int cols(phs_t *phs);
int mouv(phs_t * phs, anim_t *knight_a, game_t *game);
int dash(sfRenderWindow *, phs_t *, game_t *game);
float launch_dash(phs_t * phs);
int gravity_n_cinetic(phs_t * phs);

//particles functions

int init_vertexArray(phs_t *phs);
int potion_particles(phs_t *phs, sfRenderWindow *window, sfVector2f pos,
sfColor color);
int pause_particles(rpg_t *rpg);
int init_vertexArray_pause(phs_t *phs);

//animation functions

int init_knight_animation(phs_t *phs, anim_t *knight_a, sfRenderWindow *window);
int dash_anime(phs_t * phs, float angle);
int knight_anim_idle(phs_t * phs, anim_t * knight_a);
int apply_anim(phs_t * phs, anim_t * knight_a, game_t *game);

#endif
