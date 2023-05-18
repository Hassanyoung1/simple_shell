#include "shell.h"


int main(int argc, char **argv, char **env)
{
	int i = 0, len = 0, a;
	size_t n = 0;
	char **temp, *path, *new_temp, *str;

	path = getenv("PATH");
	printf("%s: \n", path);

	temp = token_split(path, ":");

	while(temp[i] != NULL)
	{
		printf("%s \n", temp[i]);
		i++;
	}
	i = 0;

	getline(&str, &n, stdin);
	str[strlen(str) - 1] = '\0';
	while(temp[i] != NULL)
	{
		len = strlen(temp[i]);
		new_temp = malloc(sizeof(str) + len + 3);
		strcpy(new_temp, temp[i]);
		new_temp[len] = '/';
		new_temp[len + 1] = *str;
		new_temp[len + 3] = '\0';

		//free(temp[i]);
		temp[i] = new_temp;
		i++;
	}
	a = fork();

	if (a == 0)
	{
		execve(temp[0], temp, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	i = 0;

	while(temp[i] != NULL)
	{
		printf("%s \n", temp[i]);
		i++;
	}
	//getline(&str, &n, stdin);
	//str[strlen(str) - 1] = '\0';


	free_vector(temp);
	return (0);
}
