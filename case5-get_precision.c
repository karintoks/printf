#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision..
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	count = handle_print(format, &args);
	va_end(args);

	return count;
}

/**
 * handle_print - Handles the printing based on the format string
 * @format: Format string
 * @args: Variable arguments list
 *
 * Return: Number of characters printed
 */
int handle_print(const char *format, va_list *args)
{
	int count = 0;
	int i = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return -1;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return -1;
			if (format[i] == '%')
			{
				count += write_char('%');
				i++;
				continue;
			}
			count += handle_conversion(format[i], args);
		}
		else
		{
			count += write_char(format[i]);
			i++;
		}
	}

	return count;
}

/**
 * handle_conversion - Handles the conversion specifier
 * @specifier: Conversion specifier
 * @args: Variable arguments list
 *
 * Return: Number of characters printed
 */
int handle_conversion(char specifier, va_list *args)
{
	if (specifier == 's')
		return write_string(va_arg(*args, char *));
	else if (specifier == 'c')
		return write_char(va_arg(*args, int));
	else if (specifier == '%')
		return write_char('%');
	else
		return -1;
}

/**
 * write_char - Writes a single character to stdout
 * @c: Character to write
 *
 * Return: Number of characters printed (1 if successful, -1 otherwise)
 */
int write_char(char c)
{
	return write(1, &c, 1);
}

/**
 * write_string - Writes a string to stdout
 * @str: String to write
 *
 * Return: Number of characters printed
 */
int write_string(char *str)
{
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len += write_char(str[len]);

	return len;
}
