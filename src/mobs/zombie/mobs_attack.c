/*
** EPITECH PROJECT, 2018
** RPG | mobs attack
** File description:
** NOUHAUD Maïssa
*/

#include <unistd.h>
#include "player.h"
#include "menu.h"
#include "mob.h"
#include "draw.h"
#include "init.h"
#include "parsing.h"
#include "free.h"

int mob_collision(sfVector2f m_pos, sfVector2f c_pos)
{
	if ((m_pos.x <= c_pos.x + 70)
	&& (m_pos.x + 70 >= c_pos.x)
	&& (m_pos.y <= c_pos.y + 70)
	&& (m_pos.y + 70 >= c_pos.y))
		return (1);
	return (0);
}

void lose_life(mobs_t *mob)
{
	mob->life_lose.time = sfClock_getElapsedTime(mob->life_lose.clock);
	mob->life_lose.seconds =
		mob->life_lose.time.microseconds / 1000000.0;
	if (mob->life_lose.seconds > 0.7)
		mob->lose = 1;
}

void death_handling(mobs_t *mob, rpg_t *rpg)
{
	static int i = 0;
	int gold = rand() % 30;

	if ((rpg->phs->is_dash == 0 && mob->mob_dead == 0) &&
	(rpg->game->is_attacking == 0 && mob->mob_dead == 0)) {
		rpg->player->nb_lives--;
		damage_taken(rpg, mob);
		if (rpg->player->nb_lives == 0)
			display_death(rpg);
		mob->lose = 0;
		sfClock_restart(mob->life_lose.clock);
	} else {
		i += rpg->player->strength + rpg->player->tmp_strength;
		mob->damages = 1;
		mob->stop2 = 0;
		if (i >= mob->mob_life) {
			mob->mobs_nb -= 1;
			mob->mob_dead = 1;
			rpg->player->nb_gold += gold;
			i = 0;
		}
		mob->lose = 0;
		sfClock_restart(mob->life_lose.clock);
	}
}

void mob_attack(mobs_t *mob, rpg_t *rpg)
{
	sfVector2f mob_position;
	sfVector2f char_position;

	mob_position = sfSprite_getPosition(mob->zombie.sprite);
	char_position = sfRectangleShape_getPosition(rpg->phs->sqr);
	if (mob_collision(mob_position, char_position) == 1)
		lose_life(mob);
	if (mob->lose == 1)
		death_handling(mob, rpg);
	if (mob->damages > 0 && mob->stop2 == 0 && mob->mob_dead == 0)
		draw_damages(mob, rpg->window);
	if (mob->mob_dead == 1 && mob->stop == 0)
		draw_smoke(mob, rpg->window);
}

void mob_handling(mobs_t *mob, rpg_t *rpg, sfRenderWindow *window)
{
	int i = 0;
	int j = 0;

	while (j < 6) {
		mob_moving(&mob[i], window, rpg->phs, rpg);
		mob_attack(&mob[i], rpg);
		i++;
		j++;
	}
}
