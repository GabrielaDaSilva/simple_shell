#include "shell.h"

/**
 * nodeAffix - makes node a t beginning of list
 * @hNode: pointer add. to hNode
 * @cStr: str field
 * @num: mark node of history
 * Return: size of list
 */

Log_t *nodeAffix(Log_t **hNode, const char *cStr, int num)
{
	Log_t *nHead;

	if (!hNode)
		return (NULL);
	nHead = malloc(sizeof(Log_t));
	if (!nHead)
		return (NULL);
	init_Memory((void *)nHead, 0, sizeof(Log_t));
	nHead->num = num;
	if (cStr)
	{
		nHead->cStr = duplicate_str(cStr);
		if (!nHead->cStr)
		{
			free(nHead);
			return (NULL);
		}
	}
	nHead->next = *hNode;
	*hNode = nHead;
	return (nHead);
}

/**
 * affixFin_node - adds a node to the end of the list
 * @top: address of pointer to head node
 * @cStr: str field of node
 * @s_num: node index used by history
 *
 * Return: size of list
 */
Log_t *affixFin_node(Log_t **top, const char *cStr, int s_num)
{
	Log_t *new_node, *node;

	if (!top)
		return (NULL);

	node = *top;
	new_node = malloc(sizeof(Log_t));
	if (!new_node)
		return (NULL);
	init_Memory((void *)new_node, 0, sizeof(Log_t));
	new_node->s_num = s_num;
	if (cStr)
	{
		new_node->cStr = duplicate_str(cStr);
		if (!new_node->cStr)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*top = new_node;
	return (new_node);
}

/**
 * sPrint_lsString - writes str values only
 * @s: points to 1st node
 * Return: size of list
 */

size_t sPrint_lsString(const Log_t *s)
{
	size_t n = 0;

	while (s)
	{
		strPuts(s->cStr ? s->cStr : "(nil)");
		strPuts("\n");
		s = s->next;
		n++;
	}
	return (n);
}

/**
 * nodeRem_ind - deletes node at given index
 * @upper: 1st node pointer
 * @index: node to be removed
 * Return: 1 on success, 0 on failure
 */

int nodeRem_ind(Log_t **upper, unsigned int index)
{
	Log_t *rmNode, *prev_node;
	unsigned int f = 0;

	if (!upper || !*upper)
		return (0);

	if (!index)
	{
		rmNode = *upper;
		*upper = (*upper)->next;
		free(rmNode->cStr);
		free(rmNode);
		return (1);
	}
	rmNode = *upper;
	while (rmNode)
	{
		if (f == index)
		{
			prev_node->next = rmNode->next;
			free(rmNode->cStr);
			free(rmNode);
			return (1);
		}
		f++;
		prev_node = rmNode;
		rmNode = rmNode->next;
	}
	return (0);
}

/**
 * ls_release - release all nodes
 * @tHead_node: points to the top node
 * Return: void
 */

void ls_release(Log_t **tHead_node)
{
	Log_t *mNode, *fol_node, *top;

	if (!tHead_node || !*tHead_node)
		return;
	top = *tHead_node;
	mNode = top;
	while (mNode)
	{
		fol_node = mNode->next;
		free(mNode->cStr);
		free(mNode);
		mNode = fol_node;
	}
	*tHead_node = NULL;
}
