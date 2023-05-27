#include "shell.h"

/**
 * Shell_loop - shell main loop
 * @data: return and para info
 * @av: arg vector from main()
 * Return: 0 on success, 1 on error, or error code
 */

int Shell_loop(data_t *data, char **av)
{
	ssize_t n = 0;
	int retBuiltin = 0;

	while (n != -1 && retBuiltin != -2)
	{
		_emptyInf(data);
		if (inter_Mode(data))
			strPuts("$ ");
		sin_putchar(RESET_BUFFER);
		n = gStore(data);
		if (n != -1)
		{
			_configInf(data, av);
			retBuiltin = locBuiltin(data);
			if (retBuiltin == -1)
				locateCmd(data);
		}
		else if (inter_Mode(data))
			putchar_s('\n');
		_relinf(data, 0);
	}
	histWr(data);
	_relinf(data, 1);
	if (!inter_Mode(data) && data->condition)
		exit(data->condition);
	if (retBuiltin == -2)
	{
		if (data->error_amount == -1)
			exit(data->condition);
		exit(data->error_amount);
	}
	return (retBuiltin);
}

/**
 * locBuiltin - locates a builtin cmd
 * @data: return and para for info
 * Return: -1 if builtin not found,
 * 0 if builtin executed successfully,
 * 1 if builtin found but not successful,
 * 2 if builtin signals exit()
 */

int locBuiltin(data_t *data)
{
	int n, built_in_ret = -1;
	log_builtin builtintbl[] = {
		{"exit", shell_Exit},
		{"env", env_cust},
		{"help", assist_s},
		{"history", hist_info},
		{"setenv", config_env},
		{"unsetenv", unstow_env},
		{"cd", ch_dir},
		{"alias", alias_info},
		{NULL, NULL}
	};

	for (n = 0; builtintbl[i].class; n++)
		if (comp_string(data->argv[0], builtintbl[i].class) == 0)
		{
			data->calcu_lin++;
			built_in_ret = builtintbl[n].func(data);
			break;
		}
	return (built_in_ret);
}

/**
 * locateCmd - locations path to cmd
 * @data: return and parameter info
 * Return: void
 */

void locateCmd(data_t *data)
{
	char *cPath = NULL;
	int i, k;

	data->cPath = data->argv[0];
	if (data->calcLin_flg == 1)
	{
		data->calcu_lin++;
		data->calcLin_flg = 0;
	}
	for (i = 0, k = 0; data->arg[i]; i++)
		if (!deli_Meter(data->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	cPath = search_cmd_path(data, ret_env(data, "PATH="), data->argv[0]);
	if (cPath)
	{
		data->cPath = cPath;
		forkCom(data);
	}
	else
	{
		if ((inter_Mode(data) || ret_env(data, "PATH=")
					|| data->argv[0][0] == '/') && check_command(data, data->argv[0]))
			forkCom(data);
		else if (*(data->arg) != '\n')
		{
			data->condition = 127;
			list_Err(data, "not found\n");
		}
	}
}

/**
 * forkCom - forks exec. to run cmd
 * @data: parameter & return info
 * Return: void
 */

void forkCom(data_t *data)
{
	pid_t mychild_pid;

	mychild_pid = fork();
	if (mychild_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (mychild_pid == 0)
	{
		if (execve(data->path, data->argv, enviro_ret(data)) == -1)
		{
			_relinf(data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

	}
	else
	{
		wait(&(data->condition));
		if (WIFEXITED(data->condition))
		{
			data->condition = WEXITSTATUS(data->condition);
			if (data->condition == 126)
				list_Err(data, "Permission denied\n");
		}
	}
}
