#include "shell.h"

/**
 * ptr_free - release the pointer
 * @freePtr: location of pointer to release
 * Return: 1 if freed, otherwise 0.
 */

int ptr_free(void **freePtr)
{
	if (freePtr && *freePtr)
	{
		free(*freePtr);
		*freePtr = NULL;
		return (1);
	}
	return (0);
}
