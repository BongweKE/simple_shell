#include "main.h"

/**
 * which - soemthing
 * @cmd: the whole prompt to the shell
 *
 * Return: path to executable or (nil)
 */
char *which(char **cmd)
{
	unsigned int i = 0, j = 0;
	struct stat st;
	char *pth, *token, **path_array;
	char *temp;
	const char separator[2] = ":";

	if (stat(cmd[0], &st) == 0)
		return (cmd[0]);

	path_array = malloc(sizeof(char *) * 20);
	temp = malloc(sizeof(char) * 100);
	pth = malloc(sizeof(char) * 100);
	if (path_array == NULL || temp == NULL)
		unix_error("Null malloc error\n");

	pth =  _getenv("PATH");

	token = strtok(pth, separator);

	while (token != NULL)
	{
		path_array[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	while (j < i)
	{
		_strcat(
			_strcat(_strcpy(temp, path_array[j]), "/", 1), cmd[0],
			_strlen(cmd[0]));
		if (stat(temp, &st) == 0)
			return (temp);
		j++;
	}

	_fprintf(STDERR_FILENO, cmd[0]);
	_fprintf(STDERR_FILENO, ": Command not found\n");
	return ("(nil)");
}
