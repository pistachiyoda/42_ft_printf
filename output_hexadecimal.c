/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:22:18 by fmai              #+#    #+#             */
/*   Updated: 2021/03/20 23:35:20 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	output_hexadecimal(t_format format, va_list ap)
{
	unsigned int	input_num;
	char			*hex_num;
	int				hex_digit;
	int				decimal;

	input_num = (unsigned int)va_arg(ap, unsigned int);
	hex_num = format.type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	hex_digit = 0;
	decimal = input_num;
	while (decimal > 0)
	{
		decimal /= 16;
		hex_digit++;
	}
	if (input_num == 0)
		hex_digit += 1;
	return (print_hex(format, input_num, hex_digit, hex_num));
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
	if (format.flag_zero && format.precision == -1)
		return (total_digit - hex_digit);
	else
	{
		if (format.precision > hex_digit)
			return (format.precision - hex_digit);
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

int	print_hex(
	t_format format, unsigned int decimal, int hd, char *hex_num
)
{
	int		tmp;
	char	hex[10000];
	int		i;
	int		td;

	if ((format.precision == 0 || format.dot_only) && decimal == 0)
		return (proc_empty(format));
	td = proc_total_digit(format, hd);
	if (!format.flag_minus && (!format.flag_zero || format.precision != -1))
		output_spaces(td - hd - proc_zero_digit(format, td, hd));
	output_zeros(proc_zero_digit(format, td, hd));
	i = 0;
	while (decimal >= 0)
	{
		tmp = decimal % 16;
		decimal /= 16;
		hex[i++] = hex_num[tmp];
		if (decimal == 0)
			break ;
	}
	while (i-- > 0)
		ft_putchar(hex[i]);
	if (format.flag_minus)
		output_spaces(td - hd - proc_zero_digit(format, td, hd));
	return (td);
}
