/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:01:37 by fmai              #+#    #+#             */
/*   Updated: 2021/03/19 23:03:58 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max_length(int input_str_len, int precision)
{
	if (precision < 0)
		return (input_str_len);
	return (input_str_len < precision ? input_str_len : precision);
}

int	output_string(t_format format, va_list ap)
{
	char	*input_str;
	int		str_digit;
	int		total_digit;

	input_str = (char *)va_arg(ap, char *);
	if (format.dot_only)
		input_str = "";
	else if (!input_str)
		input_str = "(null)";
	str_digit = max_length((int)ft_strlen(input_str), format.precision);
	total_digit = format.field >= str_digit ? format.field : str_digit;
	if (!format.flag_minus && format.field)
		output_spaces(total_digit - str_digit);
	ft_putstr_n(input_str, str_digit);
	if (format.flag_minus)
		output_spaces(total_digit - str_digit);
	return (total_digit);
}