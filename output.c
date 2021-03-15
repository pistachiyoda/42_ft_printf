#include "ft_printf.h"

int	ft_output(t_format format, va_list ap)
{
	int output_count;
	char *input_str;
	int	input_num;

	output_count = 0;

	if (format.type == 's')
	{
		input_str = (char *)va_arg(ap, char *);
		ft_putstr(input_str);
	}
	else if (format.type == 'd' || format.type == 'i' || format.type == 'u')
	{
		input_num = (int)va_arg(ap, int);
		// todo putnbrのunsigned int対応
		ft_putnbr(input_num);
	}
	else if (format.type == 'c')
	{
		return ft_output_char(format, ap);
	}
	else if (format.type == 'p')
	{}
	else if (format.type == 'x')
	{}
	else if (format.type == 'X')
	{}
	else if (format.type == '%')
	{
		ft_putchar('%');
		return 1;
	}
	return 0;
}

int ft_output_char(t_format format, va_list ap)
{
	char input;

	input = (char)va_arg(ap, int);
	if (!format.flag_minus && format.field > 2)
		output_spaces(format.field - 1);
	ft_putchar(input);
	if (format.flag_minus && format.field > 2)
		output_spaces(format.field - 1);
	return format.field > 1 ? format.field : 1;
}

int output_spaces(int num)
{
	while (num --)
		ft_putchar(' ');
	return num;
}