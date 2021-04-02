/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:21:12 by fmai              #+#    #+#             */
/*   Updated: 2021/04/03 00:00:19 by fmai             ###   ########.fr       */
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
	if (format.dot_only && decimal == 0)
		format.flag_zero = 0;
	hex_digit = format.dot_only && decimal == 0 ? 0 : calc_hex_digit(decimal);
	return (print_pointer_hex(format, input_num, hex_digit, hex_num));
}

int	proc_p_total_digit(t_format format, int hex_digit)
{
	int total_digit;

	total_digit = max(max(format.field, hex_digit + 2), format.precision + 2);
	return (total_digit);
}

int	proc_p_zero_digit(t_format format, int total_digit, int hex_digit)
{
	if (format.precision > hex_digit)
		return (format.precision - hex_digit);
	else if (format.flag_zero)
		return (total_digit - 2 - hex_digit);
	return (0);
}

int	print_pointer_hex(
	t_format format, unsigned long long decimal, int hd, char *hex_num
)
{
	char	hex[100];
	int		i;
	int		td;
	int		zero_digit;

	if ((format.precision == 0 || format.dot_only) && decimal == 0)
		hd = 0;
	td = proc_p_total_digit(format, hd);
	zero_digit = proc_p_zero_digit(format, td, hd);
	if (!format.flag_minus)
		output_spaces(td - 2 - zero_digit - hd);
	ft_putstr("0x");
	output_zeros(zero_digit);
	i = set_hex_str(decimal, hex_num, hex);
	if (decimal == 0 && !(format.dot_only || format.precision == 0))
		ft_putchar('0');
	else if (decimal != 0)
	{
		while (i-- > 0)
			ft_putchar(hex[i]);
	}
	if (format.flag_minus)
		output_spaces(td - 2 - zero_digit - hd);
	return (td);
}
