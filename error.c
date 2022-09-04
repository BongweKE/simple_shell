#include "main.h"

/**
 * unix_error - outputs error message in stdout when an error occurs
 * @msg: the error message that should be output
 *
 * Return: nothing
 */
void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}
