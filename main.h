#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

extern char **environ;

void unix_error(char *msg);
void Execve(char *argv[], char **environ);
pid_t Fork(void);
int main(void);
char *which(char **cmd);
void run(char *input);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src, int n);
/* temporary? printf replacements */
int _strlen(char *s);
void Write(int fd, char *str);
void _fprintf(int fd, char *str);
void _printf(char *str);
/* change the above to _printf function if we can't work with them */


#endif
