#include "shell.h"
#include <stdlib.h>

#define MAX_EXIT_FUNCS 32

typedef void (*ExitFunc)();

static ExitFunc exit_funcs[MAX_EXIT_FUNCS];
static int num_funcs = 0;

int atexit(ExitFunc func)
{
	if (num_funcs < MAX_EXIT_FUNCS)
	{
		exit_funcs[num_funcs++] = func;
		return (0);  // Success
	}
	return (-1);  // Failure (maximum number of registered functions reached)
}

void exit(int status)
{
	// Call the registered functions in reverse order
	for (int i = num_funcs - 1; i >= 0; i--)
	{
		exit_funcs[i]();
	}

	// Terminate the program
	_exit(status);
}

