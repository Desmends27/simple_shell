#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
char *readline(int *eof);
char **tokenize(char *line);
int launch(char **args, char **env, char *argv);
int hsh_execute(char **args, char **env, char *argv);
char *file_check(char *args);

int hsh_exit(char **args);
int hsh_env(char **args);
int hsh_cd(char **args);
#endif

