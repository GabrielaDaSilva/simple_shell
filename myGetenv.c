#include "shell.h"

/**
 * enviro_ret - returns the string array copy of our environ
 * @data: Holds arg
 * Return: Always 0
 */

char **enviro_ret(data_t *data)
{
	if (!data->environ || data->mod_env)
	{
		data->environ = ls_str(data->env);
		data->mod_env = 0;
	}

	return (data->environ);
}

/**
 * env_deact - delete enviro var
 * @data: struct holding info
 * Return: 1 on delete, 0 otherwise
 * @eVariable: string env var
 */

int env_deact(data_t *data, char *eVariable)
{
	Log_t *node = data->env;
	size_t s = 0;
	char *cP;

	if (!node || !eVariable)
		return (0);

	while (node)
	{
		cP = beginWith(node->cStr, eVariable);
		if (cP && *cP == '=')
		{
			data->mod_env = nodeRem_ind(&(data->env), s);
			s = 0;
			node = data->env;
			continue;
		}
		node = node->next;
		s++;
	}
	return (data->mod_env);
}

/**
 * env_place - set new env var
 * @data: contains info
 * @enVar: str to env var
 * @value: env var value
 * Return: Always 0
 */

int env_place(data_t *data, char *enVar, char *value)
{
	char *buffer = NULL;
	Log_t *node;
	char *pos;

	if (!enVar || !value)
		return (0);

	buffer = malloc(len_string(enVar) + len_string(value) + 2);
	if (!buffer)
		return (1);
	copy_string(buffer, enVar);
	cat_string(buffer, "=");
	cat_string(buffer, value);
	node = data->env;
	while (node)
	{
		pos = beginWith(node->cStr, enVar);
		if (pos && *pos == '=')
		{
			free(node->cStr);
			node->cStr = buffer;
			data->mod_env = 1;
			return (0);
		}
		node = node->next;
	}
	affixFin_node(&(data->env), buffer, 0);
	free(buffer);
	data->mod_env = 1;
	return (0);
}
