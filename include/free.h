/*
** EPITECH PROJECT, 2017
** File Name : free.h
** File description:
** Rémi BISSON
*/

#ifndef FREE_H
#define FREE_H

#include "struct.h"

void free_all(rpg_t *rpg);
void destroy_all(sfRenderWindow *window, rpg_t *rpg);
void destroy_inventory(inventory_t *inventory);

#endif
