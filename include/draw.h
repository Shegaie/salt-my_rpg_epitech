/*
** EPITECH PROJECT, 2017
** File Name : draw.h
** File description:
** Rémi BISSON
*/

#ifndef DRAW_H
#define DRAW_H

#include "struct.h"
#include "mob.h"

int draw_bgd(sfRenderWindow *window, hud_t *background, hud_t *door,
int mob_nb);
void draw_game(sfRenderWindow *window, rpg_t *rpg,
anim_t *knight_a, mobs_t *mob);
void draw_shop(sfRenderWindow *window, shop_t *shop, clock_s *shop_clock);
void draw_square(sfRenderWindow *, map_t *, game_t *game);
void draw_gold(sfRenderWindow *window, hud_t *gold);
void draw_inventory(rpg_t *rpg);
void draw_interaction(rpg_t *rpg);

#endif
