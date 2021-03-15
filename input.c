#include "ft_printf.h"

// flagの取得
void proc_flags(char **fmt, t_format *format)
{
	while(**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '0')
			format->flag_zero = 1;
		if (**fmt == '-')
			format->flag_minus = 1;
        (*fmt)++;
	}
}

void proc_field(char **fmt, t_format *format, va_list ap)
{
	if (ft_isdigit(**fmt))
		format->field = ft_atoi(*fmt);
	while(ft_isdigit(**fmt))
        (*fmt)++;
	if (**fmt == '*')
	{
		format->field = va_arg(ap, int);
		(*fmt)++;
	}
}

void proc_precision(char **fmt, t_format *format, va_list ap)
{
    if (**fmt == '.')
	{
		(*fmt)++;
		if (ft_isdigit(**fmt))
			format->precision = ft_atoi(*fmt);
		while(ft_isdigit(**fmt))
			(*fmt)++;
		if (**fmt == '*')
		{
			format->precision= va_arg(ap, int);
			(*fmt)++;
		}
	}
}