#include "ft_printf.h"
#include "stdio.h"

int ft_printf(const char *fmt, ...)
{
	int output_count;
	va_list	ap;
    char *current;

	output_count = 0;
	current = (char *)fmt;
	va_start(ap, fmt);
	while(*current)
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

t_format init_format()
{
	t_format format;

	format.flag_minus = 0;
	format.flag_zero = 0;
	format.field = -1;
	format.precision = -1;
	format.type = '\0';

	return (format);
}

int ft_proc_percent(char **fmt, va_list ap)
{
	t_format format;
	
	format = init_format();
    (*fmt)++;
	proc_flags(fmt, &format);
	proc_field(fmt, &format, ap);
	proc_precision(fmt, &format, ap);
	format.type = ft_strchr("cspdiuxX%", **fmt) ? **fmt : '\0';
	return (ft_output(format, ap));
}

int	ft_output(t_format format, va_list ap)
{
	int output_count;
	char *input_str;
	int	input_num;

	output_count = 0;

	if (format.type == 's')
	{
		input_str = (char *)va_arg(ap, char *);
		ft_putstr(input_str);
	}
	else if (format.type == 'd' || format.type == 'i' || format.type == 'u')
	{
		input_num = (int)va_arg(ap, int);
		// todo putnbrのunsigned int対応
		ft_putnbr(input_num);
	}
	else if (format.type == 'c')
		return ft_output_char(format, ap);
	else if (format.type == 'p')
	{}
	else if (format.type == 'x')
	{}
	else if (format.type == 'X')
	{}
	else if (format.type == '%')
	{
		ft_putchar('%');
		return 1;
	}
	return 0;
}