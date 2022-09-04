#include "main.h"

/**
 * run - take input from the shell prompt and break it down into atomic size of
 * commands to be fed to the shell background
 * @input: the line from shell prompt
 *
 * Description: Utilizes sretok
 * i) We use single space between prompt string to separate the string
 * in the strtok arguments
 * ii) create argv to be the array to hold commands in atomic form
 * and do a malloc check for it
 * iii) after populating it with given args, ensure argv array is
 * NULL terminated and pass
 * the resultant array argv to which command to check the path of the
 * executable in the given system.
 */
void run(char *input)
{
	char *token;
	const char separator[2] = " ";
	char **argv;
	int i = 0;

	token = strtok(input, separator);

	argv = malloc(sizeof(char *) * 20);
	if (argv == NULL)
	{
		unix_error("Malloc error");
	}
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	argv[i] = NULL;
	Execve(argv, environ);
}
