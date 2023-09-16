#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * tokenize_input - Tokenizes the input buffer into arguments.
 * @buffer: Input buffer containing the command.
 * @args: Double pointer for storing the tokenized arguments.
 */
void tokenize_input(char *buffer, char ***args)
{
	int i = 0;
	char *token;

	/* Allocate memory for a list of arguments */
	*args = malloc(sizeof(char *) * 100);
	if (*args == NULL) /* Check if memory allocation was successful */
		exit(EXIT_FAILURE);

	/* Begin tokenizing the buffer with space and newline as delimiters */
	token = strtok(buffer, " \n");
	while (token)
	{
		(*args)[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}

	/* Terminate the list of arguments with a NULL pointer */
	(*args)[i] = NULL;
}
