#include "main.h"

/**
 * Fork - creates somewhat duplicate process of the calling process
 * The new process is called the child process
 *
 * Return: the process ID of the child process
 */
pid_t Fork(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		unix_error("Fork error");
	}

	return (pid);
}
