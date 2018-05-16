/*
** EPITECH PROJECT, 2017
** File Name : my_strdup.c
** File description:
** Rémi BISSON
*/

#include "lib.h"

char *my_strdup(char *str)
{
	int i = 0;
	char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (res == NULL)
		return (NULL);
	while (str[i] != '\0') {
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
