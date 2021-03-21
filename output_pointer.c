/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:21:12 by fmai              #+#    #+#             */
/*   Updated: 2021/03/21 16:44:53 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_pointer(t_format format, va_list ap)
{
	unsigned long long	input_num;
	char				*hex_num;
	int					hex_digit;
	unsigned long long	decimal;

	input_num = (unsigned long long)va_arg(ap, unsigned long long);
	hex_num = "0123456789abcdef";
	decimal = input_num;
	hex_digit = calc_hex_digit(decimal, input_num);
	return (print_pointer_hex(format, input_num, hex_digit + 2, hex_num));
}

int	print_pointer_hex(
	t_format format, unsigned long long decimal, int hd, char *hex_num
)
{
	char	hex[100];
	int		i;
	int		td;

	if ((format.precision == 0 || format.dot_only) && decimal == 0)
		return (proc_empty(format));
	td = proc_total_digit(format, hd);
	if (format.field >= hd && !format.flag_minus && format.precision == -1)
		output_spaces(td - hd);
	ft_putstr("0x");
	if (format.precision != -1)
		output_zeros(proc_zero_digit(format, td, hd));
	i = set_hex_str(decimal, hex_num, hex);
	while (i-- > 0)
		ft_putchar(hex[i]);
	if (format.flag_minus)
		output_spaces(td - proc_zero_digit(format, td, hd) - hd);
	return (td);
}
