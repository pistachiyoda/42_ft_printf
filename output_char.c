/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:17:06 by fmai              #+#    #+#             */
/*   Updated: 2021/03/31 00:35:11 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_char(t_format format, va_list ap)
{
	char input;

	input = (char)va_arg(ap, int);
	if (!format.flag_minus && format.flag_zero && format.field > 1)
		output_zeros(format.field - 1);
	else if (!format.flag_minus && format.field > 1)
		output_spaces(format.field - 1);
	ft_putchar(input);
	if (format.flag_minus && format.field > 1)
		output_spaces(format.field - 1);
	return (format.field > 1 ? format.field : 1);
}
