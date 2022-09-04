#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern char **environ;

void unix_error(char *msg);
void Execve(char *argv[], char **environ);
pid_t Fork(void);
int main(void);
char *which(char **cmd);
void run(char *input);
#endif
