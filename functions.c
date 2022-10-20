#include "main.h"


/**
 * print_c - prints the chars
 * @ap: argument parameters.
 * @buffer: buffer memory.
 * @flags: calculates the flags present.
 * @width: the minimun field width.
 * @precision: precision specifier.
 * @size: size
 * Return: no of chars printed
 */

int print_c(va_list ap, char buffer[],
		int flags, int width, int precision, int size)
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
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(ap, char *);

	UNUSED(buffer);
	UNUSED(flags);
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
	}
	while (str[len] != '\0')
	{
		len++;
	}
	if (precision >= 0 && precision < len)
	{
		len = precision;
	}
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
			{
				write(1, " ", 1);
			}
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/**
 * print_percent - prints a % sign
 * @ap: argument parameters.
 * @flags: calculates active flags
 * @width: minimum field width.
 * @precision: precision
 * @size: size.
 * @buffer: buffer memory.
 * Return: no. of chars printed
 */

int print_percents(va_list ap, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(ap);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * print_binary - print unsigned number(+ve)
 * @ap: argument parameters.
 * @buffer: buffer memory
 * @flags: calculate active flags.
 * @width: minimum field width
 * @precision: precision
 * @size: size
 * Return: Number of char printed
 */

int print_binary(va_list ap, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(ap, unsigned int);
	m = 2147483648; /* (2 ^ 31) */

	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];

		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);

}

/**
 * print_int - print_int - Print int
 * @ap: argument parameters
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flag
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */

int print_int(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
