#include "Shell.h"

/**
 * result_ev - Checks if command is a builtin
 * @cmd_struct: The cmd Struct
 * Return: void
 */

void result_ev(cmd *cmd_struct)
{
	char verify_Path[20] = "/bin/", *cur_Path;

	void (*func)(cmd *cmd_struct) = is_builtin(cmd_struct->argv[0]);

	if (func)
	{
		func(cmd_struct);
	}
	else
	{
		cur_Path = process_path(cmd_struct, verify_Path);
		_run(cmd_struct, cur_Path);
	}
}
