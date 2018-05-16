/*
** EPITECH PROJECT, 2017
** File Name : music_texts.c
** File description:
** Rémi BISSON
*/

#include "struct.h"
#include "shop.h"
#include "draw.h"

void greg_music_collision(rpg_t *rpg)
{
	char greg[] = "Change game music. In progress.\n\
	                                    500 Gold";
	if (check_collide(rpg->shop->music[0].sprite, rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, greg, (sfVector2f){370, 120});
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE)
			&& rpg->player->nb_gold >= 500
			&& rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 500;
			rpg->main_music = rpg->music[GREG_MUSIC];
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void maissa_music_collision(rpg_t *rpg)
{
	char maissa[] = "Change game music. Nous aurons tous les pouvoirs.\n\
	                                    500 Gold";
	if (check_collide(rpg->shop->music[1].sprite, rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, maissa, (sfVector2f){370, 120});
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE)
			&& rpg->player->nb_gold >= 500
			&& rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 500;
			rpg->main_music = rpg->music[MAISSA_MUSIC];
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void mathieu_music_collision(rpg_t *rpg)
{
	char mathieu[] = "Change game music. Fus Roh Da.\n\
	                                    500 Gold";
	if (check_collide(rpg->shop->music[2].sprite, rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, mathieu, (sfVector2f){370, 120});
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE)
			&& rpg->player->nb_gold >= 500
			&& rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 500;
			rpg->main_music = rpg->music[MATH_MUSIC];
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void remi_music_collision(rpg_t *rpg)
{
	char remi[] = "Change game music. Just enjoy it.\n\
	                                    500 Gold";
	if (check_collide(rpg->shop->music[3].sprite, rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, remi, (sfVector2f){370, 120});
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE)
			&& rpg->player->nb_gold >= 500
			&& rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 500;
			rpg->main_music = rpg->music[REMI_MUSIC];
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}

void abel_music_collision(rpg_t *rpg)
{
	char abel[] = "Change game music. Sounds like Tetris.\n\
	                                   5000 Gold";
	if (check_collide(rpg->shop->music[4].sprite, rpg->phs->sqr_pos) == 1) {
		draw_text(rpg->window, rpg, abel, (sfVector2f){370, 120});
		draw_interaction(rpg);
		if (sfKeyboard_isKeyPressed(sfKeyE)
			&& rpg->player->nb_gold >= 5000
			&& rpg->shop->can_buy == 1) {
			rpg->player->nb_gold -= 5000;
			rpg->main_music = rpg->music[ABEL_MUSIC];
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
		}
	}
}
