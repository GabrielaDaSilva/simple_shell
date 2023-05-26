#include "shell.h"

/**
 * shell_Exit - Closes the Shell
 * @data: Holds arg
 * Return: exits with exit status
 */

int shell_Exit(data_t *data)
{
	int check_Exit;

	if (data->argv[1]) 
	{
		check_Exit = atoi_Error(data->argv[1]);
		if (check_Exit == -1)
		{
			data->condition = 2;
			list_Err(data, "Illegal number: ");
			str_puts(data->argv[1]);
			sin_putchar('\n');
			return (1);
		}
		data->error_amount = atoi_Error(data->argv[1]);
		return (-2);
	}
	data->error_amount = -1;
	return (-2);
}

/**
 * ch_dir - changes the directory of current proc.
 * @data: Stores arg
 * Return: Always 0
 */

int ch_dir(data_t *data)
{
	char *stri, *directory, buffer[1024];
	int dir_Ch;

	stri = getcwd(buffer, 1024);
	if (!stri)
		strPuts("TODO: >>getcwd failure emsg here<<\n");
	if (!data->argv[1])
	{
		directory = ret_env(data, "HOME=");
		if (!directory)
			dir_Ch = /* TODO: what should this be? */
				chdir((directory = ret_env(data, "PWD=")) ? directory : "/");
		else
			dir_Ch = chdir(directory);
	}
	else if (comp_string(data->argv[1], "-") == 0)
	{
		if (!ret_env(data, "OLDPWD="))
		{
			strPuts(stri);
			putchar_s('\n');
			return (1);
		}
		strPuts(ret_env(data, "OLDPWD=")), putchar_s('\n');
		dir_Ch = /* TODO: what should this be? */
			chdir((directory = ret_env(data, "OLDPWD=")) ? directory : "/");
	}
	else
		dir_Ch = chdir(data->argv[1]);
	if (dir_Ch == -1)
	{
		list_Err(data, "can't cd to ");
		str_puts(data->argv[1]), sin_putchar('\n');
	}
	else
	{
		env_place(data, "OLDPWD", ret_env(data, "PWD="));
		env_place(data, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * assist_s - Current dir changes
 * @data: Stores arg
 * Return: Always 0
 */

int assist_s(data_t *data)
{
	char **arr_argument;

	arr_argument = data->argv;
	strPuts("help call works. Function not yet implemented \n");
	if (0)
		strPuts(*arr_argument); 
	return (0);
}
