#include "ft_printf.h"
#include <stdio.h>
int output_hexadecimal(t_format format, va_list ap)
{
    unsigned int input_num;
    int digit;
	int decimal;

    input_num = (unsigned int)va_arg(ap, unsigned int);
    digit = 0;
	decimal = input_num;
	while (decimal > 0)
	{
		decimal /= 16;
		digit++;
	}

	print_hex(format, input_num, digit);
	return 1;
}

void print_hex(t_format format, unsigned int decimal, int digit)
{
	char *hex_num;
	int tmp;
	char hex[10000]; // なにかにひっかからないか心配...
	int i;

	hex_num =  format.type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";

	if (!format.flag_minus && format.field && (format.precision <= digit))
		output_spaces(format.field - digit);
	else if (!format.flag_minus && format.field && (format.precision > digit ))
		output_spaces(format.field - format.precision);
	if (format.precision)
		output_zeros(format.precision - digit);

	i = 0;
	while (decimal >= 0)
	{
		tmp = decimal % 16;
		decimal /= 16;
		hex[i++] = hex_num[tmp];
		if (decimal == 0)
			break;
	}

	while (i-- > -1)
		ft_putchar(hex[i]);

	if (format.flag_minus)
		output_spaces(format.field - digit - (format.precision - digit));
}
