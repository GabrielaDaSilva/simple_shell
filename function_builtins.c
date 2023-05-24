#include "Shell.h"

/**
 * ext_out - closes shell
 * @cmd_struct: the env & args
 */

void ext_out(cmd *cmd_struct)
{
	int calculate = 0;

	while (cmd_struct->argv[calculate])
	{
		free(cmd_struct->argv[calculate]);
		calculate++;
	}
	free(cmd_struct);
	exit(0);
}

/**
 * env_cust - env vars will be the output
 * @cmd_struct: args and env inside
 */
void env_cust(cmd *cmd_struct)
{
	int calculate = 0;
	size_t envi_Nsize, num_Lett;
	char lin_Break = '\n';

	while (cmd_struct->env[calculate])
	{
		num_Lett = 0;
		while (cmd_struct->env[calculate][num_Lett])
		{
			num_Lett++;
		}
		envi_Nsize = num_Lett;
		write(STDOUT_FILENO, cmd_struct->env[calculate], envi_Nsize);
		calculate++;
		write(STDOUT_FILENO, &lin_Break, 1);
	}
}
