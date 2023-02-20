#define MAIN_H
#ifdef MAIN_H
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
char *hsh_readline();
char **tokenize(char *line);
int launch(char **args, char **env, char *argv);
#endif
