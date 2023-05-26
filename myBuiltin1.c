#include "shell.h"

/**
 * hist_info - displays the history list
 * @data: Holds arg
 *  Return: Always 0
 */

int hist_info(data_t *data)
{
	sPrint_ls(data->history);
	return (0);
}

/**
 * unset_alias - Places alias to string
 * @str: the string alias
 * @data: store struct
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(data_t *data, char *str)
{
	char *p, s;
	int fetch;

	p = char_string(str, '=');
	if (!p)
		return (1);
	s = *p;
	*p = 0;
	fetch = nodeRem_ind(&(data->alias),
		retInd_node(data->alias, begNode_incl(data->alias, str, -1)));
	*p = s;
	return (fetch);
}

/**
 * set_alias - applies alias on str
 * @str: alias for string
 * @data: stores in struct
 * Return: Always 0 on success, 1 on error
 */

int set_alias(data_t *data, char *str)
{
	char *sa;

	sa = char_string(str, '=');
	if (!sa)
		return (1);
	if (!*++sa)
		return (unset_alias(data, str));

	unset_alias(data, str);
	return (affixFin_node(&(data->alias), str, 0) == NULL);
}

/**
 * print_alias - The alias str will print
 * @node: node to alias
 * Return: 1 on error,Always 0 on success
 */

int print_alias(Log_t *node)
{
	char *an = NULL, *s = NULL;

	if (node)
	{
		an = char_string(node->cStr, '=');
		for (s = node->cStr; s <= an; s++)
		putchar_s(*s);
		putchar_s('\'');
		strPuts(an + 1);
		strPuts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alias_info - shadows alias buitin
 * @data: holds arg.
 *  Return: Always 0
 */
int alias_info(data_t *data)
{
	int j = 0;
	char *ai = NULL;
	Log_t *node = NULL;

	if (data->argc == 1)
	{
		node = data->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; data->argv[j]; j++)
	{
		ai = char_string(data->argv[j], '=');
		if (ai)
			set_alias(data, data->argv[j]);
		else
			print_alias(begNode_incl(data->alias, data->argv[j], '='));
	}

	return (0);
}
