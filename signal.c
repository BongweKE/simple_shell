#include "main.h"

/**
 * Kill - executes the kill signal on the specified process
 * @pid: the process ID of the process to be killed
 *
 * Return: 0 on success
 */
int Kill(pid_t pid)
{
	if ((kill(pid, SIGINT)) < 0)
		unix_error("exit failed");

	return (0);
}
