/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:53:05 by fmai              #+#    #+#             */
/*   Updated: 2021/04/08 21:10:34 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *fmt, ...)
{
	int		output_count;
	va_list	ap;
	char	*current;

	output_count = 0;
	current = (char *)fmt;
	va_start(ap, fmt);
	while (*current)
	{
		if (*current == '%')
			output_count += ft_proc_percent(&current, ap);
		else
		{
			ft_putchar(*current);
			output_count++;
		}
		current++;
	}
	return (output_count);
}

int			ft_proc_percent(char **fmt, va_list ap)
{
	t_format	format;

	format = init_format();
	(*fmt)++;
	proc_flags(fmt, &format);
	proc_field(fmt, &format, ap);
	while (!ft_strchr("cspdiuxX%", **fmt))
	{
		if (**fmt == '.')
		{
			(*fmt)++;
			format.precision = 0;
			proc_precision(fmt, &format, ap);
		}
		else
		{
			(*fmt)--;
			return (0);
		}
	}
	format.type = ft_strchr("cspdiuxX%", **fmt) ? **fmt : '\0';
	return (ft_output(format, ap));
}

t_format	init_format(void)
{
	t_format format;

	format.flag_minus = 0;
	format.flag_zero = 0;
	format.field = -1;
	format.precision = -1;
	format.type = '\0';
	return (format);
}

int			ft_output(t_format format, va_list ap)
{
	if (format.type == 's')
		return (output_string(format, ap));
	else if (format.type == 'd' || format.type == 'i')
		return (output_integer(format, ap));
	else if (format.type == 'u')
		return (output_u_integer(format, ap));
	else if (format.type == 'c')
		return (output_char(format, ap));
	else if (format.type == 'p')
		return (output_pointer(format, ap));
	else if (format.type == 'x' || format.type == 'X')
		return (output_hexadecimal(format, ap));
	else if (format.type == '%')
		return (output_percent(format));
	return (0);
}
