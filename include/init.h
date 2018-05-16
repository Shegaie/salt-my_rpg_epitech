/*
** EPITECH PROJECT, 2017
** File Name : init.h
** File description:
** Rémi BISSON
*/

#ifndef INIT_H
#define INIT_H

#include "struct.h"

#define BGD "./asset/background.png"
#define BANNER "./asset/shop_text.png"
#define STRENGTH "./asset/strength.png"
#define COOLDOWN "./asset/dash_cooldown.png"
#define MUSIC "./asset/jukebox.png"
#define LPOTION "./asset/life_potion.png"
#define SPOTION "./asset/strength_potion.png"
#define RECEPTACLE "./asset/receptacle_sheet.png"
#define GOLD "./asset/coin.png"
#define INTERACTION "./asset/interaction.png"

#define INVENT "./asset/inventory.png"
#define INVENT_SWORD "./asset/invent_sword.png"

int init_bgd(hud_t *background, hud_t *door);
int init_game(game_t *game);
int init_rpg(rpg_t *rpg);
int init_all(rpg_t *rpg);
int init_physics(phs_t * phs, map_t *map);
int init_player(player_t *player);
int init_shop(shop_t *shop);
void init_life_potion(hud_t *life_potion);
void init_strength_potion(hud_t *strength_potion);
void init_receptacle(square_t *receptacle);
void init_object(hud_t *object, char *filepath, int x, int y);
int init_inventory(inventory_t *inventory);
void init_text(text_t *text);
int init_knight_animation(phs_t *, anim_t *, sfRenderWindow *);
int init_tuto(rpg_t *rpg);

#endif
