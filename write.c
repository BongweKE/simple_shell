#include "main.h"


/**
 * _strlen - count the length of a string
 * @s: the string that we want to know the length of
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * Write - call the write function as it's supposed to
 * @fd: file descriptor
 * @str: string to be printed out
 *
 */
void Write(int fd, char *str)
{
	int l;
	ssize_t bytz;
	char *msg = "Problem Creating output\n";

	l = _strlen(str);
	bytz = write(fd, str, (size_t)l);
	if (bytz != (ssize_t)l)
		write(STDERR_FILENO, msg, (size_t)_strlen(msg));
}

/**
 * _printf - call write to print to standard output
 * @str: string to be printed out
 */
void _printf(char *str)
{
	Write(STDOUT_FILENO, str);
}

/**
 * _fprintf - call write function using a given file descriptor
 * @fd: file descriptor
 * @str: strinf to be printed out
 */
void _fprintf(int fd, char *str)
{
	Write(fd, str);
}
