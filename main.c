#include "main.h"

/**
 * main - the main function
 *
 * Return: 0 on success
 */
int main(void)
{
	size_t bufsize = 100, fetch;
	char *input;
	pid_t n;

	input = malloc(sizeof(char) * bufsize);

	if (input == NULL)
	{
		unix_error("Unable to allocate buffer");
	}
	_printf("# ");
	while ((fetch = getline(&input, &bufsize, stdin)) > 0)
	{
		n = Fork();
		if (n != 0)
		{
			wait(NULL);
			_printf("$ ");
		}
		else
		{
			input[strlen(input) - 1] = '\0';
			run(input);
		}
	}
	return (0);
}
