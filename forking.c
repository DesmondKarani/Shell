#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * execute_command - Executes the provided command.
 * @args: The tokenized arguments from the input buffer.
 * @envp: Environment variables.
 * @program_name: The name of this shell program (argv[0]).
 */
void execute_command(char **args, char **envp, char *program_name)
{
	pid_t pid;

	/* Attempt to fork the process */
	pid = fork();
	if (pid == 0) /* Child process */
	{
		/* Attempt to execute the command */
		execve(args[0], args, envp);

		/* If command doesn't execute, print error message */
		write(STDOUT_FILENO, program_name, strlen(program_name));
		write(STDOUT_FILENO, ": 1: ", 6);
		write(STDOUT_FILENO, args[0], strlen(args[0]));
		write(STDOUT_FILENO, ": not found\n", 12);
		_exit(1);
	}
	else if (pid < 0) /* Forking failed */
	{
		write(STDOUT_FILENO, "Error forking\n", 14);
		_exit(-1);
	}
	else /* Parent process */
	{
		/* Wait for the child process to complete */
		wait(NULL);
	}
}
