#include "monty.h"
stack_t *head = NULL;

/**
 * main - start
 * @ac: args number
 * @av: arguments
 *
 * Description: the starting point
 * Return: 0
 */

int main(int ac, char **av)
{
	FILE *fd;
	unsigned int words;
	char *buf, **lines, **cmd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	fseek(fd, 0, SEEK_END);
	words = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	buf = malloc(sizeof(char) * (words + 1));
	if (buf == NULL)
	{
		fclose(fd);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fread(buf, sizeof(char), words, fd);
	*(buf + words) = '\0';
	fclose(fd);
	lines = line_breaker(buf);
	free(buf);
	for (words = 0; lines[words] != NULL; words++)
	{
		cmd = splice(lines[words]);
		if (cmd == NULL)
			continue;
		selector(words + 1, cmd, lines);
		shfree(cmd);
	}
	shfree(lines), free_dlistint(head);
	return (0);
}
