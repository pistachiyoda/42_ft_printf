/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:01:37 by fmai              #+#    #+#             */
/*   Updated: 2021/04/04 15:17:07 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_string(t_format format, va_list ap)
{
	char	*input_str;
	int		str_digit;
	int		total_digit;

	input_str = (char *)va_arg(ap, char *);
	if (!input_str)
		input_str = "(null)";
	str_digit = max_length((int)ft_strlen(input_str), format.precision);
	total_digit = format.field >= str_digit ? format.field : str_digit;
	if (!format.flag_minus && !format.flag_zero && format.field)
		output_spaces(total_digit - str_digit);
	if (!format.flag_minus && format.flag_zero && format.field)
		output_zeros(total_digit - str_digit);
	ft_putstr_n(input_str, str_digit);
	if (format.flag_minus)
		output_spaces(total_digit - str_digit);
	return (total_digit);
}

int	max_length(int input_str_len, int precision)
{
	if (precision == -1)
		return (input_str_len);
	return (input_str_len < precision ? input_str_len : precision);
}
