#include "ft_printf.h"

int output_spaces(int num)
{
	if (num <= 0)
		return (0);
	while (num--)
		ft_putchar(' ');
	return (num);
}

int output_zeros(int num)
{
	if (num <= 0)
		return (0);
	while (num--)
		ft_putchar('0');
	return (num);
}

int	proc_total_digit(t_format format, int hex_digit)
{
	int total_digit;

	total_digit = format.field >= hex_digit ? format.field : hex_digit;
	if (format.precision > total_digit)
		return (format.precision);
	return (total_digit);
}

int	proc_zero_digit(t_format format, int total_digit, int hex_digit)
{
	int zero_digit;

	zero_digit = format.type == 'p' ? 2 : 0;

	if (format.flag_zero && format.precision == -1)
	{
		zero_digit += (total_digit - hex_digit);
		return (zero_digit);
	}
	else
	{
		if (format.precision > hex_digit)
		{
			zero_digit += (format.precision - hex_digit);
			return (zero_digit);
		}
	}
	return (0);
}

int	proc_empty(t_format format)
{
	if (format.field >= 0)
	{
		output_spaces(format.field);
		return (format.field);
	}
	return (0);
}