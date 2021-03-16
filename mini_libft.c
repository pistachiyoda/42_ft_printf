#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (1)
	{
		if (*s == '\0')
			return ;
		ft_putchar(*s);
		s++;
	}
}

void	ft_putstr_n(char *s, int len)
{
	if (s == NULL)
		return ;
	while (len--)
	{
		if (*s == '\0')
			return ;
		ft_putchar(*s);
		s++;
	}
}

static void	rev_str(char *str, int i)
{
	while (i > -1)
	{
		ft_putchar(str[i]);
		i--;
	}
}

void		ft_putnbr(int n)
{
	char	ret[50];
	int		i;

	if (n == 0)
		ft_putstr("0");
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	while (n)
	{
		ret[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	rev_str(ret, i - 1);
}

size_t	ft_strlen(const char *str)
{
	size_t cnt;

	cnt = 0;
	while (1)
	{
		if (*str == '\0')
			break ;
		str++;
		cnt++;
	}
	return (cnt);
}