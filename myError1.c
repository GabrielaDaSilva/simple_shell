#include "shell.h"

/**
 * atoi_Error - changes a str to int
 * @at: string to be changed
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int atoi_Error(char *at)
{
	unsigned long int outcome = 0;
	int n = 0;

	if (*at == '+')
		at++;
	for (n = 0;  at[n] != '\0'; n++)
	{
		if (at[n] >= '0' && at[n] <= '9')
		{
			outcome *= 10;
			outcome += (at[n] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outcome);
}

/**
 * list_Err - Writes err message
 * @erstr: str with certain error type
 * @data: para and return
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */

void list_Err(data_t *data, char *erstr)
{
	str_puts(data->tagFlg);
	str_puts(": ");
	dprint(data->calcu_lin, STDERR_FILENO);
	str_puts(": ");
	str_puts(data->argv[0]);
	str_puts(": ");
	str_puts(erstr);
}

/**
 * dprint - prints decimal with base 10
 * @fdes: filedescriptor to write
 * @feed: the input
 * Return: number of characters printed
 */

int dprint(int feed, int fdes)
{
	int (*__putchar)(char) = putchar_s;
	unsigned int _ser_, current;
	int k, calculate = 0;

	if (fdes == STDERR_FILENO)
		__putchar = sin_putchar;
	if (feed < 0)
	{
		_ser_ = -feed;
		__putchar('-');
		calculate++;
	}
	else
		_ser_ = feed;
	current = _ser_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_ser_ / k)
		{
			__putchar('0' + current / k);
			calculate++;
		}
		current %= k;
	}
	__putchar('0' + current);
	calculate++;

	return (calculate);
}

/**
 * num_change - function that converts
 * @foundation: Use base
 * @flags: flags for arg
 * @number: The number
 * Return: string
 */

char *num_change(long int number, int foundation, int flags)
{
	char mark = 0;
	static char buffer[50];
	char *con;
	static char *array;
	unsigned long n = number;

	if (!(flags & UNSIGNED_CHANGE) && number < 0)
	{
		n = -number;
		mark = '-';

	}
	array = flags & LOWCASE_CHANGE ? "0123456789abcdef" : "0123456789ABCDEF";
	con = &buffer[49];
	*con = '\0';

	do	{
		*--con = array[n % foundation];
		n /= foundation;
	} while (n != 0);

	if (mark)
		*--con = mark;
	return (con);
}

/**
 * com_del - substitutes 1st instance of '#' -> '\0'
 * @cbuff: the str address that will be mod
 * Return: Always 0;
 */

void com_del(char *cbuff)
{
	int s;

	for (s = 0; cbuff[s] != '\0'; s++)
		if (cbuff[s] == '#' && (!s || cbuff[s - 1] == ' '))
		{
			cbuff[s] = '\0';
			break;
		}
}
