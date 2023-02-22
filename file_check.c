#include "shell.h"
/**
 * file_check - checks for commands in /bin
 * @args: command to be searched for
 * Return: Apped the required path or null
 */
char *file_check(char *args)
{
	DIR *dir;
	char *cat;
	struct dirent *entity;

	if (access(args, X_OK) != -1)
	{
		return (args);
	}
	dir = opendir("/bin/");
	if (dir == NULL)
	{
		return (NULL);
	}
	/* read the directory */
	entity = readdir(dir);

	/* search for file */
	while ((entity = readdir(dir)) != NULL)
	{
		if (strcmp(entity->d_name, args) == 0)
		{
			cat = malloc(strlen("/bin/") + strlen(args) + 1);
			if (cat == NULL)
			{
				closedir(dir);
				return (NULL);
			}
			strcpy(cat, "/bin/");
			strcat(cat, args);
			closedir(dir);
			return (cat);
		}
	}
	closedir(dir);
	return (NULL);
}
