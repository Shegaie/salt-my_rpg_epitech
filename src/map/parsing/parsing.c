/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** parsing.c
*/

#include "struct.h"
#include "lib.h"
#include "parsing.h"
#include "get_next_line.h"

int count_square(char **array)
{
	int ret = 0;

	for (int i = 0; array[i] != NULL; i++)
		for (int n = 0; array[i][n] != '\0'; n++)
			if (is_in_str(array[i][n], SQUARE) == 0)
				ret++;
	return (ret);
}

void open_file(char *filepath, map_t *map, int n)
{
	int fd = open(filepath, O_RDWR);
	int i = 0;

	map->map[n] = malloc(sizeof(char *) * 18);
	for (char *s = get_next_line(fd); s != NULL; s = get_next_line(fd)) {
		map->map[n][i] = my_strdup(s);
		free(s);
		i++;
	}
	map->map[n][i] = NULL;
	close(fd);
}

int my_strcmp(char *str, char *str2)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] != str2[i])
			return (-1);
	return (0);
}

void pars_map(map_t *map)
{
	int i = 0;

	map->map = malloc(sizeof(char **) * (map->nb_map + 1));
	for (i = 0; map->name[i] != NULL; i++) {
		open_file((char *)(my_strcat("./map/", map->name[i])), map, i);
	}
	map->map[i] = NULL;
	for (int i = 0; map->name[i] != NULL; i++)
		if (my_strcmp(map->name[i], "shop.map") == 0)
			map->shop = i;
}

int init_map(map_t *map)
{
	int i = 0;

	map->nb_map = count_map("./map/");
	if (map->nb_map <= 0)
		return (84);
	get_name_map("./map/", map);
	pars_map(map);
	map->square = malloc(sizeof(square_t *) * (map->nb_map + 1));
	if (map->nb_map > 1)
		for (i = 0; i == map->shop; i = rand() % map->nb_map);
	map->n = i;
	return (0);
}
