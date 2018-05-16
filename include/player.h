/*
** EPITECH PROJECT, 2017
** File Name : player.h
** File description:
** Rémi BISSON
*/

#ifndef PLAYER_H
#define PLAYER_H

#define HEART "./asset/heart.png"
#define HALF_HEART "./asset/half_heart.png"
#define EMPTY_HEART "./asset/empty_heart.png"
#include "mob.h"

void display_death(rpg_t *rpg);
int init_player(player_t *player);
int draw_lives(player_t *player, sfRenderWindow *window);
void player_attack(phs_t *player, anim_t *knight_a, game_t *game);
int cooldown(phs_t * phs, game_t * game);
int music_handle(rpg_t *rpg);
int destroy_music(rpg_t *rpg);
void damage_taken(rpg_t *rpg, mobs_t *mob);

#endif
