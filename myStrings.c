#include "shell.h"

/**
 * len_string - returns size of str
 * @n: str to check
 * Return: integer length of string
 */

int len_string(char *n)
{
	int a = 0;

	if (!n)
		return (0);

	while (*n++)
		a++;
	return (a);
}

/**
 * comp_string - comparisons from two strings
 * @c1: 1st str
 * @c2: 2nd str
 * Return: negative if c1 < c2, positive if c1 > c2, zero if c1 == c2
 */

int comp_string(char *c1, char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	if (*c1 == *c2)
		return (0);
	else
		return (*c1 < *c2 ? -1 : 1);
}

/**
 * beginWith - ascertains if needle starts with haystack
 * @needle: substr to lcoate
 * @haystack: search str
 * Return: address of next char of haystack or NULL
 */

char *beginWith(const char *haystack, const char *needle)
{
	for (; *needle; ++needle, ++haystack)
	{
	if (*needle != *haystack)
		return (NULL);
	}
	return ((char *)(haystack));
}

/**
 * cat_string - cats 2 str
 * @strdest: str dest buffer
 * @mainbuf: main buffer
 * Return: pointer to destination buffer
 */

char *cat_string(char *strdest, char *mainbuf)
{
	char *csRet = strdest;

	while (*strdest)
		strdest++;
	while (*mainbuf)
		*strdest++ = *src++;
	*strdest = *mainbuf;
	return (csRet);
}
