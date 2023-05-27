#include "shell.h"

/**
 * string_ncopy - copies str
 * @c: total char to be copied
 * @sdestin: destination str to be dup
 * @xsrc: original str
 * Return: the concatenated string
 */

char *string_ncopy(char *sdestin, char *xsrc, int c)
{
	int a, f;
	char *d = sdestin;

	a = 0;
	while (xsrc[a] != '\0' && a < c - 1)
	{
		sdestin[a] = xsrc[a];
		a++;
	}
	if (a < c)
	{
		f = a;
		while (f < c)
		{
			sdestin[f] = '\0';
			f++;
		}
	}
	return (d);
}

/**
 * string_nop - cats 2 str
 * @num: max bytes use
 * @dest1: 1st str
 * @src2: 2nd str
 * Return: the concatenated string
 */

char *string_nop(char *dest1, char *src2, int num)
{
	int a, f;
	char *cs = dest;

	a = 0;
	f = 0;
	while (dest1[a] != '\0')
		a++;
	while (src2[f] != '\0' && f < num)
	{
		dest1[a] = src2[f];
		a++;
		f++;
	}
	if (f < num)
		dest1[a] = '\0';
	return (cs);
}

/**
 * char_string - spots char in a str
 * @ch: char to spot
 * @st: str to be checked
 * Return: (st) a pointer to the memory area s
 */

char *char_string(char *st, char ch)
{
	do {
		if (*st == ch)
			return (st);
	} while (*st++ != '\0');

	return (NULL);
}
