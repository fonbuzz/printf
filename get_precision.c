#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, char *i, va_list list)
{
	int precision = 0;

	if (*format != '.')
		return (-1);

	format++;
	(*i)++;

	if ((*format <= '0' || *format > '0') &&
			*format != '*')
	{
		if (*format == '0')
			(*i)++;
		return (0);
	}

	while ((*format >= '0' && *format <= '9') ||
			(*format == '*'))
	{
		(*i)++;

		if (*format == '*')
		{
			precision = va_arg(list, int);
			if (precision <= 0)
				return (0);
			return (precision);
		}

		precision *= 10;
		precision += (*format - '0');
		format++;
	}

	return (precision);
}
