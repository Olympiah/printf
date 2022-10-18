#include "main.h"


/**
 * print_char - prints the chars
 * @ap: argument parameters.
 * @buffer: buffer memory.
 * @flags: calculates the flags present.
 * @width: the minimun field width.
 * @precision: precision specifier.
 * @size: size
 * Return: no of chars printed
 */

int print_char(va_list ap, char buffer[],
		int flags, int width, int precision,
	       	int size)
{
	char c = va_arg(ap, int);

	return (handle_write_c(c, buffer, flags, width, precision, size));
}

/**
 * print_string - prints a string
 * @ap: argument params
 * @buffer: buffer memory
 * @flags: calculates active flags
 * @width: minimum field length.
 * @precision: precision.
 * @size: size
 * @Return: no. of chars printed
 */

int print_string(va_list ap, char buffer[],
		int flags, int width, int precision,
	       	int size)
{
	int len = 0, i;
	char *str = va_arg(ap, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(precision);
	UNSUSED(size);
	UNUSED(width);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
		{
			str = "      ";
		}

		while (str[len] != '\0')
		{
			len++;
		}

		if (precision >= 0 && precision < len)
		{
			len = precision;
		}

		if (width > length)
		{
			if (flags & F_MINUS)
			{
			
