#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index of the current character in the format string
 * @list: List of arguments
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = 0;

	if (format[curr_i] == '*')
	{
		int value = va_arg(list, int);
		if (value >= 0)
			precision = value;
	}
	else
	{
		while (is_digit(format[curr_i]))
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
	}

	*i = curr_i - 1;
	return (precision);
}
