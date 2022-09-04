#include "main.h"

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
	which(argv);
} 
