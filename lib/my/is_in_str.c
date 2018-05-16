/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** is_in_str.c
*/

#include "lib.h"

int is_in_str(char c, char const *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (0);
	return (1);
}