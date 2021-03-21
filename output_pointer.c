#include "ft_printf.h"

int output_pointer(t_format format, va_list ap)
{
    unsigned long long input_num;
	char *hex_num;
    int hex_digit;
	unsigned long long decimal;

    input_num = (unsigned long long)va_arg(ap, unsigned long long);
	hex_num = "0123456789abcdef";

    hex_digit = 0;
	decimal = input_num;
	while (decimal > 0)
	{
		decimal /= 16;
		hex_digit++;
	}
	if (input_num == 0)
		hex_digit += 1;
	return (print_pointer_hex(format, input_num, hex_digit + 2, hex_num));
}

int print_pointer_hex(t_format format, unsigned long long decimal, int hd, char *hex_num)
{
	int tmp;
	char hex[10000];
	int i;
	int td;

	if ((format.precision == 0 || format.dot_only) && decimal == 0)
	return (proc_empty(format));
	td = proc_total_digit(format, hd);
	if (format.field >= hd && !format.flag_minus && format.precision == -1)
		output_spaces(td - hd);
	ft_putstr("0x");
	if (format.precision != -1)
		output_zeros(proc_zero_digit(format, td, hd));
	i = 0;
	while (decimal >= 0)
	{
		tmp = decimal % 16;
		decimal /= 16;
		hex[i++] = hex_num[tmp];
		if (decimal == 0)
			break;
	}

	while (i-- > 0)
		ft_putchar(hex[i]);
	if (format.flag_minus)
		output_spaces(td - proc_zero_digit(format, td, hd) - hd);
	return (td);
}
