#include "shell.h"

/**
 * copy_string - copies str
 * @csDest: The location
 * @src: the source
 * Return: pointer to destination
 */

char *copy_string(char *csDest, char *src)
{
	int s = 0;

	if (csDest == src || src == 0)
		return (csDest);
	while (src[s])
	{
		csDest[s] = src[s];
		s++;
	}
	csDest[s] = 0;
	return (csDest);
}

/**
 * dup_str - dup a str
 * @ptr: the string to duplicate
 * Return: pointer to the duplicated string
 */

char *dup_str(const char *ptr)
{
	char *obt;
	int size = 0;

	if (ptr == NULL)
		return (NULL);
	while (*ptr++)
		size++;
	obt = malloc(sizeof(char) * (size + 1));
	if (!obt)
		return (NULL);
	for (size++; size--;)
		obt[size] = *--ptr;
	return (obt);
}

/**
 * strPuts - write in str
 * @ptr: str in use
 * Return: Nothing
 */

void strPuts(char *ptr)
{
	int n = 0;

	if (!ptr)
		return;
	while (ptr[n] != '\0')
	{
		putchar_s(ptr[n]);
		n++;
	}
}

/**
 * putchar_s - writes char c to stdout
 * @p: output char
 * Return: On success 1.
 * On error, -1 is returned, and errno is set.
 */

int putchar_s(char p)
{
	static int i;
	static char buf[OUTPUT_BUFFER_SIZE];

	if (p == RESET_BUFFER || i >= OUTPUT_BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (p != RESET_BUFFER)
		buf[i++] = p;
	return (1);
}
