/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:22:18 by fmai              #+#    #+#             */
/*   Updated: 2021/03/21 17:27:34 by fmai             ###   ########.fr       */
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
	hex_digit = calc_hex_digit(decimal, input_num);
	return (print_hex(format, input_num, hex_digit, hex_num));
}

int	print_hex(
	t_format format, unsigned int decimal, int hd, char *hex_num
)
{
	char	hex[10000];
	int		i;
	int		td;

	if ((format.precision == 0 || format.dot_only) && decimal == 0)
		return (proc_empty(format));
	td = proc_total_digit(format, hd);
	if (!format.flag_minus && (!format.flag_zero || format.precision != -1))
		output_spaces(td - hd - proc_zero_digit(format, td, hd));
	output_zeros(proc_zero_digit(format, td, hd));
	i = set_hex_str(decimal, hex_num, hex);
	while (i-- > 0)
		ft_putchar(hex[i]);
	if (format.flag_minus)
		output_spaces(td - hd - proc_zero_digit(format, td, hd));
	return (td);
}
