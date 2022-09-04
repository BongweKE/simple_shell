#include "main.h"

/*
 * Execve - executes a different program in our program
 * @argv: The arguments of that program, including its path as the first index
 * @environ: The environment variables for the program
 *
 * Return: Nothing
 */
void Execve(char *argv[], char **environ)
{
	if (execve(argv[0], argv, environ) < 0)
		unix_error("Execution error");
	exit(0);
}
