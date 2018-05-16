/*
** EPITECH PROJECT, 2017
** File Name : handle_shop.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void handle_1_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum1) &&
		rpg->inventory->slot2->nb_objects > 0 &&
		rpg->shop->can_buy == 1) {
			rpg->inventory->slot2->nb_objects -= 1;
			rpg->shop->can_buy = 0;
			sfClock_restart(rpg->shop->buy_clock->clock);
	}
}

void handle_2_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum2) &&
		rpg->inventory->slot3->nb_objects > 0 &&
		rpg->shop->can_buy == 1 && rpg->player->nb_lives
		!= rpg->player->max_lives) {
			rpg->inventory->slot3->nb_objects -= 1;
			rpg->shop->can_buy = 0;
			rpg->player->nb_lives += 2;
			if (rpg->player->nb_lives > rpg->player->max_lives)
				rpg->player->nb_lives = rpg->player->max_lives;
			sfClock_restart(rpg->shop->buy_clock->clock);
	}
}

void handle_3_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum3) &&
		rpg->inventory->slot4->nb_objects > 0 &&
		rpg->shop->can_buy == 1) {
			rpg->inventory->slot4->nb_objects -= 1;
			rpg->shop->can_buy = 0;
			rpg->player->strength += 5;
			sfClock_restart(rpg->shop->buy_clock->clock);
	}
}

void handle_4_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum4) &&
		rpg->inventory->slot5->nb_objects > 0 &&
		rpg->game->dash_cooldown > 0 &&
		rpg->shop->can_buy == 1) {
			rpg->inventory->slot5->nb_objects -= 1;
			rpg->shop->can_buy = 0;
			rpg->game->dash_cooldown -= 1;
		sfClock_restart(rpg->shop->buy_clock->clock);
	}
}

void handle_inventory(rpg_t *rpg)
{
	handle_1_key(rpg);
	handle_2_key(rpg);
	handle_3_key(rpg);
	handle_4_key(rpg);
}
