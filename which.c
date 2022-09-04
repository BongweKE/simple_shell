#include "main.h"

/**
 * which - soemthing
 * @cmd: path
 *
 * Return: path to executable or (nil)
 */
char *which(char **cmd)
{
	unsigned int i = 0, j = 0, k = 1, l = 1;
	struct stat st;
	char *pth, *token, **path_array;
	char *temp, *argv[3];
	const char separator[2] = ":";

	if (stat(cmd[0], &st) == 0)
		return (cmd[0]);

	path_array = malloc(sizeof(char *) * 20);
	temp = malloc(sizeof(char) * 100);
	if (path_array == NULL)
	{
		fprintf(stderr, "Null malloc error\n");
		exit(EXIT_FAILURE);
	}

	pth = getenv("PATH");
	token = strtok(pth, separator);

	while (token != NULL)
	{
		path_array[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	while (j < i)
	{
		strcat(strcat(strcpy(temp, path_array[j]), "/"), cmd[0]);
		if (stat(temp, &st) == 0)
		{
			return (temp);
		}
		j++;
	}
	fprintf(stderr, "Command '%s' not found\n", cmd[0]);
	return ("(nil)");
}
