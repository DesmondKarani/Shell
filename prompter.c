#include <unistd.h>
#include <stdio.h>
#include "main.h"
/**
 * prompt_user - Prompts the user for input.
 * @lineptr: Pointer to the input line.
 *
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t prompt_user(char **lineptr)
{
	size_t len = 0;
	char prompt[] = "\033[32mBetelgeuse😜\033[0m:\033[34m~\033[0m$ ";

	/* Displaying the shell prompt */
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	/* Reading user's input until newline or EOF */
	return (getline(lineptr, &len, stdin));
}
