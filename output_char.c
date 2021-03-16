#include "ft_printf.h"
#include <stdio.h>

int ft_output_char(t_format format, va_list ap)
{
	char input;
	input = (char)va_arg(ap, int);
	if (!format.flag_minus && format.flag_zero && format.field > 2)
		output_zeros(format.field - 1);
	else if (!format.flag_minus && format.field > 2)
		output_spaces(format.field - 1);
	ft_putchar(input);
	if (format.flag_minus && format.field > 2)
		output_spaces(format.field - 1);
	return (format.field > 1 ? format.field : 1);
}
