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

int	proc_total_digit(t_format format, int num_digit)
{
	int total_digit;

	total_digit = format.field >= num_digit ? format.field : num_digit;
	if (format.type == '%')
		return (total_digit);
	if (format.precision > total_digit)
		return (format.precision);
	return (total_digit);
}

int	proc_zero_digit(t_format format, int total_digit, int num_digit)
{
	int zero_digit;

	zero_digit = format.type == 'p' ? 2 : 0;
	if (format.type == '%')
		return (total_digit - 1);
	if (format.flag_zero && format.precision == -1)
	{
		zero_digit += (total_digit - num_digit);
		return (zero_digit);
	}
	else
	{
		if (format.precision > num_digit)
		{
			zero_digit += (format.precision - num_digit);
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

int calc_hex_digit(unsigned long long decimal)
{
	int hex_digit;

	if (decimal == 0)
		return (1);
	hex_digit = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		hex_digit++;
	}
	return (hex_digit);
}

int set_hex_str(unsigned long long decimal, char *hex_num, char *hex)
{
	int		tmp;
	int		i;

	i = 0;
	while (decimal >= 0)
	{
		tmp = decimal % 16;
		decimal /= 16;
		hex[i++] = hex_num[tmp];
		if (decimal == 0)
			break ;
	}
	return (i);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}