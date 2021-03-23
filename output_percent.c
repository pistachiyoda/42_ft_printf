/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:09:38 by fmai              #+#    #+#             */
/*   Updated: 2021/03/23 18:09:51 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_percent(t_format format)
{
	int td;

	td = proc_total_digit(format, 1);
	if (!format.flag_zero && !format.flag_minus)
		output_spaces(td - 1);
	if (format.flag_zero && !format.flag_minus)
		output_zeros((proc_zero_digit(format, td, 1)));
	ft_putchar('%');
	if (format.flag_minus)
		output_spaces(td - 1);
	return (td);
}
