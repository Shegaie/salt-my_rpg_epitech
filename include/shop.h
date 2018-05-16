/*
** EPITECH PROJECT, 2017
** File Name : shop.h
** File description:
** Rémi BISSON
*/

#ifndef SHOP_H
#define SHOP_H

#include "struct.h"

int shop(rpg_t *rpg);
void draw_text(sfRenderWindow *window, rpg_t *rpg, char *str, sfVector2f pos);
void draw_text2(rpg_t *rpg, char *str, sfVector2f pos, int size);
int check_collide(sfSprite *sprite, sfVector2f pos);
void greg_music_collision(rpg_t *rpg);
void maissa_music_collision(rpg_t *rpg);
void mathieu_music_collision(rpg_t *rpg);
void remi_music_collision(rpg_t *rpg);
void abel_music_collision(rpg_t *rpg);
void strength_collision(rpg_t *rpg);
void cooldown_collision(rpg_t *rpg);
void life_collision(rpg_t *rpg);
void strength2_collision(rpg_t *rpg);
void receptacle_collision(rpg_t *rpg);
void handle_inventory(rpg_t *rpg);
void handle_buy_clock(shop_t *shop);

#endif
