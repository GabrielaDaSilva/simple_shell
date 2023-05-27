#include "shell.h"

/**
 *  inter_Mode - When in interactive mode will ret 1
 * @iData: struct address
 *
 * Return: 0 otherwise, 1 if interactive mode
 */

int  inter_Mode(data_t *iData)
{
	return (isatty(STDIN_FILENO) && iData->scan_fdesc <= 2);
}

/**
 * deli_Meter - validate is char a delim
 * @delim: the delim str
 * @d: the var to validate
 * Return: 0 if false, 1 true
 */

int deli_Meter(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 * valAlpha - looks for alpha char
 * @d: char given
 * Return: 0 otherwise, 1 c is alphabetic
 */

int valAlpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * nAtoi_cust - change str to int
 * @k: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int nAtoi_cust(char *k)
{
	int j, indicate = 1, fmark = 0, result_out;
	unsigned int result = 0;

	for (j = 0; k[j] != '\0' && fmark != 2; j++)
	{
		if (k[j] == '-')
			indicate *= -1;

		if (k[j] >= '0' && k[j] <= '9')
		{
			fmark = 1;
			result *= 10;
			result += (k[j] - '0');
		}
		else if (fmark == 1)
			fmark = 2;
	}

	if (indicate == -1)
		result_out = -result;
	else
		result_out = result;

	return (result_out);
}
