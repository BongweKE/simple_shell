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

	if (_strcmp(argv[0], "exit") == 0)
	{
		if ((kill(0, SIGKILL)) < 0)
			unix_error("exit failed");
	}

	temp = malloc(sizeof(char) * 100);
	if (temp == NULL)
	{
		unix_error("Malloc error");
	}
	
	_strcpy(temp, which(argv));

	if (_strcmp(temp, "(nil)") == 0)
	{
		unix_error(argv[0]);
	}

	if (execve(temp, argv, environ) < 0)
		unix_error("Execution error");
	exit(0);
}
