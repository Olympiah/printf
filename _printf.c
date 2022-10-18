#include "main.h"

void print_buff(char buffer[], *buff_ind);

/**
 * _printf - is the printf func.
 * @format: string containing the characters
 * and specifiers
 * Return: the characters to be printed.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_c = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list ap;
	char buffer[BUFFER_SIZE];

	/* checking if there are no number of args */
	if (format == NULL)
	{
		return (-1);
	}

	va_start(ap, format);
	/* note; format are the last known arguments */

	/* making sure we do not include the null parameter */
	for (i = 0; format && format[i] != '\0')
	{
		/* if the char at ith position is not a specifier */
		/* (are introduced with %) */
		if (format[i] != '%')
		{
			/* copying the char/arg to the buffer memory */
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
			{
				/* PRINTING CONTENTS IN BUFFER */
				print_buf(buffer, &buff_ind);
			}
			printed_c++;
		}
		else
		{
			print_buf(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer, flags, width, precision, size);
			if (printed == -1)
			{

				return (-1);
			}
			printed_c += printed;
		}
	}
	print_buf(buffer, &buff_ind);

	va_end(ap);

	return (printed_c);
}

/**
 * print_buf - function that prints contents
 * in memory buffer.
 * @buffer: array of chars.
 * @buff_ind: the index to place next char.
 * Return: void
 */

void print_buf(char buffer[], int *buff_ind)
{

	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	buff_ind = 0;
}


