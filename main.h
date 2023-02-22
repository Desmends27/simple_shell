#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
char *hsh_readline();
char **tokenize(char *line);
int launch(char **args, char **env, char *argv);
char *file_check(char *args);
int execute(char **args);
#endif
