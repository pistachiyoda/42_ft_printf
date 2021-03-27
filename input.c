/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:46:48 by fmai              #+#    #+#             */
/*   Updated: 2021/03/27 10:33:52 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_flags(char **fmt, t_format *format)
{
	while (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '0')
			format->flag_zero = 1;
		if (**fmt == '-')
			format->flag_minus = 1;
		(*fmt)++;
	}
	if (format->flag_minus && format->flag_zero)
		format->flag_zero = 0;
}

void	proc_field(char **fmt, t_format *format, va_list ap)
{
	if (ft_isdigit(**fmt))
		format->field = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '*')
	{
		format->field = va_arg(ap, int);
		if (format->field < 0)
		{
			format->field *= -1;
			format->flag_minus = 1;
		}
		(*fmt)++;
	}
	if (format->flag_minus && format->flag_zero)
		format->flag_zero = 0;
}

void	proc_precision(char **fmt, t_format *format, va_list ap)
{
	if (**fmt != '.')
		return ;
	(*fmt)++;
	if (ft_isdigit(**fmt))
	{
		format->precision = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (**fmt == '*')
	{
		format->precision = va_arg(ap, int);
		(*fmt)++;
	}
	else
		format->dot_only = 1;
}
