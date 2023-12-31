#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for our shell program.
 * @argc: Number of arguments received.
 * @argv: Array of received arguments.
 *
 * Return: 0 on successful exit, otherwise non-zero.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	/* Setting up environment variables */
	char *envp[] = {
		"PATH=/bin:/usr/bin",
		"TERM=xterm",
		NULL
	};

	(void)argc;

	while (1)
	{
		if (prompt_user(&line) <= 0)
		{
			free(line);
			return (0);
		}
		handle_command(line, envp, argv[0]);
		free(line);
		line = NULL;
	}
}
