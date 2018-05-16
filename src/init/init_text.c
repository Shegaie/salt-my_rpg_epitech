/*
** EPITECH PROJECT, 2017
** File Name : init_text.c
** File description:
** Rémi BISSON
*/

#include "struct.h"

void init_text(text_t *text)
{
	text->font = sfFont_createFromFile("./asset/fonts/font.otf");
}
