/*
** EPITECH PROJECT, 2018
** RPG | draw mobs extra
** File description:
** NOUHAUD Maïssa
*/

#include "mob.h"

void draw_smoke(mobs_t *mob, sfRenderWindow *window)
{
	sfVector2f char_pos = sfSprite_getPosition(mob->zombie.sprite);

	mob->zombie_dying.pos.x = char_pos.x;
	mob->zombie_dying.pos.y = char_pos.y -30;
	sfSprite_setScale(mob->zombie_dying.sprite, (sfVector2f){1.7, 1.7});
	sfSprite_setTextureRect(mob->zombie_dying.sprite,
				mob->zombie_dying.rect);
	sfSprite_setPosition(mob->zombie_dying.sprite, mob->zombie_dying.pos);
	sfRenderWindow_drawSprite(window, mob->zombie_dying.sprite, NULL);
	mob->mob_dying.time = sfClock_getElapsedTime(mob->mob_dying.clock);
	mob->mob_dying.seconds = mob->mob_dying.time.microseconds / 1000000.0;
	if (mob->mob_dying.seconds > 0.2) {
		mob->zombie_dying.rect.left += 50;
		if (mob->zombie_dying.rect.left >= 150) {
			mob->zombie_dying.rect.left = 0;
			mob->stop = 1;
		}
		sfClock_restart(mob->mob_dying.clock);
	}
}

void draw_damages(mobs_t *mob, sfRenderWindow *window)
{
	sfVector2f char_pos = sfSprite_getPosition(mob->zombie.sprite);

	mob->zombie_damages.pos.x = char_pos.x + 10;
	mob->zombie_damages.pos.y = char_pos.y - 10;
	sfSprite_setScale(mob->zombie_damages.sprite, (sfVector2f){1.7, 1.7});
	sfSprite_setTextureRect(mob->zombie_damages.sprite,
				mob->zombie_damages.rect);
	sfSprite_setPosition(mob->zombie_damages.sprite,
			mob->zombie_damages.pos);
	sfRenderWindow_drawSprite(window, mob->zombie_damages.sprite, NULL);
	mob->mob_damages.time = sfClock_getElapsedTime(mob->mob_damages.clock);
	mob->mob_damages.seconds =
		mob->mob_damages.time.microseconds / 1000000.0;
	if (mob->mob_damages.seconds > 0.1) {
		mob->zombie_damages.rect.left += 50;
		if (mob->zombie_damages.rect.left >= 150) {
			mob->zombie_damages.rect.left = 0;
			mob->stop2 = 1;
		}
		sfClock_restart(mob->mob_damages.clock);
	}
}
