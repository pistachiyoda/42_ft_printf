#include "ft_printf.h"

int	output_string(t_format format, va_list ap)
{
	char *input_str;
	int strlen;

	input_str = (char *)va_arg(ap, char *);
	strlen = ft_strlen(input_str);

	if (!format.flag_minus && !format.flag_zero && format.field)
		output_spaces(format.field - strlen);
	if (format.flag_zero && format.field)
		output_zeros(format.field - strlen);
	ft_putstr_n(input_str, format.precision);
	if (format.flag_minus)
		output_spaces(format.field - strlen);
	return 1;
}