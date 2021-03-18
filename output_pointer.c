#include "ft_printf.h"
#include <stdio.h>

int output_pointer(t_format format, va_list ap)
{
    unsigned long long input_num;
    int digit;
	unsigned long long decimal;
	char *hex_str;

    input_num = (unsigned long long)va_arg(ap, unsigned long long);
    digit = 0;
	decimal = input_num;
	while (decimal > 0)
	{
		decimal /= 16;
		digit++;
	}
	print_pointer_hex(format, input_num, digit + 2);
	return 1;
}
void print_pointer_hex(t_format format, unsigned long long decimal, int digit)
{
	char *hex_num;
	int tmp;
	char hex[10000];
	int i;
	int length;

	hex_num = "0123456789abcdef";
	length = 0;

	if (format.field >= digit && !format.flag_minus && format.precision == -1)
	{
		length += format.field - digit;
		output_spaces(format.field - digit);
	}
	ft_putstr("0x");
	length += 2;

	if (format.precision != -1)
	{
		length += format.precision - (digit - 2);
		output_zeros(format.precision - (digit - 2));
	}

	i = 0;
	while (decimal >= 0)
	{
		tmp = decimal % 16;
		decimal /= 16;
		hex[i++] = hex_num[tmp];
		if (decimal == 0)
			break;
	}
	length += i;

	while (i-- > -1)
		ft_putchar(hex[i]);
	if (format.flag_minus)
		output_spaces(format.field - length);
}
