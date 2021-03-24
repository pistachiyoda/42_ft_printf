/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:59:13 by fmai              #+#    #+#             */
/*   Updated: 2021/03/24 23:34:02 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		calc_u_decimal_digit(unsigned int decimal)
{
	int digit;

	if (decimal == 0)
		return (1);
	digit = 0;
	while (decimal > 0)
	{
		decimal /= 10;
		digit++;
	}
	return (digit);
}

int		proc_u_integer_total_digit(t_format format, unsigned int input_num)
{
	int decimal_digit;

	decimal_digit = calc_u_decimal_digit(input_num);
	return (max(max(
		decimal_digit, format.field),
		format.precision));
}

int		proc_u_integer_zero_digit(t_format format, unsigned int input_num)
{
	int decimal_digit;
	int total_digit;

	decimal_digit = calc_u_decimal_digit(input_num);
	total_digit = proc_u_integer_total_digit(format, input_num);
	if (format.flag_zero && format.precision == -1)
	{
		return (total_digit - decimal_digit);
	}
	else if (format.precision > decimal_digit)
	{
		return (format.precision - decimal_digit);
	}
	return (0);
}

int		output_u_integer(t_format format, va_list ap)
{
	unsigned int	input_num;
	int				total_digit;
	int				decimal_digit;
	int				zero_digit;

	input_num = va_arg(ap, unsigned int);
	if ((format.precision == 0 || format.dot_only) && input_num == 0)
		return (proc_empty(format));
	decimal_digit = calc_u_decimal_digit(input_num);
	total_digit = proc_u_integer_total_digit(format, input_num);
	zero_digit = proc_u_integer_zero_digit(format, input_num);
	if (!format.flag_minus && (!format.flag_zero || format.precision != -1))
		output_spaces(total_digit - decimal_digit - zero_digit);
	output_zeros(zero_digit);
	ft_putunbr(input_num);
	if (format.flag_minus)
		output_spaces(total_digit - decimal_digit - zero_digit);
	return (total_digit);
}
