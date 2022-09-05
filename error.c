#include "main.h"

/**
 * unix_error - outputs error message in stdout when an error occurs
 * @msg: the error message that should be output
 *
 * Return: nothing
 */
void unix_error(char *msg)
{
	_fprintf(STDERR_FILENO, msg);
	_fprintf(STDERR_FILENO, ": ");
	_fprintf(STDERR_FILENO, strerror(errno));
	_fprintf(STDERR_FILENO, "\n");

	exit(EXIT_FAILURE);
}
