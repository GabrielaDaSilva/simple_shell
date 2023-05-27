#include "shell.h"

/**
 * _emptyInf - sets data_t struct
 * @data: the address
 */

void _emptyInf(data_t *data)
{
	data->arg = NULL;
	data->argv = NULL;
	data->path = NULL;
	data->argc = 0;
}

/**
 * _configInf - set data_t struct
 * @data: struct address
 * @arg_vect: argument vector
 */

void _configInf(data_t *data, char **arg_vect)
{
	int n = 0;

	data->tagFlg = arg_vect[0];
	if (data->arg)
	{
		data->argv = token_string(data->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = duplicate_str(data->arg);
				data->argv[1] = NULL;
			}
		}
		for (n = 0; data->argv && data->argv[n]; n++)
			;
		data->argc = n;

		sub_alias(data);
		sub_vars(data);
	}
}

/**
 * _relinf - releases data_t struct
 * @data: struct address
 * @entire: true if freeing all fields
 */

void _relinf(data_t *data, int entire)
{
	mem_free(data->argv);
	data->argv = NULL;
	data->path = NULL;

	if (entire)
	{
		if (!data->buff_command)
			free(data->arg);
		if (data->env)
			ls_release(&(data->env));
		if (data->history)
			ls_release(&(data->history));
		if (data->alias)
			ls_release(&(data->alias));
		mem_free(data->environ);
			data->environ = NULL;
		ptr_free((void **)data->buff_command);
		if (data->scan_fdesc > 2)
			close(data->scan_fdesc);
		putchar_s(RESET_BUFFER);
	}
}
