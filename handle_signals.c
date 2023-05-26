#include "shell.h"

/**
 * handle_sigs - handles signals
 *
 * @sig_num: siganl number
 * @info: relevant information about signal
 * @contx: context
 */
void handle_sigs(int sig_num, siginfo_t *info, void *contx)
{
	sig_str *sig_cont = (sig_str *)contx;

	(void)sig_num;
	(void)info;
	sig_cont->flag = 1;

	write(1, "\n$ ", 3);
}

/**
 * init_handle_sigs - registers the handle_sigs function and struct
 *
 * @contx: The context
 */
void init_handle_sigs(sig_str *contx)
{
	struct sigaction sig_act;

	(void)contx;
	sig_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sig_act.sa_sigaction = handle_sigs;
	sigemptyset(&sig_act.sa_mask);

	if (sigaction(SIGINT, &sig_act, NULL) == -1)
	{
		perror("signal error");
		exit(EXIT_FAILURE);
	}
}
