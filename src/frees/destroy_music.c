/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** music
*/

#include <stdlib.h>
#include "struct.h"
#include "player.h"
#include "rpg.h"

int destroy_music(rpg_t *rpg)
{
	sfMusic_stop(rpg->main_music);
	sfMusic_stop(rpg->music[SHOP_MUSIC]);
	for (int i = 0; i < MUSIC_NB; i++)
		sfMusic_destroy(rpg->music[i]);
	free(rpg->music);
	return (0);
}