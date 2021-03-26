/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:59:13 by fmai              #+#    #+#             */
/*   Updated: 2021/03/26 20:15:31 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		calc_decimal_digit(int decimal)
{
	int digit;

	if (decimal == -2147483648)
		return (10);
	if (decimal == 0)
		return (1);
	digit = 0;
	if (decimal < 0)
		decimal *= -1;
	while (decimal > 0)
	{
		decimal /= 10;
		digit++;
	}
	return (digit);
}

int		proc_integer_total_digit(t_format format, int input_num)
{
	int decimal_digit;
	int minus_digit;

	decimal_digit = calc_decimal_digit(input_num);
	minus_digit = input_num < 0 ? 1 : 0;
	return (max(max(
		(decimal_digit + minus_digit), format.field),
		(format.precision + minus_digit)));
}

int		proc_integer_zero_digit(t_format format, int input_num)
{
	int decimal_digit;
	int minus_digit;
	int total_digit;

	decimal_digit = calc_decimal_digit(input_num);
	minus_digit = input_num < 0 ? 1 : 0;
	total_digit = proc_integer_total_digit(format, input_num);
	if (format.flag_zero && format.precision == -1)
	{
		return (total_digit - decimal_digit - minus_digit);
	}
	else if (format.precision > decimal_digit)
	{
		return (format.precision - decimal_digit);
	}
	return (0);
}

void	putnbr_without_sign(int input_num)
{
	if (input_num == INT_MIN)
		ft_putstr("2147483648");
	else if (input_num < 0)
		ft_putnbr(input_num * -1);
	else
		ft_putnbr(input_num);
}

int		output_integer(t_format format, va_list ap)
{
	int input_num;
	int total_digit;
	int decimal_digit;
	int zero_digit;
	int minus_digit;

	input_num = va_arg(ap, int);
	if ((format.precision == 0 || format.dot_only) && input_num == 0)
		return (proc_empty(format));
	minus_digit = input_num < 0 ? 1 : 0;
	decimal_digit = calc_decimal_digit(input_num);
	total_digit = proc_integer_total_digit(format, input_num);
	zero_digit = proc_integer_zero_digit(format, input_num);
	if (!format.flag_minus && (!format.flag_zero || format.precision != -1))
		output_spaces(total_digit - decimal_digit - minus_digit - zero_digit);
	if (input_num < 0)
	{
		ft_putchar('-');
	}
	output_zeros(zero_digit);
	putnbr_without_sign(input_num);
	if (format.flag_minus)
		output_spaces(total_digit - decimal_digit - minus_digit - zero_digit);
	return (total_digit);
}
