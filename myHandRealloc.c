#include "shell.h"

/**
 * init_Memory - complete mem with cnst byte
 * @s: filling byte
 * @ui: Value of bytes to use
 * @j: points to mem area
 * Return: (s) a pointer to the memory area s
 */

char *init_Memory(char *j, char s, unsigned int ui)
{
	unsigned int i;

	for (i = 0; i < ui; i++)
		j[i] = s;
	return (j);
}

/**
 * mem_free - releases str to str
 * @ss: str of str
 */

void mem_free(char **ss)
{
	char **n = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(n);
}

/**
 * realloc_mem - relocate block of mem
 * @mPtr: pointer to previous malloc'ated block
 * @prev_size: byte size of previous block
 * @new_sz: byte size of new block
 * Return: s
 */
void *realloc_mem(void *mPtr, unsigned int prev_size, unsigned int new_sz)
{
	char *s;

	if (!mPtr)
		return (malloc(new_sz));
	if (!new_sz)
		return (free(mPtr), NULL);
	if (new_sz == prev_size)
		return (mPtr);

	s = malloc(new_sz);
	if (!s)
		return (NULL);

	prev_size = prev_size < new_sz ? prev_size : new_sz;
	while (prev_size--)
		s[prev_size] = ((char *)mPtr)[prev_size];
	free(mPtr);
	return (s);
}
