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
		{
			output_count += ft_proc_percent(&current, ap);
		}
		else
		{
			ft_putchar(*current);
			output_count++;
		}
		current++;
	} 
	return output_count;
}

t_format init_format()
{
	t_format format;

	format.flag_minus = 0;
	format.flag_zero = 0;
	format.field = -1;
	format.precision = -1;
	format.type = '\0';

	return format;
}

int ft_proc_percent(char **fmt, va_list ap)
{
	t_format format;
	
	format = init_format();
    (*fmt)++;
    // flagの取得開始
	while(**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '0')
			format.flag_zero = 1;
		if (**fmt == '-')
			format.flag_minus = 1;
        (*fmt)++;
	}
    // flagの取得完了

    // fieldの取得開始
	if (ft_isdigit(**fmt))
		format.field = ft_atoi(*fmt);
	while(ft_isdigit(**fmt))
        (*fmt)++;
	if (**fmt == '*')
	{
		format.field = va_arg(ap, int);
		(*fmt)++;
	}
    // fieldの取得完了
    
	// presicionの取得開始
    if (**fmt == '.')
	{
		(*fmt)++;
		if (ft_isdigit(**fmt))
			format.precision = ft_atoi(*fmt);
		while(ft_isdigit(**fmt))
			(*fmt)++;
		if (**fmt == '*')
		{
			format.precision= va_arg(ap, int);
			(*fmt)++;
		}
	}
	// presicionの取得完了

	// typeの取得開始
	format.type = ft_strchr("cspdiuxX%", **fmt) ? **fmt : '\0';
	// typeの取得完了

	return ft_output(format, ap);
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
	{
		return ft_output_char(format, ap);
	}
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

int ft_output_char(t_format format, va_list ap)
{
	char input;

	input = (char)va_arg(ap, int);
	if (!format.flag_minus && format.field > 2)
		output_spaces(format.field - 1);
	ft_putchar(input);
	if (format.flag_minus && format.field > 2)
		output_spaces(format.field - 1);
	return format.field > 1 ? format.field : 1;
}

int output_spaces(int num)
{
	while (num --)
		ft_putchar(' ');
	return num;
}