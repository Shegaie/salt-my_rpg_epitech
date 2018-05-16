/*
** EPITECH PROJECT, 2017
** File Name : struct.h
** File description:
** Rémi BISSON
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
//music define//
#define MAIN_MUSIC 0
#define SHOP_MUSIC 1
#define GREG_MUSIC 2
#define REMI_MUSIC 3
#define MATH_MUSIC 4
#define MAISSA_MUSIC 5
#define ABEL_MUSIC 6
#define MUSIC_NB 7
////////////////

typedef struct hud {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
} hud_t;

typedef struct square {
	int cols;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
} square_t;

typedef struct map {
	int s;
	int n;
	int shop;
	int nb_map;
	char **name;
	char ***map;
	square_t **square;
} map_t;

typedef struct physics {
	sfRectangleShape *sqr;
	int is_dash;
	int can_jump;
	int can_dash;
	sfVector2i mouse_pos;
	sfVector2f velocity;
	sfVector2f sqr_size;
	sfVector2f sqr_pos;
	sfVector2f sqr_pos_dash;
	sfVertexArray *part_array;
	sfVector2f *part_pos;
	sfVertexArray *part_array_pause;
	sfVector2f *part_pos_pause;
	sfTexture *dash_txt;
	map_t *map;
} phs_t;

typedef struct clock {
	sfClock *clock;
	sfTime time;
	float seconds;
} clock_s;

typedef struct game {
	clock_s *anim_knight;
	clock_s *cooldown_jump;
	clock_s *cooldown_dash;
	clock_s *cooldown_attack;
	clock_s *anim_attack;
	clock_s *shop_clock;
	clock_s *map;
	int is_attacking;
	int can_attack;
	int map_done;
	int dash_cooldown;
	int is_return;
} game_t;

typedef struct knight_anim {
	sfIntRect knight_r;
	sfTexture *knight_t;
} anim_t;


typedef struct slot {
	hud_t *object;
	int nb_objects;
} slot_t;

typedef struct inventory {
	slot_t *slot1;
	slot_t *slot2;
	slot_t *slot3;
	slot_t *slot4;
	slot_t *slot5;
	hud_t *invent;
} inventory_t;

typedef struct player {
	int nb_gold;
	int nb_lives;
	int max_lives;
	int tmp_lives;
	int strength;
	int tmp_strength;
	hud_t *heart;
	hud_t *half_heart;
	hud_t *empty_heart;
	hud_t *gold;
} player_t;

typedef struct shop {
	hud_t *banner;
	hud_t *strength;
	hud_t *dash_cooldown;
	hud_t *music;
	hud_t *strength_potion;
	hud_t *life_potion;
	hud_t *interaction;
	square_t *seller;
	square_t *receptacle;
	clock_s *buy_clock;
	int can_buy;
} shop_t;

typedef struct text {
	sfVector2f pos;
	sfFont *font;
	sfText *text;
} text_t;

typedef struct tuto {
	hud_t *hud;
} tuto_t;

typedef struct statistic {
	text_t *text;
	hud_t *hud;
	sfRectangleShape *rect;
	sfVector2f r;
} stat_t;

typedef struct rpg {
	sfRenderWindow *window;
	sfMusic **music;
	sfMusic *main_music;
	int shop_music;
	anim_t *knight_a;
	phs_t *phs;
	game_t *game;
	player_t *player;
	hud_t *background;
	hud_t *door;
	map_t *map;
	shop_t *shop;
	text_t *text;
	inventory_t *inventory;
	stat_t *stat;
	tuto_t tuto;
	int tuto_step;
} rpg_t;

#endif
