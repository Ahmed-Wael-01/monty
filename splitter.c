#include "monty.h"

/**
 * line_len - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int line_len(char *str)
{
	int i;
	int count = 0;

	for (i = 0; str[i] != '\n' && str[i] != '\0'; i++)
		count++;
	return (count);
}

/**
 * line_breaker - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

char **line_breaker(char *str)
{
	char **vessel;
	int i, j, ln = 0;

	i = line_count(str);
	vessel = malloc(sizeof(str) * (i + 1));
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\n')
		{
			j = line_len(&str[i]);
			*(vessel + ln) = malloc(sizeof(char) * (j + 1));
			for (j = 0; str[i] != '\0' && str[i] != '\n'; j++)
			{
				*(*(vessel + ln) + j) = str[i];
				i++;
			}
			*(*(vessel + ln) + j) = '\0';
			i--, ln++;
		}
	}
	*(vessel + ln) = NULL;
	return (vessel);
}

/**
 * word_cnt - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int word_cnt(char *str)
{
	int counter = 0;
	int i = 0;

	if (str[i] == '#')
		return (0);
	if (str[i] != ' ')
		counter++;
	i++;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '#' && str[i - 1] == ' ')
			return (counter);
		if (str[i] != ' ' && str[i] != '\n' && str[i - 1] == ' ')
			counter++;
		i++;
	}
	return (counter);
}

/**
 * word_len - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int word_len(char *str)
{
	int len = 0;

	while (str[len] != '\0' && str[len] != ' '
				&& str[len] != '\n' && str[len] != '$')
		len++;
	return (len);
}

/**
 * splice - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

char **splice(char *str)
{
	int i, j, wn = 0;
	char **vessel;

	i = word_cnt(str);
	if (i == 0 || str[0] == '\n')
		return (NULL);
	vessel = malloc(sizeof(str) * (i + 1));
	for (i = 0; str[i] != '\0' && str[i] != '\n'
			&& str[i] != '#'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '$')
		{
			j = word_len(&str[i]);
			*(vessel + wn) = malloc(sizeof(char) * (j + 1));
			for (j = 0; str[i] != '\0' && str[i] != ' '
				&& str[i] != '\n' && str[i] != '$'
				&& str[i] != '\t'; j++)
			{
				*(*(vessel + wn) + j) = str[i];
				i++;
			}
			*(*(vessel + wn) + j) = '\0';
			i--, wn++;
		}
	}
	*(vessel + wn) = NULL;
	return (vessel);
}
