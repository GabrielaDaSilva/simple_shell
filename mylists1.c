#include "shell.h"

/**
 * ls_size - Finds size of list
 * @t: directs toward
 * Return: size of list
 */

size_t ls_size(const Log_t *t)
{
	size_t n = 0;

	while (t)
	{
		t = t->next;
		n++;
	}
	return (n);
}

/**
 * ls_str - gives array of str
 * @high: pointer to first node
 * Return: array of strings
 */

char **ls_str(Log_t *high)
{
	Log_t *node = high;
	char **strs;
	size_t n = ls_snze(high), s;
	char *chStr;

	if (!high || !n)
		return (NULL);
	strs = malloc(sizeof(char *) * (n + 1));
	if (!strs)
		return (NULL);
	for (n = 0; node; node = node->next, n++)
	{
		chStr = malloc(_cStrlen(node->chStr) + 1);
		if (!chStr)
		{
			for (s = 0; s < n; s++)
				free(strs[s]);
			free(strs);
			return (NULL);
		}

		chStr = copy_string(chStr, node->chStr);
		strs[n] = chStr;
	}
	strs[n] = NULL;
	return (strs);
}


/**
 * sPrint_ls - prints every value in list
 * @s: points to 1st node
 * Return: size of list
 */

size_t sPrint_ls(const Log_t *s)
{
	size_t n = 0;

	while (s)
	{
		strPuts(num_change(s->number, 10, 0));
		putchar_s(':');
		putchar_s(' ');
		strPuts(s->cStr ? s->cStr : "(nil)");
		strPuts("\n");
		s = s->next;
		n++;
	}
	return (n);
}

/**
 * begNode_incl - returns node whose string starts with prefix
 * @nodeHead: pointer to list head
 * @matchStr: string to match
 * @s: following char after matchStr to match
 * Return: match nodeHead or null
 */

Log_t *begNode_incl(Log_t *nodeHead, char *matchStr, char s)
{
	char *ptr = NULL;

	while (nodeHead)
	{
		ptr = beginWith(nodeHead->cStr, matchStr);
		if (ptr && ((s == -1) || (*ptr == s)))
			return (nodeHead);
		nodeHead = nodeHead->next;
	}
	return (NULL);
}

/**
 * retInd_node - retrieves pos.
 * @highest: points to head
 * @pNode: points to pNode
 * Return: index of pNode or -1
 */

ssize_t retInd_node(Log_t *highest, Log_t *pNode)
{
	size_t n = 0;

	while (highest)
	{
		if (highest == pNode)
			return (n);
		highest = highest->next;
		n++;
	}
	return (-1);
}
