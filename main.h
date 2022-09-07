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
#include <stddef.h>
extern char **environ;

/**
 * struct path_s - singly linked list
 * @name: name of path val
 * @val: val in path
 * @next: what our node points to
 *
 * Description: singly linked list node structure
 * used to represent our path
 */
typedef struct path_s
{
	char *name;
	char *val;
	struct path_s *next;
} path_t;


void unix_error(char *msg);
void Execve(char *argv[], char **environ);
pid_t Fork(void);
char *which(char **cmd);
void run(char *input);
int prompt(void);
int check_executable(char buffer, char *args[]);

/*shell funcs*/
void exec_not_found(char **argv);
char **tokenize(char *input);
void exec_found(char **argv);
/* strings */
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src, int n);
char *_strchr(char *s, char c);

/* temporary? printf replacements */
int _strlen(char *s);
void Write(int fd, char *str);
void _fprintf(int fd, char *str);
void _printf(char *str);
/* change the above to _printf function if we can't work with them */

/*environment*/
path_t *get_env(path_t *node, char *name);
path_t *create_path(char **env);
path_t *add_node_end(path_t **head, char *name, char *val);
path_t *find_tail(const path_t *c);
path_t *create_first_node(path_t *head, char *name, char *val);
char *_getenv(char *path_name);
#endif
