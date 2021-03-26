/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:09:15 by fmai              #+#    #+#             */
/*   Updated: 2021/03/26 20:09:17 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	proc_total_digit(t_format format, int num_digit)
{
	int total_digit;

	total_digit = format.field >= num_digit ? format.field : num_digit;
	if (format.type == '%')
		return (total_digit);
	if (format.precision > total_digit)
		return (format.precision);
	return (total_digit);
}

int	proc_zero_digit(t_format format, int total_digit, int num_digit)
{
	int zero_digit;

	zero_digit = format.type == 'p' ? 2 : 0;
	if (format.type == '%')
		return (total_digit - 1);
	if (format.flag_zero && format.precision == -1)
	{
		zero_digit += (total_digit - num_digit);
		return (zero_digit);
	}
	else
	{
		if (format.precision > num_digit)
		{
			zero_digit += (format.precision - num_digit);
			return (zero_digit);
		}
	}
	return (0);
}
