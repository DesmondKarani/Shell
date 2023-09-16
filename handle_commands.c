#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * handle_command - Handles the user's command input.
 * @buffer: Input buffer.
 * @envp: Environment variables.
 * @program_name: Name of the program.
 */
void handle_command(char *buffer, char **envp, char *program_name)
{
	char **args = NULL;

	/* Check for "exit" command */
	if (strtok(buffer, " \n") && (strncmp(buffer, "exit", 4) == 0))
	{
		free(args); /* Clean up any allocated memory */
		_exit(0); /* Exit the shell */
	}

	/* Tokenize the input buffer to separate command and arguments */
	tokenize_input(buffer, &args);

	/* Execute the parsed command */
	execute_command(args, envp, program_name);

	/* Free the memory allocated for the arguments */
	free(args);
}
