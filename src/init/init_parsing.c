/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** init_parsing.c
*/

#include "struct.h"
#include "lib.h"
#include "parsing.h"

int check_ext(char *str)
{
	int i = 0;
	int ret = 0;
	char str2[] = ".map";

	for (i = 0; str[i] != '.'; i++);
	while (str[i] == str2[ret]) {
		ret++;
		i++;
	}
	if (ret == 5)
		return (0);
	return (1);
}

int count_map(char *filepath)
{
	int i = 0;
	DIR *rep = opendir(filepath);
	struct dirent *ent;

	if (rep == NULL)
		return (-1);
	while ((ent = readdir(rep)) != NULL) {
		if (ent->d_name[0] != '.' &&
		check_ext(ent->d_name) == 0)
			i++;
	}
	closedir(rep);
	return (i);
}

void get_name_map(char *filepath, map_t *map)
{
	int i = 0;
	DIR *rep2 = opendir(filepath);
	struct dirent *ent2;

	map->name = malloc(sizeof(char *) * (map->nb_map + 1));
	while ((ent2 = readdir(rep2)) != NULL) {
		if (ent2->d_name[0] != '.' &&
		check_ext(ent2->d_name) == 0) {
			map->name[i] = my_strdup(ent2->d_name);
			i++;
		}
	}
	map->name[i] = NULL;
	closedir(rep2);
}
