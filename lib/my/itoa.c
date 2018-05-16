/*
** EPITECH PROJECT, 2017
** File Name : itoa.c
** File description:
** Rémi BISSON
*/

#include <stdlib.h>
#include "lib.h"

int get_size(int nb)
{
	int i = 0;

	for (i = 0; nb != 0; i++)
		nb = nb / 10;
	return (i);
}

char *str_reverse(char *str)
{
	int j = my_strlen(str);
	int i = 0;
	char *res = malloc(sizeof(char) * (j + 1));

	if (res == NULL)
		return (NULL);
	j--;
	while (str[i] != '\0') {
		res[i] = str[j];
		i++;
		j--;
	}
	res[i] = '\0';
	return (res);
}

char *my_itoa(int nb)
{
	char *res = malloc(sizeof(char) * (get_size(nb) + 2));
	int i = 0;

	if (nb == 0){
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	for (i = 0; nb != 0; i++) {
		res[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	res[i] = '\0';
	return (str_reverse(res));
}
