#include "ft_printf.h"
#include "stdio.h"

void ft_putchar(char c);
// %がでてくるまで文字列の出力
int ft_printf(const char *fmt, ...)
{
	va_list	ap;
    char *current;

	current = fmt;
	va_start(ap, fmt);
	while(*current)
	{
		if (*current == '%')
		{
			ft_proc_percent(&current);
		}
		else
			ft_putchar(*current);
		current++;
	}
	return 1;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

t_format init_format()
{
	t_format format;

	format.flag_minus = -1;
	format.flag_zero = -1;
	format.field = -1;
	format.precision = -1;
	format.type = '\0';

	return format;
}

void ft_proc_percent(char **fmt)
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
    // fieldの取得完了
    
	// presicionの取得開始
    if (**fmt == '.')
	{
		(*fmt)++;
		if (ft_isdigit(**fmt))
			format.precision = ft_atoi(*fmt);
		while(ft_isdigit(**fmt))
			(*fmt)++;
	}
	// presicionの取得完了

	printf("format.flag_minus = %d\n", format.flag_minus);
	printf("format.field = %d\n", format.field);
	printf("format.precision = %d\n", format.precision);
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (1)
	{
		if (*str == (char)c)
			return (str);
		if (*str == 0)
			return (NULL);
		str++;
	}
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	n;

	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (ft_isdigit(*str))
	{
		if (sign == 1 && ((unsigned int)10 * n + (*str - '0')) > 2147483647)
			return (-1);
		if (sign == -1 && ((unsigned int)10 * n + (*str - '0')) > 2147483648)
			return (0);
		n = 10 * n + (*str - '0');
		str++;
	}
	return (sign * n);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
