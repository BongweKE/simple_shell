#include "main.h"

/**
 * Execve - executes a different program in our program
 * @argv: The arguments of that program, including its path as the first index
 * @environ: The environment variables for the program
 *
 * Return: Nothing
 */
void Execve(char *argv[], char **environ)
{
	char *temp;

	strcpy(temp, which(argv));

	if (strcmp(temp, "(nil)") == 0)
	{
		unix_error("command not found");
	}

	if (execve(temp, argv, environ) < 0)
		unix_error("Execution error");
	exit(0);
}
