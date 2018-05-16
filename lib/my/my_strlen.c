/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}
