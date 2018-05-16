/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** music
*/

#include "struct.h"
#include "player.h"
#include "rpg.h"

int music_handle(rpg_t *rpg)
{
	if (rpg->shop_music == 1) {
		if (sfMusic_getStatus(rpg->music[SHOP_MUSIC]) == sfPlaying) {
			sfMusic_pause(rpg->main_music);
		} else
			sfMusic_play(rpg->music[SHOP_MUSIC]);
	} else {
		if (sfMusic_getStatus(rpg->main_music) == sfPlaying) {
			sfMusic_stop(rpg->music[SHOP_MUSIC]);
		} else
			sfMusic_play(rpg->main_music);
	}
	return (0);
}