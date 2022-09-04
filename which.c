#include "main.h"
void stat_check(char **args, char **argv, char **cmd);
void which(char **cmd)
{	
        unsigned int i = 0, j = 0, k = 1, l = 1;
        struct stat st;
        char *pth, *token, **path_array;
        char temp[50], *argv[3];
        extern char **environ;
        const char separator[2] = ":";

	if (stat(cmd[0], &st) == 0)
        {
               	argv[0] = cmd[1];
               	while (cmd[k] != NULL)
                {
                     	argv[l] = cmd[k];
                        l++;
                        k++;
                }
                argv[l] = NULL;
                Execve(argv, environ);
        }
        path_array = malloc(sizeof(char *) * 20);
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
                	argv[0] = temp;
                	while (cmd[k] != NULL)
                	{
                        	argv[l] = cmd[k];
                        	l++;
                        	k++;
                	}
                	argv[l] = NULL;
                	Execve(argv, environ);
			break;
        	}
		j++;
        }
        printf("Command '%s' not found\n", cmd[0]);

        exit(0);
}
