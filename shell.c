#include "main.h"

/**
 * prompt - prompts user for command for execution
 *
 * Description: The function starts a shell session and prompts for
 * user commands which are used to create child processes each time
 * of execution and kills each process after execution.
 * Return: 0 on success
 */
int prompt(void)
{
	size_t bufsize = 100, fetch;
	char *input, *path;
	char **av;

	path = malloc(sizeof(char) * 100);
	input = malloc(sizeof(char) * bufsize);
	if (input == NULL || path == NULL)
	{
		unix_error("Unable to allocate buffer");
	}
	_printf("$ ");
	while ((fetch = getline(&input, &bufsize, stdin)) > 0)
	{
		input[_strlen(input) - 1] = '\0';
		av = tokenize(input);
		_strcpy(path, which(av));
		if (_strcmp(path, "(nil)") == 0)
		{
			exec_not_found(av);
		}
		else
		{
			av[0] = path;
			exec_found(av);
		}
	}
	return (0);
}

/**
 * exec_found - Handles the situations where the executable has been found
 * @argv: Array of tokenized commands
 *
 * Description: The function forks child processes when the command is found
 * Return: Nothing
 */
void exec_found(char **argv)
{
	pid_t n;

	n = Fork();
	if (n != 0)
	{
		wait(NULL);
		_printf("$ ");
	}
	else
	{
		if (execve(argv[0], argv, environ) < 0)
		{
			_printf("1");
			_printf("\n");
		}
	}

}

/**
 * exec_not_found - Handles situations where the command has not been found
 * @argv: The array of tokenized commands
 *
 * Return: Nothing
 */
void exec_not_found(char **argv)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		if ((kill(0, SIGKILL)) < 0)
			unix_error("exit failed");
	}

	_printf(argv[0]);
	_printf(": command not found");
	_printf("\n");
	_printf("$ ");
}

/**
 * run - take input from the shell prompt and break it down into atomic size of
 * commands to be fed to the shell background
 * @input: the line from shell prompt
 *
 * Description: Utilizes strtok
 * i) We use single space between prompt string to separate the string
 * in the strtok arguments
 * ii) create argv to be the array to hold commands in atomic form
 * and do a malloc check for it
 * iii) after populating it with given args, ensure argv array is
 * NULL terminated and pass
 * the resultant array argv to which command to check the path of the
 * executable in the given system.
 * Return: nothing
 */
void run(char *input)
{
	Execve(tokenize(input), environ);
}

/**
 * tokenize - breaks down the input into an array of substrings
 * @input: the given input
 *
 * Return: The array of strings or NULL
 */
char **tokenize(char *input)
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

	return (argv);
}
