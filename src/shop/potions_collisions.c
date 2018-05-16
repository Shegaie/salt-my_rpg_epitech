/*
** EPITECH PROJECT, 2017
** File Name : potions_texts.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "shop.h"
#include "physic.h"
#include "draw.h"

void strength_collision(rpg_t *rpg)
{
	char strength[] = "Strength potion. +20 strength for one room.\n\
	                                                      150 Gold";
	if (check_collide(rpg->shop->strength->sprite,
	rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, strength, (sfVector2f){370, 120});
		potion_particles(rpg->phs, rpg->window,
		(sfVector2f){450, 1080-29}, sfRed);
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE)
			&& rpg->player->nb_gold >= 150
			&& rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 150;
			rpg->inventory->slot2->nb_objects += 1;
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void cooldown_collision(rpg_t *rpg)
{
	char cooldown[] = "Weird potion. Reduce dash cooldown by 0,1.\n\
	                                                      150 Gold";
	if (check_collide(rpg->shop->dash_cooldown->sprite,
	rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, cooldown, (sfVector2f){370, 120});
		potion_particles(rpg->phs, rpg->window,
		(sfVector2f){550, 1080-29}, sfBlue);
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE) &&
			rpg->player->nb_gold >= 150 &&
			rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 150;
			rpg->inventory->slot5->nb_objects += 1;
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void life_collision(rpg_t *rpg)
{
	char life[] = "Life potion. Give you 1 heart back.\n\
	                                                      100 Gold";
	if (check_collide(rpg->shop->life_potion->sprite,
		rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, life, (sfVector2f){370, 120});
		potion_particles(rpg->phs, rpg->window,
		(sfVector2f){650, 1080-29}, sfRed);
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE) &&
			rpg->player->nb_gold >= 100 &&
			rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 100;
			rpg->inventory->slot3->nb_objects += 1;
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void strength2_collision(rpg_t *rpg)
{
	char strength2[] = "Strength potion. +5 permanent strength.\n\
	                                                      200 Gold";
	if (check_collide(rpg->shop->strength_potion->sprite,
		rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, strength2, (sfVector2f){370, 120});
		potion_particles(rpg->phs, rpg->window,
		(sfVector2f){750, 1080-29}, sfBlue);
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE) &&
			rpg->player->nb_gold >= 200 &&
			rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 200;
			rpg->inventory->slot4->nb_objects += 1;
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void receptacle_collision(rpg_t *rpg)
{
	char receptacle[] = "Heart receptacle. +1 permanent heart.\n\
	                                                      500 Gold";
	if (check_collide(rpg->shop->receptacle->sprite,
		rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, receptacle, (sfVector2f){370, 120});
		potion_particles(rpg->phs, rpg->window,
		(sfVector2f){850, 1080-29}, sfRed);
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE) &&
			rpg->player->nb_gold >= 500 &&
			rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 500;
			rpg->player->max_lives += 2;
			rpg->player->nb_lives = rpg->player->max_lives;
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}
