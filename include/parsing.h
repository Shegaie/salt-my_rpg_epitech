/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** pars.h
*/

#ifndef PARSING_H
#define PARSING_H

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "struct.h"

#define STONE "./asset/cube.png"
#define WOOD "./asset/wood.png"
#define TORCH "./asset/torch.png"
#define COIN "./asset/coin.png"

#define SQUARE "tc#*"
#define COLS "#*"
#define SPRITE "tc"

void get_name_map(char *, map_t *);
int count_map(char *);
int count_square(char **);
int init_map(map_t *);
void init_map_game(map_t *, int);
void load_map(map_t *);
void set_sprite(square_t *square, char c);
void set_texture(square_t *square, char c);

#endif
