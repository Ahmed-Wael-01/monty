#include "monty.h"

/**
 * _strcmp - does something
 * @s1: a variable
 * @s2: a variable
 *
 * Description: a function
 * Return: dest
*/

int _strcmp(char *s1, char *s2)
{
	int i;
	int fstr;
	int scstr;

	fstr = _strlen(s1);
	scstr = _strlen(s2);

	if (fstr > scstr)
		return (fstr - scstr);
	if (scstr > fstr)
		return (scstr - fstr);

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strlen - does something
 * @s: a variable
 *
 * Description: a function
 * Return: 0
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcpy - does something
 * @dest: a variable
 * @src: a variable
 *
 * Description: a function
 * Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - does something
 * @dest: a variable
 * @src: a variable
 *
 * Description: a function
 * Return: dest
*/

char *_strcat(char *dest, char *src)
{
	int i = 0, counter = 0;

	while (dest[counter] != '\0')
		counter++;
	while (src[i] != '\0')
	{
		dest[counter + i] = src[i];
		i++;
	}
	dest[counter + i] = '\0';
	return (dest);
}

/**
 * line_count - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int line_count(char *str)
{
	int i;
	int counter = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
			counter++;
	}
	return (counter);
}
