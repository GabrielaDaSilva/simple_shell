#include "shell_header.h"

/**
* eval – Determines whether the command is builtin,
* system or invalid and takes action.
* @cmd_struct: command structure.
* Return: void.
*/

void eval(cmd *cmd_struct)
{
	char checkpath[20] = "/bin/", *new_path;
	void (*func)(cmd *cmd_struct) = is_builtin(cmd_struct->argv[0]);

	if (func)
	{
		func(cmd_struct);
	}
	else
	{
		new_path = handle_path(cmd_struct, checkpath);
		execute(cmd_struct, new_path);
	}
}
