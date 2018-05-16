/*
** EPITECH PROJECT, 2017
** File Name : draw_text.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void draw_text(sfRenderWindow *window, rpg_t *rpg, char *str, sfVector2f pos)
{
	sfRenderWindow_drawSprite(window, rpg->shop->banner->sprite, NULL);
	rpg->text->pos = pos;
	rpg->text->text = sfText_create();
	sfText_setString(rpg->text->text, str);
	sfText_setFont(rpg->text->text, rpg->text->font);
	sfText_setCharacterSize(rpg->text->text, 28);
	sfText_setPosition(rpg->text->text, rpg->text->pos);
	sfText_setColor(rpg->text->text, sfBlack);
	sfRenderWindow_drawText(window, rpg->text->text, NULL);
	sfText_destroy(rpg->text->text);
}

void draw_text2(rpg_t *rpg, char *str, sfVector2f pos, int size)
{
	rpg->text->pos = pos;
	rpg->text->text = sfText_create();
	sfText_setString(rpg->text->text, str);
	sfText_setFont(rpg->text->text, rpg->text->font);
	sfText_setCharacterSize(rpg->text->text, size);
	sfText_setPosition(rpg->text->text, rpg->text->pos);
	sfText_setColor(rpg->text->text, sfBlack);
	sfRenderWindow_drawText(rpg->window, rpg->text->text, NULL);
	sfText_destroy(rpg->text->text);
}
