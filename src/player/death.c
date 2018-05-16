/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** death
*/

#include <unistd.h>
#include "menu.h"
#include "player.h"
#include "mob.h"
#include "draw.h"
#include "init.h"
#include "parsing.h"
#include "free.h"

void damage_taken(rpg_t *rpg, mobs_t *mob)
{
	if (mob->zombie.pos.x - rpg->phs->sqr_pos.x < 0)
		rpg->phs->velocity.x = 10;
	else
		rpg->phs->velocity.x = -10;
	rpg->phs->velocity.y = -20;
}

void display_death(rpg_t *rpg)
{
	sfTexture *death_tx =
	sfTexture_createFromFile("./asset/DeathScreen.png", NULL);
	sfSprite *death_sp = sfSprite_create();

	sfSprite_setTexture(death_sp, death_tx, sfTrue);
	for (int i = 0; i < 10; i++) {
		sfRectangleShape_setRotation(rpg->phs->sqr, 90+(i*(90/10)));
		draw_bgd(rpg->window, rpg->background, rpg->door, 1);
		draw_square(rpg->window, rpg->map, rpg->game);
		sfRenderWindow_drawRectangleShape(rpg->window,
			rpg->phs->sqr, NULL);
		sfRenderWindow_drawSprite(rpg->window, death_sp, NULL);
		sfRenderWindow_display(rpg->window);
		sfSleep((sfTime){100000});
	}
	rpg->game->is_return = 1;
}
