/*
** EPITECH PROJECT, 2018
** NOUHAUD Maïssa
** File description:
** get_next_line improved
*/

#include "get_next_line.h"

static int my_strlen(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}

static char *my_strcat(char *temp, char *buffer)
{
	int len = my_strlen(temp);
	char *str = malloc(sizeof(char) * (len + 2));
	int i = 0;

	while (i < len) {
		str[i] = temp[i];
		i++;
	}
	str[len] = buffer[0];
	str[len + 1] = '\0';
	return (str);
}

char *first_add(char *buffer)
{
	char *str = malloc(sizeof(char) * 2);

	str[0] = buffer[0];
	str[1] = '\0';
	return (str);
}

char *my_realloc(char *temp, char *buffer)
{
	if (temp == NULL)
		temp = first_add(buffer);
	else
		temp = my_strcat(temp, buffer);
	return (temp);
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char) * 1);
	char *temp = NULL;
	ssize_t r;

	while (read(fd, buffer, 1) != 0) {
		temp = my_realloc(temp, buffer);
		if (buffer[0] == '\n')
			return (temp);
	}
}
