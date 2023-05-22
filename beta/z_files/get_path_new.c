#include "shell.h"

char *path_get_new(char *command)
{
	char **path_holder, *path_copy;
	char exec_path[100];
	char *holder = NULL;  // Declare holder before the loop
	int i = 0;

	char *path = getenv("PATH");
	if (path == NULL)
		return NULL;

	path_copy = strdup(path);
	if (path_copy == NULL)
		return NULL;

	path_holder = token_split(path_copy, ":");
	if (path_holder == NULL)
	{
		free_vector(path_holder);
		return (NULL);
	}

	while (path_holder[i] != NULL)
	{
		strcpy(exec_path, path_holder[i]);
		strcat(exec_path, "/");
		strcat(exec_path, command);
		strcat(exec_path, "\0");

		if (access(exec_path, X_OK) == 0)
		{
			holder = strdup(exec_path);
			printf("concatenated str is: %s\n", holder);

			break;  // Exit the loop once a valid path is found
		}
		i++;
	}
	//free_vector(path_holder);
	free(path_copy);

	if (holder == NULL)
		return NULL;

	return (holder);
}
