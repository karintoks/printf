#include "main.h"

/**
 * print_char - Prints character
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 * This code is written by DONJOR KARINA and OLOKUNTOYE TEMITOLA
 */

int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
